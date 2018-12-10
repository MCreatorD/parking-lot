#include "Rf_Oper_gb.h"
#include <stdio.h>
#include <math.h>

#include "main_application.h"
#include "XML_Operation.h"
#include "general_functions.h"

Rf_Oper_GB::Rf_Oper_GB() {
	// TODO Auto-generated constructor stub
	this->m_AntChangeDelay = SWITCHANT_DELAY*3;

}

Rf_Oper_GB::~Rf_Oper_GB() {
	// TODO Auto-generated destructor stub

}
/**
 * @brief Rf_Oper_GB::setFPGAWriteGB
 * 指示FPGA可以进行GB的写数据
 */
void Rf_Oper_GB::setFPGAWriteGBEnable(){
    this->m_pIOCtrl->setSingleEnd(0); //借用行标的本张标签操作结束信号指示国标对某张标签可以进行写操作。
}

void Rf_Oper_GB::setFPGAWriteGBDisable(){
    this->m_pIOCtrl->setSingleEnd(1); //借用行标的本张标签操作结束信号指示国标对某张标签可以进行写操作。
}

/**
 * @brief Rf_Oper_GB::setSelectAccessParam
 * @param pTagSelectSpec
 * @param pTagAccessSpec
 * @param antSpecIndex
 * @param pRfSpec
 * @return
 * 配置射频参数，与行标不同的是不操作安全模块
 * 对于国标，读用户区不应下发读USER0区的数据
 */
bool Rf_Oper_GB::setSelectAccessParam(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec){
    //如果要设置的参数与当前参数一至，什么也不做，直接返回真
    if(pTagSelectSpec==m_pCurrentSelectSpec&&pTagAccessSpec==m_pCurrentAccessSpec&&pRfSpec==m_pCurrentRfSpec){
        return true;
    }

    //printf("do set SelectAccessParam!\n");
    m_pCurrentSelectSpec = pTagSelectSpec;
    m_pCurrentAccessSpec = pTagAccessSpec;
    m_pCurrentRfSpec = pRfSpec;
    needSendParam = true;

    AB_ConfigParam = 0xAB04000000000000; //设为国标模式

    //设置当前Select的相关参数
    pTagSelectSpec->currentpTagAccessSpec = pTagAccessSpec;
    pTagSelectSpec->currentAntSpecIndex = antSpecIndex;
    if(pRfSpec!=NULL){
        pTagSelectSpec->currentRfSpecID = pRfSpec->getRfSpecID();
    }else{
        pTagSelectSpec->currentRfSpecID = 0; //因为RfSpecID规定必须是非0值。故用0表示是无效
    }
    pTagSelectSpec->currentOperBankIDs.clear();

    /////////////////////////////////////////////////////////////////////////////////

    if(pTagSelectSpec->currentpTagAccessSpec==NULL){//没有Access操作
        printf("no access\n");
        if(pRfSpec!=NULL){//这里同样不会为空指针，
            printf("AccessSpec is NULL!use no continue mode!\n");
            pTagSelectSpec->hasContinueOperation = false; //没有Ａccess，肯定没有continue操作
            return this->setNoContinueOpParam(pRfSpec,NULL,pTagSelectSpec);
        }
        //return false;
    }else{ //有Access操作。
        printf("has access\n");

        if(pRfSpec!=NULL){//这里同样不会为空指针，
            printf("AccessSpec is not NULL!use no continue mode!\n");
            pTagSelectSpec->hasContinueOperation = true; //标记为有continue操作
            return this->setNoContinueOpParam(pRfSpec,pTagAccessSpec->getAccessSpec(),pTagSelectSpec);
		}
    }
}

/*
 * 传入的是一对SelectSpec和AccessSpec
 * 如果pAccessSpec为NULL，即等同于setSelectMemParam函数的作用
 * 如不为NULL,则等同于不对AccessSpec做匹配选择，直接读AccessSpec所指定的分区信息，可为单分区，可为多分区。
 * 此时，selecSpec中传入的参数不起作用。
 */
bool Rf_Oper_GB::setNoContinueOpParam(CRfSpec *pRfSpec, CAccessSpec *pAccessSpec, Tag_SelectSpec *pTagSelectSpec){
    printf("setNoContinueParam.......................................\n");
    if(pRfSpec==NULL){
        printf("Rf_Oper_New:warnning,pRfSpec is null!\n");
        return false;
    }
   //==============================================//
        pTagSelectSpec->hasReadRepeat = false; //复位有重复读标志

        //这里对AB的配置必须加，否则会读卡失败
        llrp_u8_t selecttype = pRfSpec->getSelectType();

        AB_ConfigParam &= 0xFFFFFFFFFFFFFF00;
        C1_ConfigParam = 0xC100000000000000;
        C2_ConfigParam = 0xC200000000000000;
        C3_ConfigParam = 0xC300000000000000;
        C4_ConfigParam = 0xC400000000000000;
        C5_ConfigParam = 0xC500000000000000;
        C6_ConfigParam = 0xC600000000000000;

        if(pAccessSpec==NULL){ //无AccessSpec
            printf("selecttype=%d\n",selecttype);
            if(selecttype==0){//是盘点
                AB_ConfigParam |= 0x00;
                C1_ConfigParam |= 0x0000020000000000ll;
            }else{//是读
                AB_ConfigParam |= 0x01;
                C1_ConfigParam |= 0x0000080000000000ll;
                //C2_ConfigParam |= 0x0030760000000000ll;
                C2_ConfigParam |= 0x0030760080fe672d;
                //C3_ConfigParam |= 0x0030000400050000; // 读5个字
                //C3_ConfigParam |= 0x0030000400780000;
                //C3_ConfigParam |= 0x00300004003C0000; //读60个字
                C3_ConfigParam |= 0x0030000400140000; //读20个字
                Struct_TagBank_RWInfo bankinfos[6]; //最多6个分区。规范中分区5不能读，故最多5个分区
                int bankcount = 0;
                CMemoryBank *pbank = pRfSpec->getMemoryBank();
                pbank->setReadType(1); //国标强制为按分区读
                if(pbank!=NULL){
                    bankinfos[bankcount++] = this->getBankinfoFromMemBank(pbank);
                }

            }

            //AB_ConfigParam = 0xAB01000000000001;
            printf("SetAccessParam:AB_ConfigParam = %llx\n",AB_ConfigParam);
            printf("SetAccessParam:C1_ConfigParam = %llx\n",C1_ConfigParam);
            printf("SetAccessParam:C2_ConfigParam = %llx\n",C2_ConfigParam);
            printf("SetAccessParam:C3_ConfigParam = %llx\n",C3_ConfigParam);

            //发送配置帧给FPGA
            if(this->sendParamToRf(PARAM_AB,0)){
                printf("GB:send AB param success!\n");
            }
            if(this->sendGBParamToRf(C1_ConfigParam)){
                printf("GB:send C1 param success!\n");
            }
            if(this->sendGBParamToRf(C2_ConfigParam)){
                printf("GB:send C2 param success!\n");
            }
            if(this->sendGBParamToRf(C3_ConfigParam)){
                printf("GB:send C3 param success!\n");
            }
            //////////////////////////////////////////////////////////
        }else{//有AccessSpec

            AB_ConfigParam |= 0x01;

            C1_ConfigParam |= 0x0000100000000000l;
            C2_ConfigParam |= 0x0030980080fe672d;

            C4_ConfigParam |= 0x0030000000000000; //写2个字
            CAccessCommand *pcommand = pAccessSpec->getAccessCommand();
            //国标中，只支持一次写一个分区，故不管下发几个分区，只取第一个分区
            // 国标中，只有一个用户区，故不使用命令中的分区参数。
            if(pcommand->beginOpSpec()!=pcommand->endOpSpec()){
                CParameter *popspec= *pcommand->beginOpSpec();
                switch(popspec->m_pType->m_TypeNum+PARAM_BASE)
                {
                case HbReadSpec: //国标中，不需要在accessspec中有读操作
                    break;
                case HbWriteSpec: //国标中，可直接写，故这里直接根据写规则进行操作
                {
                    printf("a0....................................\n");
                    CHbWriteSpec *pwritespec = (CHbWriteSpec*)popspec;
                    llrp_u16_t pointer = pwritespec->getPointer();
                    llrp_u64_t temp = pointer;
                    C4_ConfigParam |= temp<<32; //放入pointer
                    llrp_u16v_t tagdata = pwritespec->getData();
                    //memcpy((llrp_u8_t*)&GB_Tagdata,(llrp_u8_t*)tagdata.m_pValue,tagdata.m_nValue*2); //取出数据

                    int count = tagdata.m_nValue/4;
                    if(tagdata.m_nValue%4!=0){
                        count  = count + 1;
                    }
                    for(int i=0;i<count-1;i++){
                        llrp_u64_t tempdata = 0;
                        int j = 0;
                        *(((llrp_u8_t*)&tempdata)+7) = tagdata.m_pValue[j]>>8;
                        *(((llrp_u8_t*)&tempdata)+6) = tagdata.m_pValue[j++];
                        *(((llrp_u8_t*)&tempdata)+5) = tagdata.m_pValue[j]>>8;;
                        *(((llrp_u8_t*)&tempdata)+4) = tagdata.m_pValue[j++];
                        *(((llrp_u8_t*)&tempdata)+3) = tagdata.m_pValue[j]>>8;;
                        *(((llrp_u8_t*)&tempdata)+2) = tagdata.m_pValue[j++];
                        *(((llrp_u8_t*)&tempdata)+1) =tagdata.m_pValue[j]>>8;;
                        *(((llrp_u8_t*)&tempdata)+0) = tagdata.m_pValue[j++];
                        m_GBTagdatas.push_back(tempdata);
                    }
                    llrp_u64_t tempdata = 0;
                    int a = 0;
                    if(tagdata.m_nValue%4!=0){
                       a = tagdata.m_nValue%4;

                    }else{
                        a = 4;
                    }
                    if(count>=1){
                        count = (count-1)*4;
                        //printf("count=%d,a=%d\n",count,a);
                         int j = 8;
                        for(int i=0;i<a;i++){
                            *(((llrp_u8_t*)&tempdata)+(--j)) = tagdata.m_pValue[count+i]>>8;
                            *(((llrp_u8_t*)&tempdata)+(--j)) = tagdata.m_pValue[count+i];
                        }
                        m_GBTagdatas.push_back(tempdata);

                    }
                    //printf("tagdata.m_nValue=%d\n",tagdata.m_nValue);
                    temp = tagdata.m_nValue;
                    C4_ConfigParam |= temp<<16;
                 }
                    break;
                case ClientRequestSpec:
                    break;

                }//end of switch

                printf("SetAccessParam:AB_ConfigParam = %llx\n",AB_ConfigParam);
                printf("SetAccessParam:C1_ConfigParam = %llx\n",C1_ConfigParam);
                printf("SetAccessParam:C2_ConfigParam = %llx\n",C2_ConfigParam);
                printf("SetAccessParam:C4_ConfigParam = %llx\n",C4_ConfigParam);


                //发送配置帧给FPGA
                if(this->sendParamToRf(PARAM_AB,0)){
                    printf("GB:send AB param success!\n");
                }
                if(this->sendGBParamToRf(C1_ConfigParam)){
                    printf("GB:send C1 param success!\n");
                }
                if(this->sendGBParamToRf(C2_ConfigParam)){
                    printf("GB:send C2 param success!\n");
                }
                if(this->sendGBParamToRf(C4_ConfigParam)){
                    printf("GB:send C4 param success!\n");
                }
                for(int i=0;i<m_GBTagdatas.size();i++){
                    if(this->sendGBParamToRf(m_GBTagdatas.at(i))){
                        printf("GB:GB_Tagdata[%d] = %0llx\n",i,m_GBTagdatas.at(i));
                        printf("GB:send GB_Tagdata[%d] success!\n",i);
                    }
                }
                m_GBTagdatas.clear();
								printf("\n setNoContinueOpParam -> 有AccessSpec -> if(pcommand->beginOpSpec()!=pcommand->endOpSpec()) \n");

            }
        }

}

/**
 * @brief Rf_Oper_GB::sendGBParamToRf
 * @param param
 * @return
 * 发送国标配置参数给射频
 */
bool Rf_Oper_GB::sendGBParamToRf(llrp_u64_t param){
    unsigned char sendbufspi[8] = {0x00};
    int datalen = 8;
    for(int i=0;i<8;i++){
        sendbufspi[i] = *(((unsigned char *)&param)+7-i);
    }
    if(!this->writeSPIData(sendbufspi,datalen)){
        return false;
    }
    return true;
}

bool Rf_Oper_GB::isRfNeedComm(){
    if(m_pIOCtrl->readFPGAIO(1)==1){
        return true;
    }
    return false;
}

void Rf_Oper_GB::removeGBFrame(STRUCT_RF2M_FRAME *pframe){
    if(pframe==NULL){
        return;
    }
    if(pframe->DataBuf!=NULL){
        delete [] pframe->DataBuf;
    }
    delete pframe;
    pframe = NULL;
}

/*
 * 读取国标标签数据
 */
STRUCT_RF2M_FRAME *Rf_Oper_GB::readGBTag(){
    //等待射频中断信号

//    if(this->waitFPGANeedComm(100)==false){
//        return NULL;
//    }
    if(this->isRfNeedComm()==false){
        return NULL;
    }

    //读取射频模块数据
    STRUCT_RF2M_FRAME *pframe = this->getFrameFromRf();
    if(pframe==NULL){
//		printf("GB_RfOper:getFrameFromSecure fail!\n");
        return NULL;
    }
    return pframe;
}

STRUCT_RF2M_FRAME * Rf_Oper_GB::getFrameFromRf(){
    int framelen = 100;//300;//512; //GB射频返回帧最大长度

    uint8_t buf[100];
    if(readSPIData(buf,framelen)){
        STRUCT_RF2M_FRAME * pframe = this->getGBDataFromBuf(buf,framelen);
        return pframe;
    }else{
        return NULL;
    }
}

STRUCT_RF2M_FRAME * Rf_Oper_GB::getGBDataFromBuf(uint8_t *buf,int buflen){

    if(buflen<11){
        return NULL;
    }
    if(buf[0]!=0x80||(buf[1]!=0x01&&buf[1]!=0x00)&&buf[1]!=0x02){
        return NULL;
    }

    //printf("a0...................................../n");
    STRUCT_RF2M_FRAME *pframe = new STRUCT_RF2M_FRAME;
    memset((unsigned char *)pframe,0x00,sizeof(STRUCT_RF2M_FRAME));
    pframe->Head[0] = buf[0];
    pframe->Head[1] = buf[1];
    pframe->FrameLen[0] = buf[2];
    pframe->FrameLen[1] = buf[3];
    uint16_t framelen = 0;
    framelen = pframe->FrameLen[0]<<8|pframe->FrameLen[1];
    //printf("framelen=%d\n",framelen);
    //printf("a1...................................../n");
    pframe->CpuCommand[0] = buf[4];
    pframe->CpuCommand[1] = buf[5];

    pframe->AntId[0] = buf[6];
    pframe->AntId[1] = buf[7];

//    if(pframe->AntId[1]==0x11){
//        printf("pframe->AntId[1]=%d\n",pframe->AntId[1]);
//        printf("rf_oper_gb:framelen%d\n",framelen);
//        printf("frame buflen=%d,buf is:",buflen);
//        for(int i=0;i<buflen;i++){
//            printf("0x%02x,",buf[i]);
//        }
//        printf("\n");
//    }

    pframe->SuccessMark[0] = buf[8];
    pframe->SuccessMark[1] = buf[9];

    //printf("a2...................................../n");
    if((framelen>4)&&(framelen<480)){
        //printf("a3...................................../n");
        uint16_t datalen = framelen*2-8;
        uint8_t *databuf = new uint8_t[datalen];
        memcpy(databuf,buf+10,datalen);
        pframe->DataBuf = databuf;
        pframe->DataLen[0] = datalen>>8;
        pframe->DataLen[1] = datalen;
    }else{
        //printf("a4...................................../n");

        //m_pIOCtrl->setSMResetHigh();
//        printf("rf_oper_gb:framelen%d\n",framelen);
//        printf("frame buflen=%d,buf is:",buflen);
//        for(int i=0;i<buflen;i++){
//            printf("0x%02x,",buf[i]);
//        }
//        printf("\n");
//        exit(0);
//        pframe->DataLen[0] = 0x00;
//        pframe->DataLen[1] = 0x00;
//        pframe->DataBuf = NULL;
        this->removeGBFrame(pframe);
        return NULL;
    }
    return pframe;
}
