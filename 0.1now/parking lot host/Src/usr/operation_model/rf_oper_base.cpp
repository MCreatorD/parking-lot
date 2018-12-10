#include "rf_oper_base.h"

#include <stdio.h>
#include <math.h>
#include "main_application.h"
#include "XML_Operation.h"
#include "rf_oper_base.h"
#include "general_functions.h"
#include "systick.h"



Rf_Oper_Base::Rf_Oper_Base() {
    // TODO Auto-generated constructor stub

    pCurrentHbWriteSpec = NULL;
	
		AA_ConfigParam = 0xAA00000000000000;
		AB_ConfigParam = 0xAB01000000000000; //0次，表示无限次读取

		AC_ConfigParam = 0xAC00000000000000;
		AD_ConfigParam = 0xAD00015000010003;

		pCurrentHbWriteSpec = NULL;

		this->isRfOperStart = false;
		needSendParam = false;
		m_pCurrentSelectSpec = NULL;
		m_pCurrentAccessSpec = NULL;
		m_pCurrentRfSpec = NULL;
		m_pCurrentAntSpec = NULL;

		m_Filterms = 0;
		/////////////////////////////////////////////////////
		m_CurrentAntIDIndex = 0;
		m_AntChangeDelay = 0;
		m_FreqChangeDelay = 0;
		
		this->initSPIDevice(SIM_SPI0_Device);

}

Rf_Oper_Base::~Rf_Oper_Base() {
    // TODO Auto-generated destructor stub

}

void Rf_Oper_Base::startRfOper(){
//改写
//    if(this->isRfOperStart==true){
//        return;
//    }
    m_pIOCtrl->enableRfModule();
    //this->isRfOperStart = true;

}

void Rf_Oper_Base::stopRfOper(){

    m_pIOCtrl->disableRfModule();
    this->isRfOperStart = false;
    this->needSendParam = true;
}

Struct_TagBank_RWInfo Rf_Oper_Base::getBankinfoFromMemBank(CMemoryBank *pMemoryBank){
	Struct_TagBank_RWInfo bankinfo;

	bankinfo.BankNum = pMemoryBank->getMemoryBankID();
	llrp_u8_t memid = pMemoryBank->getMemoryBankID();
	llrp_u16_t pointer = pMemoryBank->getPointer();
	llrp_u16_t count = pMemoryBank->getCount();

	if(pMemoryBank->getReadType()==0){//按长度读
		//printf("d2\n");
		if(memid==0||memid==2){ //user0，user2才有上下半区的概念
			if(pointer>=HALF_USER_POINT){//起点在下半区
				bankinfo.BankReadFlag = 0; //下半区
			}else{//起点在上半区
				if(pointer+count-1>=HALF_USER_POINT){
					bankinfo.BankReadFlag = 2;//全区
				}else{
					bankinfo.BankReadFlag = 1;//上半区
				}
			}
		}else{
			bankinfo.BankReadFlag = 2; //其它区全部只能是全区
		}
	}else if(pMemoryBank->getReadType()==1){//按分区类型读
		//printf("d3\n");
		bankinfo.BankReadFlag = pMemoryBank->getBankType();
	}

	bankinfo.BankCryptFlag = 0x00;
	bankinfo.BankReadSpeedFlag = 1; //暂定为默认的1(user0,user2只能用高速读)
	bankinfo.BankReadPoint = 0x00;
	bankinfo.BankReadCount = 0x00;

	return bankinfo;
}

CReadMode* Rf_Oper_Base::getDefaultReadMode(){
    CSetDeviceConfig *pdeviceconfig = NULL;
    if(pdeviceconfig!=NULL){
        CSecurityModuleConfiguration *pseccfg = pdeviceconfig->getSecurityModuleConfiguration();
        if(pseccfg!=NULL){
            CGenaralConfigData *pgeneralcfg = pdeviceconfig->getSecurityModuleConfiguration()->getGenaralConfigData();
            if(pgeneralcfg!=NULL){
                //printf("step0...........\n");
                CReadMode *preadmode = pgeneralcfg->getReadMode();
                return preadmode;
            }else{
                //printf("step1...........\n");
                return NULL;
            }
        }else{
            return NULL;
        }
    }else{
        return NULL;
    }
}

/**
 * @brief Rf_Oper_GB::setSelectRfParam
 * @return
 * 配置盘点操作的射频参数。每轮盘点前，根据需要操作
 * 主要是作跳频和切换天线的参数配置
 */
bool Rf_Oper_Base::setSelectRfParam(){
    if(m_AvailableAntIDs.size()==0){
        return false;
    }
    if(m_CurrentAntIDIndex>=m_AvailableAntIDs.size()){
        m_CurrentAntIDIndex = 0;
    }
    //有不只一个天线在工作，就要进行天线的切换工作
    if(m_AvailableAntIDs.size()>0){
        m_AntChangeDelay++;
        if(m_AntChangeDelay>SWITCHANT_DELAY){//切换天线
            m_AntChangeDelay = 0;
            m_CurrentAntIDIndex++;
            if(m_CurrentAntIDIndex>=m_AvailableAntIDs.size()){
               // printf("m_CurrentAntIDIndex=%d\n",m_CurrentAntIDIndex);
                m_CurrentAntIDIndex = 0;
            }
        }
    }

    m_FreqChangeDelay++; //频率切换，即跳频
    if(m_FreqChangeDelay>SWITCHFREQ_DELAY){
        m_FreqChangeDelay = 0;

        STRUCT_ANTCFG_DATA *pstruct_antcfg;
        map<int,STRUCT_ANTCFG_DATA>::iterator it = m_AntIDToAntCFG.find(m_AvailableAntIDs.at(m_CurrentAntIDIndex));

        if(it!=m_AntIDToAntCFG.end()){
            pstruct_antcfg = &(m_AntIDToAntCFG[m_AvailableAntIDs.at(m_CurrentAntIDIndex)]);
            //printf("0:FreqIndexes->m_nvalue=%d,CurrentFreqIndex=%d\n",pstruct_antcfg->FreqIndexes.m_nValue,pstruct_antcfg->CurrentFreqIndex);
            pstruct_antcfg->CurrentFreqIndex++;
            if(pstruct_antcfg->CurrentFreqIndex>=pstruct_antcfg->FreqIndexes.m_nValue){
                //printf("......................................\n");
                pstruct_antcfg->CurrentFreqIndex = 0;
            }
        }else{ //没有找到，不做任何事

        }

    }
}

bool Rf_Oper_Base::sendSelectRfParam(unsigned char work_mode){
    //printf("d0...................................................\n");
    AA_ConfigParam = 0xAA00000000000000;
    AC_ConfigParam = 0xAC00000000000000;

    llrp_u64_t temp = 0;

    llrp_u8_t antennaID;
    llrp_u8_t transmitPowerIndex;
    llrp_u16_t revDataRateIndex;
    llrp_u16_t revDataEcodingIndex;
    llrp_u16_t forDataRateIndex;

    //printf("m_CurrentAntIDIndex=%d\n",m_CurrentAntIDIndex);
    STRUCT_ANTCFG_DATA *pstruct_antcfg ;

    if(m_AntIDToAntCFG.empty()==true){
//        printf("sendSelectRfParam:m_AntIDToAntCFG is empty");
        return false;
    }

    //找出当前天线号所对应的天线配置
    map<int,STRUCT_ANTCFG_DATA>::iterator it = m_AntIDToAntCFG.find(m_AvailableAntIDs.at(m_CurrentAntIDIndex));
    //printf("m_AntIDToAntCFG.size=%d,m_CurrentAntIDIndex=%d,ant id =%d\n",m_AntIDToAntCFG.size(),m_CurrentAntIDIndex,m_AvailableAntIDs.at(m_CurrentAntIDIndex));
    if(it!=m_AntIDToAntCFG.end()){
        //printf("e0\n");

        pstruct_antcfg = &(m_AntIDToAntCFG[m_AvailableAntIDs.at(m_CurrentAntIDIndex)]);
    }else{
       // printf("e1\n");
        //没有找到，则复制第一个天线设置中除天线号外的设置
        STRUCT_ANTCFG_DATA struct_antcfg = m_AntIDToAntCFG.begin()->second;
        struct_antcfg.AntID = m_AvailableAntIDs.at(m_CurrentAntIDIndex);
        struct_antcfg.CurrentFreqIndex = 0; //频率固定
        pstruct_antcfg = &struct_antcfg;
    }

    antennaID = pstruct_antcfg->AntID; //这里的天线从0编号
    //printf("sendSelectRfParam:antennaID = %d\n",antennaID);
    if(antennaID==1){
        antennaID = 2;
    }else if(antennaID==2){
        antennaID = 1;
    }


    temp = antennaID;
    AC_ConfigParam |= temp<<48;
    //printf("b1...................................................\n");
    //printf("FreqIndexes.m_nvalue=%d,CurrentFreqIndex=%d\n",struct_antcfg.FreqIndexes.m_nValue,struct_antcfg.CurrentFreqIndex);
    temp = pstruct_antcfg->FreqIndexes.m_pValue[pstruct_antcfg->CurrentFreqIndex];
    AC_ConfigParam |= temp<<40;

    //printf("b2...................................................\n");

    transmitPowerIndex = pstruct_antcfg->PowerIndex;
    //printf("transmitPowerIndex=%d\n",transmitPowerIndex);
    temp = transmitPowerIndex;
    //printf("Use PowerIndex is %lld\n",temp);
    AC_ConfigParam |= temp<<32;

    //泄漏对消阈值，暂定为0x0000(在这里实际上是不起作用的)
    temp = 0x00;
    AC_ConfigParam |= temp<<24;
    temp = 0x00;
    AC_ConfigParam |= temp<<16;

    //printf("a3...................................................\n");

    //任务模式
    temp = work_mode;
    AC_ConfigParam |= temp<<8;

    //加入除帧头外的6字节异或出的CRC
    temp = this->calcCrc8(AC_ConfigParam);
    AC_ConfigParam |= temp;
//    if(work_mode==SETRFWORK_POWER){
//        printf("sendSelectRfParam:AC_ConfigParam = %llx\n",AC_ConfigParam);
//    }

    //以下是AA配置
    revDataRateIndex = pstruct_antcfg->RevRateIndex;
    revDataEcodingIndex = pstruct_antcfg->RevEncodingIndex;
    forDataRateIndex = pstruct_antcfg->ForRateIndex;

    //printf("Rf_Oper_GB:RevDataRate:%5x\n",(int)revDataRateIndex);
    //printf("Rf_Oper_GB:RevDataEncoding:%5x\n",(int)revDataEcodingIndex);
    //printf("Rf_Oper_GB:ForDataRate:%5x\n",(int)forDataRateIndex);

    //前向速率，0表示6.25us,1表示12.5us
    switch(forDataRateIndex)
    {
    case 0:
        AA_ConfigParam |= 0x0050000000000000ll;
        break;
    case 1:
        AA_ConfigParam |= 0x0028000000000000ll;
        break;
    }

    //反向编码方式，分别对应FM0,M2,M4,M8
    switch(revDataEcodingIndex)
    {
    case 0:
        AA_ConfigParam |= 0x0000000000000000ll;
        break;
    case 1:
        AA_ConfigParam |= 0x0000000100000000ll;
        break;
    case 2:
        AA_ConfigParam |= 0x0000000200000000ll;
        break;
    case 3:
        AA_ConfigParam |= 0x0000000300000000ll;
        break;
    }

    //反向速率，分别对应64，137.14，174.55，320，128，274.29，349.09，640
    revDataRateIndex = 3;
    switch(revDataRateIndex)
    {
    case 0:
        AA_ConfigParam |= 0x0000004000000000ll;
        break;
    case 1:
        AA_ConfigParam |= 0x0000004400000000ll;
        break;
    case 2:
        AA_ConfigParam |= 0x0000004800000000ll;
        break;
    case 3:
        AA_ConfigParam |= 0x0000004C00000000ll;
        break;
    case 4:
        AA_ConfigParam |= 0x0000005000000000ll;
        break;
    case 5:
        AA_ConfigParam |= 0x0000005400000000ll;
        break;
    case 6:
        AA_ConfigParam |= 0x0000005800000000ll;
        break;
    case 7:
        AA_ConfigParam |= 0x0000005C00000000ll;
        break;
    }//end of switch
    this->sendParamToRf(PARAM_AA,0);
    this->sendParamToRf(PARAM_AC,work_mode);
		
		return true;
}



/**
 * @brief Rf_Oper_Base::sendParamToRf
 * @param paramtype
 * @param ac_worktype
 * @return
 * 发送射频参数给射频，ac_worktype用以指定天线工作参数，非AC类参数，可以置为0
 */
//发送到射频前端改写成CAN
bool Rf_Oper_Base::sendParamToRf(int paramtype,int ac_worktype ){
    unsigned long long param = 0;
    switch(paramtype){
    case PARAM_AA:
        if(AA_ConfigParam==m_LastAA){
            return true;
        }
        m_LastAA = AA_ConfigParam;
        param = AA_ConfigParam;
//        printf("sendParamToRf:AA_ConfigParam = %llx\n",param);
        break;
    case PARAM_AB:
        if(AB_ConfigParam==m_LastAB){
            return true;
        }
        m_LastAB = AB_ConfigParam;
        param = AB_ConfigParam;
//        printf("sendParamToRf:AB_ConfigParam = %llx\n",param);
        break;
    case PARAM_AC:
//        if(AC_ConfigParam==m_LastAC){
//            return true;
//        }
//        m_LastAC = AC_ConfigParam;
//        param = AC_ConfigParam;
        switch(ac_worktype){
        case SETRFWORK_ANT:
            if(AC_ConfigParam==m_LastACs[0]){
                return true;
            }
            m_LastACs[0] = AC_ConfigParam;
            param = AC_ConfigParam;
//            printf("sendParamToRf:AC_ConfigParam = %llx\n",param);
            break;
        case SETRFWORK_FREQ:
            if(AC_ConfigParam==m_LastACs[1]){
                return true;
            }
            m_LastACs[1] = AC_ConfigParam;
            param = AC_ConfigParam;
//            printf("sendParamToRf:AC_ConfigParam = %llx\n",param);
            break;
        case SETRFWORK_POWER:
            if(AC_ConfigParam==m_LastACs[2]){
                //printf("power not change ,return!\n");
                return true;
            }
            m_LastACs[2] = AC_ConfigParam;
            param = AC_ConfigParam;
//            printf("SETRFWORK_POWER:AC_ConfigParam = %llx\n",param);
            break;
        case SETRFWORK_CAN:
        case SETRFWORK_POWINC:
        case SETRFWORK_POWDEC:
        case SETRFWORK_FINEINC:
        case SETRFWORK_FINEDEC:
            param = AC_ConfigParam;
            //printf("sendParamToRf:AC_ConfigParam = %llx\n",param);
            break;
        default:
            param = AC_ConfigParam;
            //printf("sendParamToRf:AC_ConfigParam = %llx\n",param);
            break;
        }

        break;
    }

    unsigned char sendbufspi[8] = {0x00};
    int datalen = 8;

    for(int i=0;i<8;i++){
        sendbufspi[i] = *(((unsigned char *)&param)+7-i);
    }
		//----------------------------------------发送带射频单元修改成CAN通信------------------------------------------
		
		
		
    //printf("Rf_Oper_GB::sendParamToRf end!\n");
    if(!this->writeSPIData(sendbufspi,datalen)){
        return false;
    }
		
		
		//----------------------------------------发送带射频单元修改成CAN通信------------------------------------------		
		
		Delay_ms(2); //测试语句
    return true;
}

void Rf_Oper_Base::setTagDataFilter(CReadMode *pReadMode){
    if(pReadMode==NULL){//为空则不过滤
        m_Filterms = 0;
    }else{
        if(pReadMode->getRepeatReadFlag()==0){//不重复读分区，即过滤
            //buf_2[3] = 0;
            llrp_u32_t t = pReadMode->getTimer();
            if(t<1000){//设定时长小于1000ms或大于120000ms，则强制转到范围内最大或最小值
                t = 1000;
            }else if(t>120000){
                t = 120000;
            }
            m_Filterms = t;
        }else{//重复读分区，则不过滤。
            //buf_2[3] = 1; //重复读分区
            m_Filterms = 0;
        }
    }
}

/**
 * @brief Rf_Oper_Base::doTagDataFilter
 * @param pFrame，放入的必须是识读信息上传帧
 * @return，过滤后的数据，如为空，则表示该条数据被过滤掉了。
 */
STRUCT_M2SEC_FRAME* Rf_Oper_Base::doTagDataFilter(STRUCT_M2SEC_FRAME *pFrame){
    if(pFrame==NULL){
        return NULL;
    }
    if(pFrame->Head!=0xAB||(pFrame->Type&0xF0)!=0x50){//不是识读信息上传帧，直接返回空
        return NULL;
    }

     llrp_u8v_t tid;
     llrp_u16v_t tagdata = llrp_u16v_t(0);
     llrp_u8_t userflag = 0; //分区号，实际还含有分区访问标识和天线号
    if(pFrame->OperId==2||pFrame->OperId==3){//是读分区或读个性化数据
        tagdata = MCUToSecureComm::getRightDataFromTagFrame(pFrame);
        if(tagdata.m_nValue==0){ //如无有效数据，则返回空
            return NULL;
        }else{//有有效数据，则取出分区号
            //MCUToSecureComm::printfSecFrame(pFrame);
            userflag = MCUToSecureComm::getRightUserFlagFromTagFrame(pFrame);
        }
        //printf("userflag=0x%2x\n",userflag);
    }else{ //是tid或未知数据，都当作识别处理
        tid =  MCUToSecureComm::getTIDFromTagFrame(pFrame);
        if(tid.m_nValue<=0){ //如无TID，则直接返回空
            return NULL;
        }
    }
    llrp_u64_t current_utcms = General_Functions::getCurrentUTC() ;
    bool findtid = false;
    STRUCT_M2SEC_FRAME *pframe = NULL;
    for(list<STRUCT_FILTER_DATA*>::iterator it=m_FilterDataList.begin();
        it!=m_FilterDataList.end();){
        list<STRUCT_FILTER_DATA*>::iterator tempit = it;
        it++;
        STRUCT_FILTER_DATA *pdata = *tempit;
        //以下还应该对分区号也进行比对，暂时未做。
        //比对列表中的TID
        if(tid.m_nValue!=pdata->TID.m_nValue||memcmp(tid.m_pValue,pdata->TID.m_pValue,tid.m_nValue)!=0){//未比对上
            //比对此条记录是否已超时，超时，则从列表中移除
            if((current_utcms-pdata->StartFilterUTCms)>m_Filterms){
                m_FilterDataList.erase(tempit);
                delete *tempit;
            }
            continue;
        }else if(pFrame->OperId==2||pFrame->OperId==3){//是读分区或读个性化数据
            if(tagdata.m_nValue!=pdata->Data.m_nValue||memcmp((unsigned char *)tagdata.m_pValue,(unsigned char *)pdata->Data.m_pValue,tagdata.m_nValue*2)!=0){//比对上TID，还要继续比对Data
                //比对此条记录是否已超时，超时，则从列表中移除
                if((current_utcms-pdata->StartFilterUTCms)>m_Filterms){
                    m_FilterDataList.erase(tempit);
                    delete *tempit;
                }
                continue;
            }else if(userflag!=pdata->UserFlag){ //两者都比对上还要比对分区信息，如没有比对上
                //比对此条记录是否已超时，超时，则从列表中移除
                if((current_utcms-pdata->StartFilterUTCms)>m_Filterms){
                    m_FilterDataList.erase(tempit);
                    delete *tempit;
                }
                continue;
            }else{//全部比对上。
                findtid = true;
                if((current_utcms-pdata->StartFilterUTCms)>m_Filterms){
                    m_FilterDataList.erase(tempit);
                    delete *tempit;
                    pframe = pFrame;
                    break;
                }else{
                    pframe = NULL;
                }

            }
        }else{ //是识别模式数据
            findtid = true;
            if((current_utcms-pdata->StartFilterUTCms)>m_Filterms){
                m_FilterDataList.erase(tempit);
                delete *tempit;
                pframe = pFrame;
                break;
            }else{
                pframe = NULL;
            }
        }

    }//end of for
    if(findtid==false){//没有查找到，则认为是一条新数据，放入列表
        pframe = pFrame;
        STRUCT_FILTER_DATA *pfilter = new STRUCT_FILTER_DATA;
        pfilter->TID = tid;
        pfilter->UserFlag = userflag;
        pfilter->Data = tagdata;
        pfilter->StartFilterUTCms = current_utcms;
        m_FilterDataList.push_back(pfilter);
    }else{//有查找到，则判断是否为空，不为空，则认为已超过过滤时间，应重新放入列表
        if(pframe!=NULL){
            STRUCT_FILTER_DATA *pfilter = new STRUCT_FILTER_DATA;
            pfilter->TID = tid;
            pfilter->UserFlag = userflag;
            pfilter->Data = tagdata;
            pfilter->StartFilterUTCms = current_utcms;
            m_FilterDataList.push_back(pfilter);
        }
    }
    /*if(pframe!=NULL){
        MCUToSecureComm::printfSecFrame(pframe);
    }*/
    return pframe;
}

bool Rf_Oper_Base::setADParam(CAntennaConfiguration * pAntennaCfg){

	llrp_u8_t antennaID = pAntennaCfg->getAntennaID();

    if(antennaID<=0){
        return false;
    }
    ///////////////////////////////////////////////////////
	//工作天线配置
	antennaID &= 0x7F;
    llrp_u8_t orginantennaID = antennaID; //保留下未颠倒的ID
	//以下把天线号颠倒一下。
    if(antennaID==3){
        antennaID = 2;
    }else if(antennaID==2){
        antennaID = 3;
    }
//    printf("Rf_Oper_GB_setADParam:AntennaID:%x\n",(int)antennaID);

    this->setACParam(antennaID,0,SETRFWORK_ANT);
    this->sendParamToRf(PARAM_AC,SETRFWORK_ANT);
    /////////////////////////////////////////////////////////////
	//以下循环对所选频道进行对消
	bool success = true;
	llrp_u16v_t freqs = pAntennaCfg->getFrequencyIndexes();
	if(freqs.m_nValue<=0){
		return false;
	}
	//printf("freqs.m_nValue=%d\n",freqs.m_nValue);
	for(int i=0;i<freqs.m_nValue;i++){

        this->setACParam(antennaID,freqs.m_pValue[i],SETRFWORK_FREQ);
        this->sendParamToRf(PARAM_AC,SETRFWORK_FREQ);

        Delay_ms(2);
        this->setACParam(antennaID,freqs.m_pValue[i],SETRFWORK_CAN);
        this->sendParamToRf(PARAM_AC,SETRFWORK_CAN);
        //printf("setADParam:AC_ConfigParam=0x%llx\n",AC_ConfigParam);
        if(this->waitFPGANeedComm(3000)==true){
//            printf("wait fpga need comm true!\n ");
            unsigned char receivebufspi[8+2] = {0x00};
            int datalen = 8;

            if(this->readSPIData(receivebufspi,datalen+2))
            {
                for(int i=0;i<8;i++)
                {
                    printf("%02x",receivebufspi[i]);
                }
                printf("\n");
                if(receivebufspi[0] == 0xBA)
                {
                    unsigned char mask = receivebufspi[2];
                    //printf("mask is 0x%02x\n",mask);
                    if((mask&0x01)==0){//无对消结果则认为失败
                        success = false;
                    }else{
                        unsigned char a = receivebufspi[1];
                        if((a&0x01)==0){
                            success = false;
                        }else{
//                            printf("Ant %d, freq %d  Cancellation is success...................................!\n",antennaID,freqs.m_pValue[i]);
                            this->putDoeCancellation(orginantennaID,freqs.m_pValue[i]);
                        }
                    }

                }else{
                    success = false;
                }
            }else{
                success = false;
            }
            //usleep(1000000);
        }else{
//            printf("wait fpga need comm false!\n ");
            success = false;
        }
    }

    ////////////////////////////////////////////////////
    return success;
}

bool Rf_Oper_Base::setAllADParam(CAntennaSpec * pAntennaSpec){
	//受硬件限制，目前，只取第一个RfSpec;
	CRfSpec *prfspec = *pAntennaSpec->beginRfSpec();

	//天线号为1～4。第一个为0，表示是全部天线轮询
	llrp_u8v_t antennaIDs = pAntennaSpec->getAntennaIDs();
	if(antennaIDs.m_nValue==0){
		return false;
	}
	if(antennaIDs.m_pValue[0]==0){ //是全部天线轮询，为方便处理，重新初始化为4个天线
		antennaIDs = llrp_u8v_t(4);
		antennaIDs.m_pValue[0] = 1;
		antennaIDs.m_pValue[1] = 2;
		antennaIDs.m_pValue[2] = 3;
		antennaIDs.m_pValue[3] = 4;

	}
	//遍历天线号组。
	bool allsuccess = true;
	for(int i=0;i<antennaIDs.m_nValue;i++){
		llrp_u8_t antennaID = antennaIDs.m_pValue[i];

		CAntennaConfiguration *ptempcfg = this->findAntennaConfig(prfspec->beginAntennaConfiguration(),prfspec->endAntennaConfiguration(),antennaID);

		if(ptempcfg==NULL){//如果没有相应设置，取默认值。
//            printf("ptempcfg is NULL!\n");
            ptempcfg = this->findAntennaConfig(g_pMainApplication->getParamManager()->getDeviceConfig()->beginAntennaConfiguration(),
                                               g_pMainApplication->getParamManager()->getDeviceConfig()->endAntennaConfiguration(),antennaID);
            if(ptempcfg==NULL){ //在默认配置中未找到，则采用第一个默认配置
//                printf("ptempcfg is not find,use default!\n");
                ptempcfg = *(g_pMainApplication->getParamManager()->getDeviceConfig()->beginAntennaConfiguration());
                if(ptempcfg!=NULL){
                    ptempcfg->setAntennaID(antennaID);
                }
            }
		}



		if(ptempcfg==NULL){
			allsuccess = false;
		}else if(this->setNewADRparam(ptempcfg)==false){
			allsuccess = false;
		}
		//usleep(2000000);

	}//end of for

	return allsuccess;
}

bool Rf_Oper_Base::setNewADRparam(CAntennaConfiguration * pAntennaCfg){
	return false;
}

bool Rf_Oper_Base::sendAEToRf(unsigned char antennaid,unsigned char datt,unsigned char ctrl){ //发送定标帧给FPGA
	AE_ConfigParam  = 0xAE00000000000000ll;
	llrp_u64_t temp = 0;

	switch(antennaid){
	case 1:
		temp = 0x01;
		break;
	case 2:
		temp = 0x04;
		break;
	case 3:
		temp = 0x02;
		break;
	case 4:
		temp = 0x08;
		break;
	}

	AE_ConfigParam |= temp<<48;
	temp = datt;
	AE_ConfigParam |= temp<<40;
	temp = ctrl;
	AE_ConfigParam |= temp<<32;

	printf("AE_ConfigParam=%llx\n",AE_ConfigParam);

	unsigned char sendbufspi[8] = {0x00};
	for(int i=0;i<8;i++){
		sendbufspi[i] = *(((unsigned char *)&AE_ConfigParam)+7-i);
	}

	/*printf("spi send buf is ");
	for(int i=0;i<8;i++){
		printf("%02x,",sendbufspi[i]);
	}
	printf("\n");*/

	if(!this->writeSPIData(sendbufspi,8)){
		return false;
	}

    //startRf_Oper_GB();

	int overtime = 0;
	unsigned char recbuf[8] = {0x00};
	while(1){
		if(!this->readSPIData(recbuf,8)){
			/*overtime++;
			if(overtime>1500){
				printf("RF powr Calibration overtime!\n");
                stopRf_Oper_GB();
				return false;
			}
			usleep(1000);
			continue;*/
			printf("Read Rf spi data fail!\n");
			return false;
		}

		printf("RF ACK is :");
		for(int i=0;i<8;i++){
			printf("%02x,",recbuf[i]);
		}
		printf("\n");

		if(recbuf[0]!=0xBB){
			overtime++;
			if(overtime>15){
				printf("RF powr Calibration overtime!\n");
                //stopRf_Oper_GB();
				return false;
			}
			Delay_ms(100);
			continue;
		}else{
			BB_ConfigAck = 0ll;
			for(int i= 0;i<8;i++){
				llrp_u64_t temp = recbuf[i];
				BB_ConfigAck |= temp<<((7-i)*8);
			}
            //stopRf_Oper_GB();
			printf("RF powr Calibration success!\n");
			return true;
		}
	}
}

/*
 * 判断是否匹配
 */
bool Rf_Oper_Base::isMatchMask(CHbTargetTag *pHbTargetTag,llrp_u8v_t TID,llrp_u16v_t userTagData){
	llrp_u8_t memorytype = pHbTargetTag->getMemoryType();
	llrp_u1_t matchtype = pHbTargetTag->getMatchType();
	llrp_u16_t pointer = pHbTargetTag->getPointer();
	llrp_u1v_t tagmask = pHbTargetTag->getTagMask();
	llrp_u1v_t tagdata = pHbTargetTag->getTagData();
	llrp_u1v_t tiddata = llrp_u1v_t(TID.m_nValue*8);
	memcpy(tiddata.m_pValue,TID.m_pValue,TID.m_nValue);


	//注意，因对个性化读的结果不知如何匹配，现在暂时未做tagdata的匹配。只做了TID匹配
	if(memorytype == MemoryType_TID){
		//要比对的两者数据长度不一样，直接返回假
		if(tiddata.m_nBit!=tagdata.m_nBit){
			return false;
		}
		//计算需掩码计算的长度,单位是位（bit）
		//注意，这里假设pointer的单位是字（这个目前不能确定是字）
		int masklen = 0;
		if((tiddata.m_nBit-pointer*16)>=tagmask.m_nBit){
			masklen = tagmask.m_nBit;
		}else{
			masklen = tiddata.m_nBit-pointer*16;
		}
        //printf("masklen=%d\n",masklen);
		//如是反向匹配，则对tagdata进行取反
		if(matchtype==MatchType_Reverse){
			for(int i=0;i<(tagdata.m_nBit+7u)/8u;i++){
				tagdata.m_pValue[i] = ~tagdata.m_pValue[i];
			}
		}
		//先对TID进行掩码运算
		for(int i=pointer*2;i<(masklen+7u)/8u;i++){
			tiddata.m_pValue[i] &= tagmask.m_pValue[(i-pointer*2)];
		}
		//再对tagdata进行掩码运算
		for(int i=pointer*2;i<(masklen+7u)/8u;i++){
			tagdata.m_pValue[i] &= tagmask.m_pValue[(i-pointer*2)];
		}
        //printf("mask tiddata is:");this->printU1VData(tiddata);
        //printf("mask tagdata is:");this->printU1VData(tagdata);
		//将tiddata和tagdata进行比对。这里只比对掩码的部分
		for(int i=pointer*2;i<(masklen+7u)/8u;i++){
			if(tiddata.m_pValue[i]!=tagdata.m_pValue[i]){
				return false;
			}
		}
		return true;
	}else if(memorytype == MemoryType_User){
		return true; //目前对用户区的匹配被认为始终匹配
	}
	return false;
}

bool Rf_Oper_Base::isDoneCancellation(int antennaid,int freqindex){
	return true;
}

void Rf_Oper_Base::putDoeCancellation(llrp_u8_t antennaid,int freqindex){
	
}

string Rf_Oper_Base::convertADDataToString(){
	string restr = "";
	for(map<int,vector<int>* >::iterator it=m_DoneCancellationSets.begin();
			it!=m_DoneCancellationSets.end();it++){
		char str[10];
		sprintf(str,"%d:",it->first);
		restr = restr + str;
		vector<int> * pfreqs = it->second;
		if(pfreqs->size()>0){
			for(int i=0;i<pfreqs->size()-1;i++){
				sprintf(str,"%d,",pfreqs->at(i));
				restr = restr + str;
			}
			sprintf(str,"%d|",pfreqs->at(pfreqs->size()-1));
			restr = restr + str;
		}
	}

	return restr;
}

/**
 * @brief Rf_Oper_GB::switchCarrier
 * @param antid，天线号1~4
 * @param freqid
 * @param on_off
 * @return
 */
bool Rf_Oper_Base::switchCarrier(int antid,int freqid,bool on_off){

	/*AA_ConfigParam =  0xAA00005500000000;
	printf("AA_ConfigParam = %llx\n",AA_ConfigParam);*/

	AB_ConfigParam &= 0xAB00000000000000;
	llrp_u64_t temp = 0x0003000000000000;
	//llrp_u64_t temp = 0x0001000000000000;
	AB_ConfigParam |= temp;
    printf("switchCarrier:AB_ConfigParam = %llx\n",AB_ConfigParam);
    this->sendParamToRf(PARAM_AB,0);

    //printf("switchCarrier:antid=%d\n",antid);

    if(antid==2){
        antid = 3;
    }else if(antid==3){
        antid = 2;
    }

    AC_ConfigParam &= 0xAC00000000000000;
    temp = antid-1;
    AC_ConfigParam |= temp<<48;
    temp = freqid;
    AC_ConfigParam |= temp<<40;

    //printf("a2...................................................\n");

    temp = 15; //功率
    AC_ConfigParam |= temp<<32;

    //泄漏对消阈值，暂定为0x0000
    temp = 0x00;
    AC_ConfigParam |= temp<<24;
    temp = 0x00;
    AC_ConfigParam |= temp<<16;

    //printf("a3...................................................\n");

    //任务模式
    temp = SETRFWORK_ANT;
    AC_ConfigParam |= temp<<8;

    //加入除帧头外的6字节异或出的CRC
    temp = this->calcCrc8(AC_ConfigParam);
    AC_ConfigParam |= temp;
    printf("switchCarrier:AC_ConfigParam = %llx\n",AC_ConfigParam);

    this->sendParamToRf(PARAM_AC,SETRFWORK_ANT);

    AC_ConfigParam &= 0xAC00000000000000;
    temp = antid - 1;
    AC_ConfigParam |= temp<<48;
    temp = freqid;
    AC_ConfigParam |= temp<<40;

    //printf("a2...................................................\n");

    temp = 15; //功率
    AC_ConfigParam |= temp<<32;

    //泄漏对消阈值，暂定为0x0000
    temp = 0x00;
    AC_ConfigParam |= temp<<24;
    temp = 0x00;
    AC_ConfigParam |= temp<<16;

    //printf("a3...................................................\n");

    //任务模式
    temp = SETRFWORK_FREQ;
    AC_ConfigParam |= temp<<8;

    //加入除帧头外的6字节异或出的CRC
    temp = this->calcCrc8(AC_ConfigParam);
    AC_ConfigParam |= temp;
    printf("switchCarrier:AC_ConfigParam = %llx\n",AC_ConfigParam);

    this->sendParamToRf(PARAM_AC,SETRFWORK_FREQ);

    if(on_off==0){
        printf("close carrier!\n");
        this->stopRfOper();
    }else{
        printf("open carrier!\n");
        this->startRfOper();
    }
	return true;
}

void Rf_Oper_Base::setACParam(int antid,int freqid,int worktype){
    this->setACParam(antid,freqid,15,worktype);
}

/**
 * @brief Rf_Oper_GB::setACParam
 * @param antid，天线编号从1开始。
 * @param freqid，频道编号从0开始。
 * @param powerid,功率序号
 * @param worktype
 */
void Rf_Oper_Base::setACParam(int antid,int freqid,int powerid,int worktype){
    unsigned long long temp = 0;
    AC_ConfigParam &= 0xAC00000000000000;
    temp = antid-1;
    AC_ConfigParam |= temp<<48;
    temp = freqid;
    AC_ConfigParam |= temp<<40;

    //printf("a2...................................................\n");

    temp = powerid; //功率
    AC_ConfigParam |= temp<<32;

    //泄漏对消阈值
    temp = 0x07;
    AC_ConfigParam |= temp<<24;
    temp = 0xD0;
    AC_ConfigParam |= temp<<16;

    //printf("a3...................................................\n");

    //任务模式
    temp = worktype;
    AC_ConfigParam |= temp<<8;

    //加入除帧头外的6字节异或出的CRC
    temp = this->calcCrc8(AC_ConfigParam);
    AC_ConfigParam |= temp;
    //printf("setACParam:AC_ConfigParam = %llx\n",AC_ConfigParam);
}

STRUCT_ANTCFG_DATA Rf_Oper_Base::getAntCfgStruct(CAntennaConfiguration *pAntcfg){
    STRUCT_ANTCFG_DATA struct_antcfg;
    struct_antcfg.AntID = pAntcfg->getAntennaID();
    if(struct_antcfg.AntID>0){
        struct_antcfg.AntID = struct_antcfg.AntID - 1;
    }
    struct_antcfg.PowerIndex = pAntcfg->getTransmitPowerIndex();
    //2018.01.05新加，检查频率列表是否为空
    if(pAntcfg->getFrequencyIndexes().m_nValue<=0){
        struct_antcfg.FreqIndexes = llrp_u16v_t(1);
        struct_antcfg.FreqIndexes.m_pValue[0] = 0;
    }else{
        struct_antcfg.FreqIndexes = pAntcfg->getFrequencyIndexes();
    }
    struct_antcfg.ForRateIndex = pAntcfg->getForDataRateIndex();
    struct_antcfg.RevRateIndex = pAntcfg->getRevDataRateIndex();
    struct_antcfg.ForModeIndex = pAntcfg->getForModulationIndex();
    struct_antcfg.RevEncodingIndex = pAntcfg->getRevDataEncodingIndex();
    struct_antcfg.CurrentFreqIndex = 0; //这里设置初始频率序号
    return struct_antcfg;
}

/**
 * @brief Rf_Oper_GB::setAntCFG
 * @param pSpec
 * 设置并保存当前天线相关配置
 * 如CAntennaSpec没变，则不会做操作
 */
void Rf_Oper_Base::setAntCFG(CAntennaSpec * pAntennaSpec,CRfSpec *pRfSpec){

    if(pAntennaSpec==NULL){
        printf("pAntennaSpec is NULL!\n");
    }else{
        //printf("pAntennaSpec is not NULL!\n");
    }

    if(pAntennaSpec==m_pCurrentAntSpec){
        //printf("pAntennaSpec==m_pCurrentAntSpec\n");
        return;
    }else{
        //printf("pAntennaSpec!=m_pCurrentAntSpec\n");
    }

    m_pCurrentAntSpec = pAntennaSpec;

    if(pRfSpec==NULL){
        printf("pRfSpec is NULL!\n");
    }

    //天线号为1～4。
    llrp_u8v_t antennaids = pAntennaSpec->getAntennaIDs();
    if(antennaids.m_nValue==0){
        printf("Rf_Oper_Base:no antennaID!\n");
        return;
    }
    //以下检查天线组是否有0号天线,或非法天线号，如有，表示使用所有天线
    //将天线组更改为1~4的4组值。
    bool haszero = false;
    for(int i=0;i<antennaids.m_nValue;i++){
        if(antennaids.m_pValue[i]<=0||antennaids.m_pValue[i]>4){
            haszero = true;
        }
    }
    if(haszero==true){
        antennaids = llrp_u8v_t(4);
        for(int i=0;i<4;i++){
            antennaids.m_pValue[i] = i+1;
        }
    }
    //////////////////////////////////////////////////////
    m_AvailableAntIDs.clear();  
    for(int i=0;i<antennaids.m_nValue;i++){
        m_AvailableAntIDs.push_back(antennaids.m_pValue[i]-1);
    }
    m_CurrentAntIDIndex = 0;

    printf("SetAntCFG:ant count =%d\n",antennaids.m_nValue);
    for(int i=0;i<antennaids.m_nValue;i++){
        printf("SetAntCFG:ant id =%d\n",antennaids.m_pValue[i]);
    }
    /////////////////////////////////////////////////////
    //printf("m_AntIDToAntCFG.clear()......................................\n");
    m_AntIDToAntCFG.clear();    

    if(pRfSpec->beginAntennaConfiguration()==pRfSpec->endAntennaConfiguration()){
        printf("AntennaConfiguration is null! Use default configuration!\n");
        CSetDeviceConfig *pdevicecfg = g_pMainApplication->getParamManager()->getDeviceConfig();
        //有默认配置采用默认配置，无则生成一个默认的配置
        if(pdevicecfg->beginAntennaConfiguration()!=pdevicecfg->endAntennaConfiguration()){
            //将所有默认配置加载入内存中
            for(list<CAntennaConfiguration*>::iterator it=pdevicecfg->beginAntennaConfiguration();
                it!=pdevicecfg->endAntennaConfiguration();it++){
                //printf("mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n");
                CAntennaConfiguration *antcfg = *it;
                STRUCT_ANTCFG_DATA struct_antcfg = this->getAntCfgStruct(antcfg);
                //printf("struct_antcfg.FreqIndexes.m_nValue=%d\n",struct_antcfg.FreqIndexes.m_nValue);
                m_AntIDToAntCFG.insert(pair<int,STRUCT_ANTCFG_DATA>(struct_antcfg.AntID,struct_antcfg));
            }
        }else{
            //printf("nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn\n");
            CAntennaConfiguration *antcfg = g_pMainApplication->getParamManager()->getDefalutAntennaConfiguration(1); //默认1号天线
            g_pMainApplication->getParamManager()->getDeviceConfig()->addAntennaConfiguration(antcfg);
            STRUCT_ANTCFG_DATA struct_antcfg = this->getAntCfgStruct(antcfg);
            m_AntIDToAntCFG.insert(pair<int,STRUCT_ANTCFG_DATA>(struct_antcfg.AntID,struct_antcfg));

        }
    }else
    {
        //printf("AntennaConfiguration is not empty,Use this configuration!\n");
        for(list<CAntennaConfiguration*>::iterator it=pRfSpec->beginAntennaConfiguration();
            it!=pRfSpec->endAntennaConfiguration();it++){
            if(m_AvailableAntIDs.size()<=m_AntIDToAntCFG.size()){//防止两个数组大小不一至
                break;
            }
            //printf("ooooooooooooooooooooooooooooooo\n");
            CAntennaConfiguration *antcfg = *it;
            STRUCT_ANTCFG_DATA struct_antcfg = this->getAntCfgStruct(antcfg);
            m_AntIDToAntCFG.insert(pair<int,STRUCT_ANTCFG_DATA>(struct_antcfg.AntID,struct_antcfg));
        }
    }
    //运行到这里时，m_AntIDToAntCFG至少会有一个成员
    //2018.01.05新加，检查是否每个天线都有一个对应的STRUCT_ANTCFG_DATA对象
    for(int i=0;i<m_AvailableAntIDs.size();i++){
        map<int,STRUCT_ANTCFG_DATA>::iterator it = m_AntIDToAntCFG.find(m_AvailableAntIDs.at(i));
        if(it==m_AntIDToAntCFG.end()){ //没有找到，则复制第一个天线设置中除天线号外的设置
            STRUCT_ANTCFG_DATA struct_antcfg = m_AntIDToAntCFG.begin()->second;
            m_AntIDToAntCFG.insert(pair<int,STRUCT_ANTCFG_DATA>(m_AvailableAntIDs.at(i),struct_antcfg));
        }

    }
    return;
}

CAntennaConfiguration *Rf_Oper_Base::findAntennaConfig(list<CAntennaConfiguration*>::iterator beginit,list<CAntennaConfiguration*>::iterator endit,llrp_u8_t antennaid){
	for(list<CAntennaConfiguration*>::iterator it=beginit;
		it!=endit;it++){
		CAntennaConfiguration *acfg = *it;
		if(antennaid==acfg->getAntennaID()){
			return acfg;
		}
	}
	return NULL;
}

llrp_u8_t Rf_Oper_Base::calcCrc8(llrp_u64_t data){
    unsigned char buf[8] = {0};
    for(int i=0;i<8;i++){
        buf[i] = data>>((7-i)*8);
    }
    llrp_u8_t crc = 0x00;
    for(int i=1;i<7;i++){
        crc ^= buf[i];
    }
    return crc;
}


/**
 * @brief Rf_Oper_GB::isFPGATurnEnd
 * @return
 * FPGA本轮操作结束，即完成一次select
 */
bool Rf_Oper_Base::isFPGATurnEnd(){
    if(m_pIOCtrl->readFPGAIO(0)==1){
        return true;
    }else{
        return false;
    }
}

bool Rf_Oper_Base::waitFPGATurnEnd(){
    int overtime_count = 0;
    while(1){
        if(m_pIOCtrl->readFPGAIO(0)==1){
            break;
        }
        overtime_count++;
        if(overtime_count>15){
            printf("wait fpga turn end overtime..........................................\n");
            return false;
        }
        Delay_ms(1); //休眠
    }
    return true;
}

/**
 * @brief Rf_Oper_GB::waitFPGANeedComm
 * @param overtime，几个1ms
 * @return
 */
bool Rf_Oper_Base::waitFPGANeedComm(int overtime){
    int overtime_count = 0;
    while(1){
        if(m_pIOCtrl->readFPGAIO(1)==1){
            break;
        }
        overtime_count++;
        if(overtime_count>overtime){
            printf("wait fpag need comm overtime..........................................\n");
            return false;
        }
        Delay_ms(1); //休眠
    }
    return true;
}

void Rf_Oper_Base::setFPGASingleStart(){
    this->m_pIOCtrl->setSingleEnd(0);
}

/**
 * @brief Rf_Oper_GB::setFPGASingleEnd
 * 在一次select操作中，通知FPGA当前标签操作结束
 */
void Rf_Oper_Base::setFPGASingleEnd(){
    this->m_pIOCtrl->setSingleEnd(1);
    //usleep(10);
    //this->m_pIOCtrl->setSingleEnd(0);
}

/**
 * @brief Rf_Oper_GB::isFPGARWOver
 * @return
 * FPGA是否读写操作结束(安全模块一次读写操作结束)
 */
bool Rf_Oper_Base::isFPGARWOver(){
    if(m_pIOCtrl->readFPGAIO(2)==1){
        return true;
    }else{
        return false;
    }
}

bool Rf_Oper_Base::waitFPGARWOver(){
    int overtime_count = 0;
    while(1){
        if(m_pIOCtrl->readFPGAIO(2)==1){
            break;
        }
        overtime_count++;
        if(overtime_count>30){
            printf("wait fpag rw over overtime..........................................\n");
            return false;
        }
        Delay_ms(1); //休眠
    }
    return true;
}

llrp_u64_t Rf_Oper_Base::getFPGAVersion(){
	llrp_u64_t verack = 0x00ll;
	llrp_u64_t a9_param = 0xA901000000000000ll; //读取FPGA版本命令
	//llrp_u64_t a9_param = 0xAAAAAAAAAAAAAAAAll;
	
	
	unsigned char sendbufspi[8+2] = {0x00};
    unsigned char receivebufspi[8+2] = {0x00};
			
	for(int i=0;i<8;i++){
		sendbufspi[i] = *(((unsigned char *)&a9_param)+7-i);
	}
	printf("Read FPGA version...............\n");

//  printf("spi send buf is:");
//	for(int i=0;i<8;i++)
//	{
//		printf("%02x,",sendbufspi[i]);
//	}
//  printf("\n");

	this->writeSPIData(sendbufspi,8);
	//Sim_SPI_ReadWriteBuf(sendbufspi,receivebufspi,8);

	Delay_ms(1);
	memset(sendbufspi,0xff,8+2);
	
	//Sim_SPI_ReadWriteBuf(sendbufspi,receivebufspi,8+2);
	readSPIData(receivebufspi,8+2);
	
	printf("spi rec buf is:");
	for(int i=0;i<8+2;i++)
	{
		printf("%02x,",receivebufspi[i]);
	}
	printf("\n");
	if(receivebufspi[0] == 0xB9)
	{
		
		for(int i=0;i<8;i++){
			//printf("spi[%d]=0x%02x,",i,receivebufspi[i]);
			verack |= ((llrp_u64_t)receivebufspi[i])<<(56-i*8);
		}
		printf("verack is %llx\n",verack);

	}
  return verack;  

}

