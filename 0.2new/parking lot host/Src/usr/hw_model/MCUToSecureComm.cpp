/*
 * MCUToSecureComm.cpp
 *
 *  Created on: 2016-3-22
 *      Author: lijn
 */
#include <stdio.h>
#include <string.h>

#include "MCUToSecureComm.h"
#include "systick.h"

MCUToSecureComm::MCUToSecureComm() {
	// TODO Auto-generated constructor stub

	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_RESRS_FRAME,14));
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_RESCER_FRAME,7));
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_SEC2CA_FRAME,1024));
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_RESACTIVE_FRAME,7));
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_SETACK_FRAME,7)); //配置帧长度可变，暂定为工作模式配置帧的返回长度
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_TAGDATA_FRAME,110));//因个性化读要求，改为读110个字节
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_UPDATEACK_FRAME,10));//升级应答可能不只10个字节，这里暂延用以前程序中的设定
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_WRITEBANKACK_FRAME,10));// 写分区响应帧。长度可能不止10.暂定为10
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_READBANKACK_FRAME,110));//
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_SECVERSIONACK_FRAME,20));//安全模块软硬件版本请求返回帧长度20字节
	m_FrameTypeToLen.insert(pair<int,int>(M2SEC_CERACK_FRAME,7));
	m_FrameTypeToLen.insert(pair<int,int>(RF2M_TAGDATA_FRAME,32));
    m_FrameTypeToLen.insert(pair<int,int>(M2SEC_FILTERACK_FRAME,7)); //安全模块过滤配置响应帧,为配置响应帧的一种。和工作模式配置返回长度一至。
    m_FrameTypeToLen.insert(pair<int,int>(M2SEC_SETTESTACK_FRAME,7)); //安全模块设置测试模式响应帧

	
	    //m_FrameTypeToLen.insert(pair<int,int>(M2SEC_SPECIALWRITEACK_FRAME,24)); //专用写分区帧应答长度，应为13字节，为保险，设为24字节
    m_FrameTypeToLen.insert(pair<int,int>(M2SEC_SPECIALWRITEACK_FRAME,1024));
	    //序列号帧长度
    m_FrameTypeToLen.insert(pair<int,int>(M2SEC_SECSERIALACK_FRAME,20));
	this->initSPIDevice(SPI2_Device);
}

MCUToSecureComm::~MCUToSecureComm() {
	// TODO Auto-generated destructor stub
}

int MCUToSecureComm::getFrameContenLen(STRUCT_M2SEC_FRAME *pframe){
	uint16_t datalen = 0;
	datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
	return datalen-1;
}

int MCUToSecureComm::caluFrameLen(STRUCT_M2SEC_FRAME *pframe){
	uint16_t datalen = 0;
	datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
	return datalen+5;
}

/*
 * 由输入的帧计算该帧的校验码
 * 产生对帧类型、版本号(两者为一个字节)、帧长度、帧内容进行按字节位异或的校验码
 */
uint8_t MCUToSecureComm::caluBCCCheck(STRUCT_M2SEC_FRAME *pframe){

	uint16_t datalen = 0;
	datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
	//printf("caluBCCCheck:datalen=%d\n",datalen);
	uint8_t checkbuf[1024+3];
	checkbuf[0] = pframe->Type;
	checkbuf[1] = pframe->DataLen[0];
	checkbuf[2] = pframe->DataLen[1];
	checkbuf[3] = pframe->OperId; //操作码的长度也是算在datalen内的
	if(datalen>1){
		memcpy(checkbuf+4,pframe->DataBuf,datalen-1);
	}
	/*printf("checkbuf is:\n");
	for(int i=0;i<datalen+3;i++){
		printf("%02x,",checkbuf[i]);
	}
	printf("\n");*/
	uint8_t bcccheck = 0;
	for(int i=0;i<datalen+3;i++){
		bcccheck ^= checkbuf[i];
	}
	//printf("caluBCCCheck:bcccheck=%02x\n",bcccheck);
	return bcccheck;
}

void MCUToSecureComm::putFrameToBuf(STRUCT_M2SEC_FRAME *pframe,uint8_t *buf){
	uint16_t datalen = 0;
	datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
	int pos = 0;
	memcpy(buf,(uint8_t*)pframe,5);
	pos = 5;
	if(datalen-1>0){
		memcpy(buf+5,pframe->DataBuf,datalen-1);//注意，这里要去掉操作码占的一个字节
		pos += datalen-1;
	}
	buf[pos] = pframe->BCCCheck;
}

/*
 * 注意，这里的frame是new出来的，必须记得删除掉
 */
STRUCT_M2SEC_FRAME * MCUToSecureComm::getFrameFromBuf(uint8_t *buf,int buflen){
	/*printf("getFrameFromBuf:buflen=%d\n",buflen);

	printf("getFrameFromBuf:buf is:");
	for(int i=0;i<buflen;i++){
		printf("0x%02x,",buf[i]);
	}
	printf("\n");*/

	if(buflen<6){
//		printf("getFrameFromBuf:buflen<6,return null!\n");
//		printf("getFrameFromBuf:buf is:");
//		for(int i=0;i<buflen;i++){
//			printf("0x%02x,",buf[i]);
//		}
//		printf("\n");

		return NULL;
	}

	/*printf("getFrameFromBuf:buf is:");
	for(int i=0;i<buflen;i++){
		printf("0x%02x,",buf[i]);
	}
	printf("\n");*/
	//printf("a0\n");
	STRUCT_M2SEC_FRAME *pframe = new STRUCT_M2SEC_FRAME;
	memset((unsigned char *)pframe,0x00,sizeof(STRUCT_M2SEC_FRAME));
	//printf("a1\n");
	pframe->Head = buf[0];
	pframe->Type = buf[1];
	pframe->DataLen[0] = buf[2];
	pframe->DataLen[1] = buf[3];

	//是通信错误帧，则直接返回NULL。
	if(pframe->Head==0xab&&(pframe->Type&0xF0==0x80)){
		printf("Received Sec comm error frame:");
		for(int i=0;i<buflen;i++){
			printf("0x%02x,",buf[i]);
		}
		printf("\n");
		
		delete pframe;
		return NULL;
	}

	uint16_t datalen = 0;
	datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
	//printf("GetFrameFromBuf:datalen=%d\n",datalen);
	if(datalen+5>buflen||datalen<=0){
//		printf("GetFrameFromBuf:datalen=%d\n",datalen);
//		printf("getFrameFromBuf:datalen+5>buflen! return NULL!\n");
//        printf("getFrameFromBuf:buf is:");
//		for(int i=0;i<buflen;i++){
//			printf("0x%02x,",buf[i]);
//		}
//        printf("\n");

		delete pframe;
		return NULL;
	}
	//printf("a2\n");
	pframe->OperId = buf[4];

	if(datalen>1){
		//printf("e0\n");
		uint8_t *databuf = new uint8_t[datalen-1];
		memcpy(databuf,buf+5,datalen-1);
		pframe->DataBuf = databuf;
		pframe->BCCCheck = buf[ 5 + datalen-1];
	}else{
		//printf("e1\n");
		pframe->DataBuf = NULL;
		pframe->BCCCheck = buf[5] ;
	}
	//printf("a3\n");
	//printf("pframe->BCCCheck is%02x\n",pframe->BCCCheck);
	//printf("Bcc is %02x\n",this->caluBCCCheck(pframe));
	if(pframe->BCCCheck==this->caluBCCCheck(pframe)){
		return pframe;
	}else{
		printf("M2SEC FRAME BCC check fail!\n");
		this->removeFrame(pframe);
		return NULL;
	}
}

/*
 * 此函数只能用来建立要发给安全模块的帧。安全模块返回的帧可用getFrameFromSecure来解析
 * 注意，这里建立的帧对象一定要手动删除
 * 这里传入的contentlen只是数据内容长度，不包括标识符长度。无数据内容时，应填为0
 */
STRUCT_M2SEC_FRAME * MCUToSecureComm::creatFrame(int frametype,uint8_t *contentbuf,int contentlen){

	STRUCT_M2SEC_FRAME *pframe = new STRUCT_M2SEC_FRAME;
	int datalen = 0;
	bool hasoperid = false;
	switch(frametype){
	case M2SEC_APPLYRS_FRAME:
		pframe->Head = 0xAA;
		pframe->Type = 0x31;
		pframe->OperId = 0x01;
		datalen = contentlen + 1;
		break;
	case M2SEC_CER_FRAME:
		//printf("M2SEC_CER__FRAME\n");
		pframe->Head = 0xAA;
		pframe->Type = 0x31;
		pframe->OperId = 0x02;
		datalen = contentlen + 1;
		break;
	case M2SEC_USERMSG_FRAME:
		pframe->Head = 0xAA;
		pframe->Type = 0x31;
		pframe->OperId = 0x03;
		datalen = contentlen + 1;
		break;
	case M2SEC_LICENSE_FRAME:
		pframe->Head = 0xAA;
		pframe->Type = 0x31;
		pframe->OperId = 0x04;
		datalen = contentlen + 1;
		break;
	case M2SEC_CERCHAIN_FRAME:
		pframe->Head = 0xAA;
		pframe->Type = 0x31;
		pframe->OperId = 0x05;
		datalen = contentlen + 1;
		break;
	case M2SEC_SET_FRAME: //从这个开始，传入的参数改为包括操作码的。长度是包含操作码的长度
		pframe->Head = 0xAA;
		pframe->Type = 0x11;
		pframe->OperId = contentbuf[0];
		datalen = contentlen;
		hasoperid = true;
		break;
	case M2SEC_UPDATE_FRAME:
		pframe->Head = 0xAA;
		pframe->Type = 0x61;
		pframe->OperId = contentbuf[0];
		datalen = contentlen;
		hasoperid = true;
		break;
	case M2SEC_WRITEBANK_FRAME:
		pframe->Head = 0xAA;
		pframe->Type = 0xB1;
		pframe->OperId = contentbuf[0];
		datalen = contentlen;
		hasoperid = true; //这里要注意，其实该帧并无OperID。为统一起见，将传入的第一个字节作为OperID对待
		break;
	case M2SEC_READBANK_FRAME:
		pframe->Head = 0xAA;
		pframe->Type = 0xA1;
		pframe->OperId = contentbuf[0];
		datalen = contentlen;
		hasoperid = true; //这里要注意，其实该帧并无OperID。为统一起见，将传入的第一个字节作为OperID对待
    case M2SEC_FILTER_FRAME:
        pframe->Head = 0xAA;
        pframe->Type = 0x11;
        pframe->OperId = contentbuf[0];
        datalen = contentlen;
        hasoperid = true;
    case M2SEC_SETTEST_FRAME:
        pframe->Head = 0xAA;
        pframe->Type = 0x31;
        pframe->OperId = contentbuf[0];
        datalen = contentlen;
        hasoperid = true;
	    case M2SEC_SPECIALWRITE_FRAME:
        pframe->Head = 0xAA;
        pframe->Type = 0xC1;
        pframe->OperId = contentbuf[0];
        datalen = contentlen;
        hasoperid = true;  //表示传入的参数含用操作符
        break;	
		
	}

	//因为传入的参数分为包含operid和不包含两种，所以要区别处理
	//if(frametype!=M2SEC_SET_FRAME){
	if(hasoperid==false){
		pframe->DataLen[0] = datalen&0x00FF;
		pframe->DataLen[1] = datalen>>8;
		if(contentlen==0){
			pframe->DataBuf = NULL;
		}else{
			//printf("contentlen=%d\n",contentlen);
			pframe->DataBuf = new uint8_t[contentlen];
			memcpy(pframe->DataBuf,contentbuf,contentlen);
		}
	}else{
		pframe->DataLen[0] = datalen&0x00FF;
		pframe->DataLen[1] = datalen>>8;
		if(contentlen==0){
			pframe->DataBuf = NULL;
		}else{
            //配置安全模块工作模式和升级安全模块固件等时，传入的Buf包括了操作标识符，故特殊处理。
			pframe->DataBuf = new uint8_t[contentlen-1];
			memcpy(pframe->DataBuf,contentbuf+1,contentlen-1);
		}

	}

    pframe->BCCCheck = caluBCCCheck(pframe);
	//printf("pframe->BCCCheck=%02x\n",pframe->BCCCheck);
	return pframe;
}

/*
 * 删除帧，同时也会删除帧内的databuf。
 * 在删除帧，一定要调用此函数，否则，会使databuf的内存泄漏
 */
void MCUToSecureComm::removeFrame(STRUCT_M2SEC_FRAME *pframe){
	if(pframe==NULL){
		return;
	}
	if(pframe->DataBuf!=NULL){
		delete [] pframe->DataBuf;
	}
	delete pframe;
	pframe = NULL;
}

STRUCT_M2SEC_FRAME* MCUToSecureComm::copyFrame(STRUCT_M2SEC_FRAME *pframe){
	//printf("B0................\n");
	STRUCT_M2SEC_FRAME *pframecopy = new STRUCT_M2SEC_FRAME();
	//printf("B1................\n");
	(*pframecopy) = (*pframe);
	//printf("B2................\n");
	int datalen =  pframe->DataLen[1]<<8|pframe->DataLen[0];
	if(datalen<1){
		datalen = 1;
	}
	//printf("datalen=%d\n",datalen);
	//printf("B3................\n");
	unsigned char  *buf = new unsigned char[datalen-1];
	//printf("B4................\n");
	memcpy(buf,pframe->DataBuf,datalen-1);
	//printf("B5................\n");
	pframecopy->DataBuf = buf;
	return pframecopy;
}

bool MCUToSecureComm::sendFrameToSecure(STRUCT_M2SEC_FRAME *pframe){

	int framelen = this->caluFrameLen(pframe);
	//printf("framelen=%d\n",framelen);
	uint8_t buf[MAX_M2SECFRAME_LEN];
	this->putFrameToBuf(pframe,buf);

	/*printf("Sended to Sec frame buf is:\n");
	for(int i=0;i<framelen;i++){
		printf("%02x,",buf[i]);
	}
	printf("\n");*/

	if(!writeSPIData(buf,framelen)){
		return false;
	}else{
		return true;
	}
}

STRUCT_M2SEC_FRAME * MCUToSecureComm::getFrameFromSecure(int frametype){

	int framelen = this->m_FrameTypeToLen[frametype];

	uint8_t buf[SPI_MAX_LEN];
	if(this->readSPIData(buf,framelen)){
		STRUCT_M2SEC_FRAME * pframe = getFrameFromBuf(buf,framelen);
        if(pframe==NULL){
            //g_pMainApplication->logProcess.addLog(LOGTYPE_DEVICE_FAULT, SECURE_SPI_FAULT, "Security communication fail!");
        }
		return pframe;
	}else{
        //g_pMainApplication->logProcess.addLog(LOGTYPE_DEVICE_FAULT, SECURE_SPI_FAULT, "Security communication fail!");
        //printf("Security communication fail!\n");
		return NULL;
	}
}

void MCUToSecureComm::resetSecMod()
{
	m_pIOCtrl->resetSecureModule();
}

/**
 * @brief MCUToSecureComm::waitSecReadyForUpdate
 * @return
 * 等待安全模块进入可升级状态。
 * 返回0表示就绪，-1表示超时。
 */
int MCUToSecureComm::waitSecReadyForUpdate(){
    int overtime_count = 0;

    //先等待0出现，即等待进入S2阶段
    while(1){
        if(m_pIOCtrl->readSMIntLv(STATUS_INT_VALUE)==0){
            printf("sec module ready for update!\n");
            return 0;
        }
        overtime_count++;
        if(overtime_count>5000){
            printf("wait sec module ready overtime..........................................\n");
            return -1;
        }
        Delay_ms(1); //1ms休眠
    }
}



/*
 * 读取安全模块status脚状态，直到变为低电平即准备就绪状态，或超时返回
 * 返回0 表示就绪，返回-1表示未就绪但已超时
 */
int MCUToSecureComm::waitSecReadyForWork(){
    //usleep(10000); //先休眠10ms
    printf("strat sec module, waiting............................................\n");
    int overtime_count = 0;

    //先等待0出现，即等待进入S2阶段
    while(1){
        if(m_pIOCtrl->readSMIntLv(STATUS_INT_VALUE)==0){
            break;
        }
        //printf("status is %d\n",m_pIOCtrl->readSMIntLv(STATUS_INT_VALUE));
        overtime_count++;
        if(overtime_count>5000){
            printf("wait sec module ready overtime..........................................\n");
            //g_pMainApplication->logProcess.addLog(LOGTYPE_DEVICE_FAULT, SECURE_START_FAILURE, "Security start fail!");
            return -1;
        }
        Delay_ms(1); //1ms休眠
    }
    //再等待1出现，即等待进入S3阶段
    overtime_count = 0;
	while(1){
        if(m_pIOCtrl->readSMIntLv(STATUS_INT_VALUE)==1){
            break;
        }
        //printf("status is %d\n",m_pIOCtrl->readSMIntLv(STATUS_INT_VALUE));
		overtime_count++;
        if(overtime_count>5000){
            printf("wait sec module ready overtime..........................................\n");
            //g_pMainApplication->logProcess.addLog(LOGTYPE_DEVICE_FAULT, SECURE_START_FAILURE, "Security start fail!");
			return -1;
        }
        Delay_ms(1); //1ms休眠
	}

    //再次等行0,即等待S4状态，即就绪状态
    overtime_count = 0;
    while(1){
        if(m_pIOCtrl->readSMIntLv(STATUS_INT_VALUE)==0){
            //printf("sec module start success....................................................!\n");
            //g_pMainApplication->logProcess.addLog(LOGTYPE_RUN_LOG, SECURE_START_SUCCESS, "Security start success!");
            return 0;
        }
        //printf("status is %d\n",m_pIOCtrl->readSMIntLv(STATUS_INT_VALUE));
        overtime_count++;
        if(overtime_count>5000){
            printf("wait sec module ready overtime..........................................\n");
            //g_pMainApplication->logProcess.addLog(LOGTYPE_DEVICE_FAULT, SECURE_START_FAILURE, "Security start fail!");
            return -1;
        }
        Delay_ms(1); //1ms休眠
    }
}

/**
 * @brief MCUToSecureComm::isSecReadyForComm
 * @return
 * 2017.09.26新加
 */
bool MCUToSecureComm::isSecReadyForComm(){
    if(m_pIOCtrl->readSMIntLv(CTRLOUT_INT_VALUE)==0){
        return true;
    }else{
        return false;
    }
}

/**
 * 等待安全模块数据准备好通信，即ctrlout_value变为0电平或有上降沿中断产生
 * 返回0表示成功等到数据准备好信号，返回非0表示等待超时
 */
int MCUToSecureComm::waitSecReadyForComm(){
	//int ctrlout_value = -1;
	int overtime_count = 0;
	while(1){
		if(m_pIOCtrl->readSMIntLv(CTRLOUT_INT_VALUE)==0){
			//printf("ctrl out is 0\n");
			return 0;
		}
        //printf("waiting ready for sec....\n");
		Delay_ms(1);
		overtime_count++;
        if(overtime_count>200){
            //printf("wait sec module ctrlout ready overtime...\n");
            //g_pMainApplication->logProcess.addLog(LOGTYPE_DEVICE_FAULT, SECURE_SPI_FAULT, "Security communication fail!");
			return -1;
		}
	}
}

/*
 * 因为某些操作需时较长，所以加了这个函数
 * 参数overtime是多少个100us
 */
int MCUToSecureComm::waitSecReadyForComm(int overtime){
	//int ctrlout_value = -1;
	int overtime_count = 0;
	while(1){
		if(m_pIOCtrl->readSMIntLv(CTRLOUT_INT_VALUE)==0){
			//printf("ctrl out is 0\n");
			return 0;
		}
		Delay_ms(1);
		overtime_count++;
		if(overtime_count>overtime){
			//printf("wait sec module ctrlout ready overtime...\n");
            //g_pMainApplication->logProcess.addLog(LOGTYPE_DEVICE_FAULT, SECURE_SPI_FAULT, "Security communication fail!");
			return -1;
		}
	}
}

llrp_u8v_t MCUToSecureComm::getTIDFromTagFrame(STRUCT_M2SEC_FRAME *pframe){
    if(pframe==NULL){
        return llrp_u8v_t(0);
    }

    //错误类型是1，3时，即无TID错误，直接返回
    if(pframe->DataBuf[0]==1||pframe->DataBuf[0]==3){
        return llrp_u8v_t(0);
    }

    llrp_u8v_t tid = llrp_u8v_t(8);
    int datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];

    if(pframe->OperId==1){ //是标签识别数据
        if((datalen-2)<13){//数据长度错误，不处理
            return llrp_u8v_t(0);
        }else{
            memcpy(tid.m_pValue,pframe->DataBuf+1,tid.m_nValue);
            return tid;
        }
    }else if(pframe->OperId==2||pframe->OperId==3){//是读分区信息数据
        if((datalen-2)<13){
            return llrp_u8v_t(0);
        }else{
            memcpy(tid.m_pValue,pframe->DataBuf+1,tid.m_nValue);
            return tid;
        }
    }else{//其它信息，暂不处理
        return llrp_u8v_t(0);
    }
}

/**
 * @brief MCUToSecureComm::getRightDataFromTagFrame
 * @param pframe
 * @return
 * 从帧中取出成功读取的数据内容。
 * （一帧中只会有一个分区的数据内容）
 */
llrp_u16v_t MCUToSecureComm::getRightDataFromTagFrame(STRUCT_M2SEC_FRAME *pframe){
    if(pframe==NULL){
        return llrp_u16v_t(0);
    }
    if(pframe->OperId==1){//如果仅是tid上报
        return llrp_u16v_t(0);
    }

    //以下根据版本号修正数据的起始位置。2016－04－27添加
    int predatalen = 13;
    if(pframe->Type==0x51){
        predatalen = 13;
    }else if(pframe->Type==0x52){
        predatalen = 17;
    }

    //错误类型是1，2，3，4时，因无数据直接返回空数据。(际上，1，3错误时，不应进到这里）
    if(pframe->DataBuf[0]==1||pframe->DataBuf[0]==2||pframe->DataBuf[0]==3||pframe->DataBuf[0]==4){
        llrp_u16v_t data(0);
        return data;
    }

    int datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
    int words = (datalen-2-predatalen)/2;
    llrp_u16v_t data(words);
    memcpy((unsigned char *)data.m_pValue,pframe->DataBuf+1+predatalen,words*2);
    return data;
}

/**
 * @brief MCUToSecureComm::getRightUserFlagFromTagFrame
 * @param pframe，输入的应是读分区上报帧
 * @return
 */
llrp_u8_t MCUToSecureComm::getRightUserFlagFromTagFrame(STRUCT_M2SEC_FRAME *pframe){
    if(pframe==NULL){
        return 0;
    }
    if(pframe->OperId==1){//如果仅是tid上报
        return 0;
    }

    //错误类型是1，2，3，4时，因无数据直接返回空数据。(际上，1，3错误时，不应进到这里）
    if(pframe->DataBuf[0]==1||pframe->DataBuf[0]==2||pframe->DataBuf[0]==3||pframe->DataBuf[0]==4){
        return 0;
    }
    //printf("DataBuf[0]=0x%2x\n",pframe->DataBuf[0]);
    return pframe->DataBuf[9];//有数据，才会返回分区标识
}

llrp_u8v_t MCUToSecureComm::getOrginDataFromTagFrame(STRUCT_M2SEC_FRAME *pframe){
    if(pframe==NULL){
        return llrp_u8v_t(0);
    }

    //以下根据版本号修正数据的起始位置。2016－04－27添加
    int predatalen = 13;
    if(pframe->Type==0x51){
        predatalen = 13;
    }else if(pframe->Type==0x52){
        predatalen = 17;
    }

    //错误类型是1，2，3时，因无数据直接返回空数据。(际上，1，3错误时，不应进到这里）
    if(pframe->DataBuf[0]==1||pframe->DataBuf[0]==2||pframe->DataBuf[0]==3){
        llrp_u8v_t data(0);
        return data;
    }

    //无错误，或错误4时，返回数据（4时，返回的是未通过校验的原始数据）

        int datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
        int bytes = datalen-2-predatalen;
        llrp_u8v_t data(bytes);
        memcpy(data.m_pValue,pframe->DataBuf+1+predatalen,bytes);
//        printf("data is:");
//        for(int i=0;i<data.m_nValue;i++){
//            printf("0x%2x,",data.m_pValue[i]);
//        }
//        printf("\n");
        return data;

}

/*
 * 从安全模块的返回帧中取出标签数据
 */
llrp_u16v_t MCUToSecureComm::getTagDataFromTagFrame(STRUCT_M2SEC_FRAME *pframe,CMemoryBank *pbank){

    if(pframe==NULL||pbank==NULL){
        return llrp_u16v_t(0);
    }

    //以下根据版本号修正数据的起始位置。2016－04－27添加
    int predatalen = 13;
    if(pframe->Type==0x51){
        predatalen = 13;
    }else if(pframe->Type==0x52){
        predatalen = 17;
    }

    //错误类型是1，2，3时，因无数据直接返回空数据。(际上，1，3错误时，不应进到这里）
    if(pframe->DataBuf[0]==1||pframe->DataBuf[0]==2||pframe->DataBuf[0]==3){
        llrp_u16v_t data(0);
        return data;
    }

    //无错误，或错误4时，返回数据（4时，返回的是未通过校验的原始数据）
    if(pbank->getReadType()==0){//按长度读
        //以下根据HbReadSpec指定的起点和偏移量来取出所需返回的数据字
        int point = pbank->getPointer();
        int count = pbank->getCount();
        int datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
        int words = (datalen-2-predatalen)/2;
        llrp_u8_t userid = (pframe->DataBuf[9]&0xF0)>>4; //取得分区号

        if(userid==0||userid==2){ //user0，user2才有上下半区的概念
            if(point>=HALF_USER_POINT){//起点在下半区
                 //printf("point=%d,HALF_USER_POINT=%d\n",point,HALF_USER_POINT);
                point = point - HALF_USER_POINT;

            }else if(point>=START_USER_POINT){//起点在上半区
                point = point - START_USER_POINT;
            }
        }else{
            if(point>=START_USER_POINT){
                point = point - START_USER_POINT;
            }
        }
        //printf("point=%d,count=%d,words=%d\n",point,count,words);
        if(count>words){ //限制最大读取数不能超过实际数
            count = words;
        }
        if(point+count>words+START_USER_POINT){ //限制读取的数据不越界
            count = words+START_USER_POINT - point;
            if(count<0){
                count = 0;
            }
        }
        //printf("Readed data count=%d\n",count);
        llrp_u16v_t data(count);
        memcpy((unsigned char *)data.m_pValue,pframe->DataBuf+(point)*2+1+predatalen,count*2);
        return data;
    }else if(pbank->getReadType()==1){//按分区读,则将读到的所有数据全部上传
        int datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
        int words = (datalen-2-predatalen)/2;
        //printf("words=%d\n",words);
        llrp_u16v_t data(words);
        memcpy((unsigned char *)data.m_pValue,pframe->DataBuf+1+predatalen,words*2);
        return data;
    }
}

/*
 * 从安全模块的返回帧中取出个性化数据
 */
CReadDataInfo * MCUToSecureComm::getCustomFromTagFrame(STRUCT_M2SEC_FRAME *pframe){

    if(pframe==NULL){
        return NULL;
    }

    //以下根据版本号修正数据的起始位置。2016－04－27添加
    int predatalen = 13;
    if(pframe->Type==0x51){
        predatalen = 13;
    }else if(pframe->Type==0x52){
        predatalen = 17;
    }

    //错误类型是1，2，3时，因无数据直接返回空数据。(际上，1，3错误时，不应进到这里）
    if(pframe->DataBuf[0]==1||pframe->DataBuf[0]==2||pframe->DataBuf[0]==3){
        return NULL;
    }

    //无错误，或错误4时，返回数据（4时，返回的是未通过校验的原始数据）
    //无论原Membank设定是什么样的。都解析并返回CReadDataInfo;
    int datalen = (pframe->DataLen[1]<<8|pframe->DataLen[0])-1-predatalen;//这里是实际数据的长度，不含TID等信息
    if(datalen<4||datalen>1024){ //有效数据长度超出范围则返回空
        printf("datalen=%d\n",datalen);
        return NULL;
    }
    //printf("sssssssssssssssssssss\n");
    //this->m_pRfOper->printfSecFrame(pframe);

    llrp_u8_t *pdata = pframe->DataBuf+1+predatalen;
    int pos = 0;

    CReadDataInfo *preaddatainfo = (CReadDataInfo*)HbFrame_Operation::genParam(ReadDataInfo,0,NULL);
    while(true){
        if(pos+4>=datalen){ //剩余的数据不足，退出循环
            break;
        }
        int datatype = pdata[pos+1]<<8|pdata[pos];
        int len = pdata[pos+3]<<8|pdata[pos+2];
        if(len>32){ //长度非法，则跳出
            break;
        }
        //printf("len=%d\n",len);
        //printf("datatype=%x\n",datatype);
        switch(datatype){
        case CID_PARAM:
        {
            CCID *p = (CCID*)HbFrame_Operation::genParam(CID,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            //20160809修改，据无锡所吴工所说，CID字节序应颠倒。
            /*for(int i=0;i<d.m_nValue;i++){
                d.m_pValue[i] = pdata[pos+4+d.m_nValue-1-i];
            }*/
            /////////////////////////////////////////
            p->setCIDData(d);
            preaddatainfo->setCID(p);
        }
            break;
        case FPDH_PARAM:
        {
            CFPDH *p = (CFPDH*)HbFrame_Operation::genParam(FPDH,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setFPDHData(d);
            preaddatainfo->setFPDH(p);
        }
            break;
        case SYXZ_PARAM:
        {
            CSYXZ *p = (CSYXZ*)HbFrame_Operation::genParam(SYXZ,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setSYXZData(d);
            preaddatainfo->setSYXZ(p);
        }
            break;
        case CCRQ_PARAM:
        {
            CCCRQ *p = (CCCRQ*)HbFrame_Operation::genParam(CCRQ,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setCCRQData(d);
            preaddatainfo->setCCRQ(p);
        }
            break;
        case CLLX_PARAM:
        {
            CCLLX *p = (CCLLX*)HbFrame_Operation::genParam(CLLX,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setCLLXData(d);
            preaddatainfo->setCLLX(p);
        }
            break;
        case GL_PARAM:
        {
            CGL *p = (CGL*)HbFrame_Operation::genParam(GL,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setGLData(d);
            preaddatainfo->setGL(p);
        }
            break;
        case PL_PARAM:
        {
            CPL *p = (CPL*)HbFrame_Operation::genParam(PL,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setPLData(d);
            preaddatainfo->setPL(p);
        }
            break;
        case HPZL_PARAM:
        {
            CHPZL *p = (CHPZL*)HbFrame_Operation::genParam(HPZL,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setHPZLData(d);
            preaddatainfo->setHPZL(p);
        }
            break;
        case HPHMXH_PARAM:
        {
            CHPHMXH *p = (CHPHMXH*)HbFrame_Operation::genParam(HPHMXH,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setHPHMXHData(d);
            preaddatainfo->setHPHMXH(p);
        }
            break;
        case JYYXQ_PARAM:
        {
            CJYYXQ *p = (CJYYXQ*)HbFrame_Operation::genParam(JYYXQ,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setJYYXQData(d);
            preaddatainfo->setJYYXQ(p);
        }
            break;
        case QZBFQ_PARAM:
        {
            CQZBFQ *p = (CQZBFQ*)HbFrame_Operation::genParam(QZBFQ,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setQZBFQData(d);
            preaddatainfo->setQZBFQ(p);
        }
            break;
        case ZKZL_PARAM:
        {
            CZKZL *p = (CZKZL*)HbFrame_Operation::genParam(ZKZL,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setZKZLData(d);
            preaddatainfo->setZKZL(p);
        }
            break;
        case CSYS_PARAM:
        {
            CCSYS *p = (CCSYS*)HbFrame_Operation::genParam(CSYS,0,NULL);
            llrp_u8v_t d = llrp_u8v_t(len);
            memcpy(d.m_pValue,pdata+pos+4,d.m_nValue);
            p->setCSYSData(d);
            preaddatainfo->setCSYS(p);
        }
            break;
        default:
            break;
        }
        pos = pos + 4 + len;
        if(pos>=datalen){//超过数据总长则退出循环
            break;
        }
    }
    return preaddatainfo;
}

STRUCT_M2SEC_FRAME* MCUToSecureComm::genSecVersionRequestFrame(){
    int contentlen = 3;
    unsigned char databuf[3] ;
    databuf[0] = 4;
    databuf[1] = 0;
    databuf[2] = 0;
    STRUCT_M2SEC_FRAME *pframe = creatFrame(M2SEC_SET_FRAME,databuf,contentlen);
    return pframe;
}

void MCUToSecureComm::printfSecFrame(STRUCT_M2SEC_FRAME *pframe){
    int framelen = caluFrameLen(pframe);
    uint8_t buf[1024];
    putFrameToBuf(pframe,buf);

    printf("M2Sec Frame is ");
    for(int i=0;i<framelen;i++){
        printf("%02x,",buf[i]);
    }
    printf("\n");
}
