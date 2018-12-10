#include "operationreport_manager.h"
#include <stdio.h>
#include "general_functions.h"
#include "general.h"
#include "main_application.h"
//char m_SelectStep_temp;
OperationReport_Manager::OperationReport_Manager()
{
    BankID_Index = 0;

}

/*
 * 从AccessCommand中找到与用户区相对应的Opspec
 */
CParameter* OperationReport_Manager::findOpspecInAccessCommand(int userid,CAccessCommand *pAccessCommand){
    for(list<CParameter*>::iterator it=pAccessCommand->beginOpSpec();it!=pAccessCommand->endOpSpec();it++){
        //printf("d0\n");
        CParameter *popspec = *it;
        switch(popspec->m_pType->m_TypeNum+PARAM_BASE){
        case HbReadSpec:
        {
            CMemoryBank *pbank = ((CHbReadSpec*)popspec)->getMemoryBank();
            if(pbank==NULL){
                return NULL;
            }
            if(pbank->getMemoryBankID()==userid){
                return popspec;
            }
        }
            break;
        case HbWriteSpec:
        {
            if(((CHbWriteSpec*)popspec)->getMemoryBankID()==userid){
                return popspec;
            }
        }
            break;
        default:
            return NULL;
            break;
        }
    }
    return NULL;
}



/**
 * @brief OperationReport_Manager::wrapOpspecResults
 * @param pOpspecResults
 * @param pTagSelectSpec
 * @return
 * 将m_TempOpsecResults的内容打包成SelectAccessResult
 */
Tag_SelectAccessResult * OperationReport_Manager::wrapOpspecResults(vector<OpspecResult*>* pOpspecResults,Tag_SelectSpec *pTagSelectSpec){
    if(pOpspecResults->size()>0){
        //printf("A0..........................\n");
        vector<OpspecResult*>* pselectresults = new vector<OpspecResult*>();
        vector<OpspecResult *> *popresults = NULL;
        //先放入盘点结果（可能包含读一个分区的数据）
        OpspecResult *popres = new OpspecResult();
        //printf("A1..........................\n");
        //this->m_pRfOper->printfSecFrame(pOpspecResults->at(0)->pOpResultFrame);
        popres->pOpResultFrame = MCUToSecureComm::copyFrame(pOpspecResults->at(0)->pOpResultFrame);
        popres->setOpParams(pTagSelectSpec,NULL);
        pselectresults->push_back(popres);
        //printf("C3...............................\n");
        if(pOpspecResults->at(0)->pAccessSpec!=NULL){//有Access
            popresults = new vector<OpspecResult*>();
            //将原数据作为Access结果放入
            CAccessCommand *paccesscmd = pOpspecResults->at(0)->pAccessSpec->getAccessCommand();
            list<CParameter*>::iterator it = paccesscmd->beginOpSpec();
            for(int i=0;i<pOpspecResults->size();i++){
                //printf("c5............................\n");
                OpspecResult *popres = pOpspecResults->at(i);
                //popres->pSelectSpec = pTagSelectSpec->getSelectSpec();
                popres->pAccessSpec = pOpspecResults->at(0)->pAccessSpec;
                popres->pOpSpec = *it;
                it ++;
                popresults->push_back(popres);
            }

        }else{ //没有Access，则认为仅有盘点数据。删除ptempresults内的内容;
            if(pOpspecResults!=NULL){
                for(int i=0;i<pOpspecResults->size();i++){
                    delete pOpspecResults->at(i);
                }
            }
        }
        //printf("A5.......................\n");
        Tag_SelectAccessResult *presult = new Tag_SelectAccessResult();
        presult->ptagSelectResult = pselectresults;
        presult->ptagAccessOpResults = popresults;
        pOpspecResults->clear(); //结束后，清除临时缓存
        return presult;
    }else{
        return NULL;
    }
}

/**
 * @brief OperationReport_Manager::getSAResFromOpRes
 * @param pDatas
 * @param pTagSelectSpec
 * @return
 * 从标签操作结果中，将同一次select及所属的access操作（可能没有）的数据打包入Tag_SelectAccessResult中
 * 以方便生成操作报告。此方法操作后，OpspecResult即从队列中去除（但对象并未删除）
 */
Tag_SelectAccessResult * OperationReport_Manager::getSAResFromOpRes(){

    if(m_pOpSpecExec->getOpResultSize()<=0){
        return NULL;
    }
    Tag_SelectAccessResult *pselectaccessresult = NULL;
    llrp_u8v_t firsttid = llrp_u8v_t(0);

    while(m_pOpSpecExec->getOpResultSize()>0){
        //printf("A0.......................\n");
		  	//上报的 m_OpResults 从容器中取出来
        OpspecResult* popresult = m_pOpSpecExec->frontOpResult();
			
			
        if(popresult==NULL){//空数据不做处理，直接抛弃
            m_pOpSpecExec->popOpResult();
            printf("opresult is null,continue\n");
            continue;
        }
        //printf("A1.......................\n");

        /////////////////////////////////////////////////////////////////////
        vector<int>* pbankids = &popresult->Op_BankIDs;
        //pbankids->clear();
        //printf("pbankids.size=%d\n",pbankids->size());
        if(pbankids->size()>0){ //有读分区操作

            if(BankID_Index>=pbankids->size()){ //这里出现大于，则认为是出错了，直接重置BankID_Index
                //2017.07.21修改。以原先简单break，增加重置BankID_Index
                printf("BankID_Index>=pbankids->size(),break...............\n");
                BankID_Index = 0;
                break;
            }
            if(firsttid.m_nValue==0){
                firsttid = MCUToSecureComm::getTIDFromTagFrame(popresult->pOpResultFrame);
            }
            if(firsttid.m_nValue==0){ //当原始数据中有无TID  错误时，不做处理，丢弃数据直接跳过
                printf("no tid error!\n");
			        	//m_SelectStep_temp = 3;
			        	rfOper_OvertimerCount = 0;
                m_pOpSpecExec->popOpResult();
                delete popresult;
                printf("delete popresult;.................\n");
                continue;
            }

            if(popresult->pOpResultFrame->DataBuf[0]==0){//数据是成功数据
                llrp_u8v_t currenttid = MCUToSecureComm::getTIDFromTagFrame(popresult->pOpResultFrame);
                if(memcmp(firsttid.m_pValue,currenttid.m_pValue,firsttid.m_nValue)==0){ //当前TID和第一个TID相同
                    int userid = (popresult->pOpResultFrame->DataBuf[9]&0xF0)>>4;
                    //printf("A3...............\n");
                    if(userid==pbankids->at(BankID_Index)){//当前数据就是要读取的分区数据
                        if(popresult->getTagSelectSpec()->currentpTagAccessSpec!=NULL){
                            //printf("A3:0,,,,,,,,,,,,,,,,,,,,,,,,\n");
                            popresult->pOpSpec = this->findOpspecInAccessCommand(userid,popresult->pAccessSpec->getAccessCommand());
                        }else{
                            //printf("A3:1,,,,,,,,,,,,,,,,,,,,,,,,\n");
                            popresult->pAccessSpec = NULL;
                            popresult->pOpSpec = NULL;
                        }
                        //printf("A4...............\n");
                        m_TempOpsecResults.push_back(popresult);
                        BankID_Index++;
                        m_pOpSpecExec->popOpResult();
                        if(BankID_Index>=pbankids->size()){
                            //printf("A5...............\n");
                            pselectaccessresult = wrapOpspecResults(&m_TempOpsecResults,popresult->getTagSelectSpec());

                            BankID_Index = 0;
                            return pselectaccessresult;
                        }
                        //printf("A6...............\n");
                    }else{//不是所要的，则认为前一轮读已结束。重置idindex
                        //printf("Result data is not request data!.................\n");
                        if(userid!=pbankids->at(0)){ //也不是下一轮的开始，则删除
                            m_pOpSpecExec->popOpResult();
                            delete popresult;
                        }
                        //printf("w1.......................\n");
                        pselectaccessresult = this->wrapOpspecResults(&m_TempOpsecResults,popresult->getTagSelectSpec());
                        //printf("return result 2............\n");
                        BankID_Index = 0;
                        return pselectaccessresult;
                    }

                }else{//当前TID与第一个TID不相同。则返回一个SelectAccess结果。

                    pselectaccessresult = this->wrapOpspecResults(&m_TempOpsecResults,popresult->getTagSelectSpec());
                    //printf("return result 1............\n");
                    BankID_Index = 0;
                    //delete ptempresults;

                    return pselectaccessresult;
                }

            }else{//有错误数据
                //注：这里应注意，如果一直都是错误数据，则有可能在停 止读卡时，错误数据一直被保存在m_TempOpspecResults中，
                //因而导致停止读卡后，读卡规则不能被正确释放.
                //另，还有可能m_TempOpspecResults过大导致内存崩溃
                //2017.08.08修改，加限制不会内存崩溃
//                if(m_TempOpsecResults.size()<2){
//                    m_TempOpsecResults.push_back(popresult);
//                }
								printf("delete popresult;.................\n");		
                m_pOpSpecExec->popOpResult();
                delete popresult;
                						
            }
        }else{//无分区要读，则认为是单盘点数据
            //单盘点时，无论返回的数据是否为空或错误，都作为结果上报。
            //printf("single select......................\n");
            vector<OpspecResult*>* pselectresults = new vector<OpspecResult*>();
            pselectresults->push_back(popresult);
            m_pOpSpecExec->popOpResult();
            pselectaccessresult = new Tag_SelectAccessResult();
            pselectaccessresult->ptagSelectResult = pselectresults;
            pselectaccessresult->ptagAccessOpResults = NULL;
            //printf("return result 3............\n");
            BankID_Index = 0;
            return pselectaccessresult;
        }
    }
    //printf("getSAResFromOpRes return NULL!\n");
    return NULL;
}

/**
 * @brief genTagReportData
 * @param pSelectResult
 * @param pAccessResults
 * @return
 * 将Select和Access操作结果打包在同一个TagReportData中
 */
CTagReportData* OperationReport_Manager::genTagReportData(vector<OpspecResult *> * pSelectResult,vector<OpspecResult *> * pAccessResults,unsigned char carid){
    if(pSelectResult==NULL){ //传入的Select结果指针为空，直接返回空，即必须要有Select结果
        return NULL;
    }

    CTagReportData *prepdata = NULL;
    vector<OpspecResult *>* presults = pSelectResult; //每个presultes中的结果对象中，select和access都是同样的。
    if(presults->size()<=0){
        return NULL;
    }
    STRUCT_M2SEC_FRAME *pframe;
    pframe = presults->at(0)->pOpResultFrame;
    if(pframe==NULL){ //Select操作结果中第一个为返回帧为空，不生成报告
        return NULL;
    }

    if(pframe->DataBuf==NULL){
        return NULL;
    }

    if((pframe->Type&0xF0)!=0xB0&&(pframe->DataBuf[0]==1||pframe->DataBuf[0]==3)){ //如果是没有TID号的错误，不生成报告
        return NULL;
    }

    CSelectSpec *pselectspec= presults->at(0)->pSelectSpec;
    CAntennaSpec *pantennaspec = *(pselectspec->beginAntennaSpec());
    CRfSpec *prfspec = (*pantennaspec->beginRfSpec());
    CSelectReportSpec *pselecreport = pselectspec->getSelectReportSpec();

    //以下获取TID
    llrp_u8v_t TID = llrp_u8v_t(8);

    if((pframe->Type&0xF0)==0xB0){ //写分区响应帧
        TID = presults->at(0)->operTagTID;
    }else{//读响应帧

        int datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];

        if(pframe->OperId==1){ //是标签识别数据
            if((datalen-2)<13){//数据长度错误，不处理
                return NULL;
            }else{
                memcpy(TID.m_pValue,pframe->DataBuf+1,TID.m_nValue);
            }
        }else if(pframe->OperId==2||pframe->OperId==3){//是读分区信息数据
            if((datalen-2)<13){
                return NULL;
            }else{
                memcpy(TID.m_pValue,pframe->DataBuf+1,TID.m_nValue);
            }
        }else{//其它信息，暂不处理
            return NULL;
        }
    }
    //////////////////////////////////////////////////////////
    //以下根据上报规则添加报告
    //printf("e4.........................................\n");
    prepdata = (CTagReportData*)HbFrame_Operation::genParam(TagReportData,0,NULL);

    //放入TID
    prepdata->setTID(TID);

    //printf("e5.........................................\n");
    if(pselecreport->getEnableSelectSpecID()){
        CSelectSpecID *pselectid = (CSelectSpecID*)HbFrame_Operation::genParam(SelectSpecID,0,NULL);
        pselectid->setSelectSpecID(pselectspec->getSelectSpecID());
        prepdata->setSelectSpecID(pselectid);
    }
    //printf("e6\n");
    if(pselecreport->getEnableSpecIndex()){
        CSpecIndex *pspecindex = (CSpecIndex*)HbFrame_Operation::genParam(SpecIndex,0,NULL);
        pspecindex->setSpecIndex(0); //暂定为0
        prepdata->setSpecIndex(pspecindex);
    }
    //printf("e7\n");
    if(pselecreport->getEnableRfSpecID()){
        CRfSpecID *prfid = (CRfSpecID*)HbFrame_Operation::genParam(RfSpecID,0,NULL);
        prfid->setRfSpecID(0);
        prepdata->setRfSpecID(prfid); //非真实数据，暂定为0
    }
    //printf("c3\n");
    if(pselecreport->getEnableAntennaID()){
        CAntennaID *pantid = (CAntennaID*)HbFrame_Operation::genParam(AntennaID,0,NULL);
        //printf("AntennaID=%02x\n",pframe->DataBuf[9]);
        if((pframe->Type&0xF0)==0xB0){//写结果帧
            //printf("B4..........................................\n");
            int t = presults->at(0)->operAntennaID;
            //对调天线号
            if(t==2){
                t = 3;
            }else if(t==3){
                t = 2;
            }
            pantid->setAntennaID(t); //这里要注意，天线的编号在UHF中是从1开始，在安全模块返回信息中是从0开始。
            prepdata->setAntennaID(pantid);
        }
        else{
            if(pframe->OperId==1){ //帧是盘点结果帧
                int t = pframe->DataBuf[9]+1;
                //对调天线号
                if(t==2){
                    t = 3;
                }else if(t==3){
                    t = 2;
                }
                pantid->setAntennaID(t); //这里要注意，天线的编号在UHF中是从1开始，在安全模块返回信息中是从0开始。
                prepdata->setAntennaID(pantid);
            }else if(pframe->OperId==2||pframe->OperId==3){//帧是读分区结果帧
                int t = (pframe->DataBuf[9]&0x03) + 1;
                //对调天线号
                if(t==2){
                    t = 3;
                }else if(t==3){
                    t = 2;
                }
								//添加修改从节点序号
								//TID(8byte)+天线号(1byte)+RTC时间
								//修改天线号	
								pantid->setAntennaID(carid);
                //pantid->setAntennaID(t);
                prepdata->setAntennaID(pantid);
            }
        }
        //printf("pantid->getAntennaID=%d\n",pantid->getAntennaID());
    }
    //printf("c4\n");
    if(pselecreport->getEnablePeakRSSI()){
        CPeakRSSI * pssi = (CPeakRSSI*)HbFrame_Operation::genParam(PeakRSSI,0,NULL);
        pssi->setPeakRSSI(24); //此值硬件上暂未提供，故先定为23
        prepdata->setPeakRSSI(pssi);
    }

    //这里注意，时间最好从安全模块中取，这里用的是系统时间
    //struct timeval now;
    //gettimeofday(&now,NULL);

    //llrp_u64_t utcmsecs = General_Functions::getCurrentUTC();
		llrp_u64_t utcmsecs = 0;
    if(pselecreport->getEnableFirstSeenTimestamp()){
        CFirstSeenTimestampUTC *putc = (CFirstSeenTimestampUTC*)HbFrame_Operation::genParam(FirstSeenTimestampUTC,0,NULL);
        putc->setMicroseconds(utcmsecs);
        prepdata->setFirstSeenTimestampUTC(putc);
    }
    if(pselecreport->getEnableLastSeenTimestamp()){
        CLastSeenTimestampUTC *putc = (CLastSeenTimestampUTC *)HbFrame_Operation::genParam(LastSeenTimestampUTC,0,NULL);
        putc->setMicroseconds(utcmsecs+10);//暂时将结束时间固定为开始加10ms
        prepdata->setLastSeenTimestampUTC(putc);
    }
    if(pselecreport->getEnableTagSeenCount()){
        CTagSeenCount *pseencount = (CTagSeenCount*)HbFrame_Operation::genParam(TagSeenCount,0,NULL);
        pseencount->setTagCount(1); //暂时将总操作次数定为1
        prepdata->setTagSeenCount(pseencount);
    }
    if(pselecreport->getEnableAccessSpecID()){
        if(presults->at(0)->pAccessSpec!=NULL){
            CAccessSpecID  *paccessid = (CAccessSpecID*)HbFrame_Operation::genParam(AccessSpecID,0,NULL);
            paccessid->setAccessSpecID(presults->at(0)->pAccessSpec->getAccessSpecID());
            prepdata->setAccessSpecID(paccessid);
        }
    }
    //以下将Select结果数据加入报告
    if(presults->size()>0){
        OpspecResult *popres = presults->at(0);
        STRUCT_M2SEC_FRAME *pframe = popres->pOpResultFrame;
        if(pframe==NULL){
            printf("genTagReportData:pframe is NULL!\n");
        //}else if(popres->pAccessSpec==NULL){ //无Access，则认为是Select结果
        }
        {
            //printf("report:no access spec.........................................\n");
            if(pframe->OperId==1){ //是单识别结果。没有数据要添加，直接将报告加入集合
                //printf("no access:operid==1.................................\n");
            }else if(pframe->OperId==2){//是读分区结果。
                //printf("d7.........................................\n");
                //CMemoryBank *pbank = m_pRfOper->pCurrentRfSpec->getMemoryBank();
                CMemoryBank *pbank = prfspec->getMemoryBank();
                if(pbank!=NULL){//无bank，说明单盘点，不放入结果
                    CGenaralSelectSpecResult *pread = (CGenaralSelectSpecResult*)HbFrame_Operation::genParam(GenaralSelectSpecResult,0,NULL);
                    pread->setResult(pframe->DataBuf[0]);
                    pread->setTagData(MCUToSecureComm::getTagDataFromTagFrame(pframe,pbank));
                    prepdata->setSelectSpecResult((CParameter*)pread);
                }
            }else if(pframe->OperId==3){//是个性化读分区结果
                CMemoryBank *pbank = prfspec->getMemoryBank();
                if(pbank!=NULL){//无bank，说明单盘点，不放入结果
                    CCustomizedSelectSpecResult *pread = (CCustomizedSelectSpecResult*)HbFrame_Operation::genParam(CustomizedSelectSpecResult,0,NULL);
                    pread->setResult(pframe->DataBuf[0]);
                    CReadDataInfo * info = MCUToSecureComm::getCustomFromTagFrame(pframe);
                    if(info!=NULL){
                        pread->setReadDataInfo(info);
                    }
                    prepdata->setSelectSpecResult((CParameter*)pread);
                }
            }else{//其它结果不处理。

            }
        }
    }//end of if

    //如果有Access结果，则放入Access结果
    if(pAccessResults!=NULL){
        presults = pAccessResults; //每个presultes中的结果对象中，select和access都是同样的。
        //printf("pAcessResults.size=%d\n",pAccessResults->size());
        //printf("presults.size=%d\n",presults->size());
        for(int i=0;i<presults->size();i++){
            OpspecResult *popres = presults->at(i);
            STRUCT_M2SEC_FRAME *pframe = popres->pOpResultFrame;
            if(pframe==NULL){
                continue;
            }else  if((pframe->Type&0xF0)==0xB0){//如果是写分区结果返回帧

                CParameter *popspec = popres->pOpSpec;
                if(popspec!=NULL){
                    switch(popspec->m_pType->m_TypeNum+PARAM_BASE){
                    case HbWriteSpec:
                    {
                        //printf("Hbwirtespec result ...................\n");
                        CHbWriteSpecResult *pwriteresult = (CHbWriteSpecResult*)HbFrame_Operation::genParam(HbWriteSpecResult,0,NULL);
                        //printf("pframe->DataBuf[0]=%d\n",pframe->DataBuf[0]);
                        pwriteresult->setResult(pframe->DataBuf[0]);
                        CHbWriteSpec *pwritespec = (CHbWriteSpec*)popspec;
                        llrp_u16_t opspecid = pwritespec->getOpSpecID();
                        //printf("opspecid=%d\n",opspecid);
                        pwriteresult->setOpSpecID(opspecid);
                        if(pframe->DataBuf[0]==2){
                            llrp_u8v_t d = llrp_u8v_t(1);
                            d.m_pValue[0] = pframe->DataBuf[1];
                            pwriteresult->setResultDescription(d);
                        }
                        prepdata->addAccessSpecResult(pwriteresult);
                        //printf("hwWriteSpec result end........................\n");
                    }
                        break;
                    }
                }
            }else{

                if(pframe->OperId==1){ //是单识别结果,不作任何处理
                    //printf("has access:operid==1.................................\n");
                }else if(pframe->OperId==2){//是普通读分区。
                    //printf("has access:operid==2.................................\n");
                    CParameter *popspec = popres->pOpSpec;
                    if(popspec!=NULL){
                        switch(popspec->m_pType->m_TypeNum+PARAM_BASE){
                        case HbReadSpec:
                        {
                            //printf("Hbreadspec result ...................\n");
                            CHbReadSpecResult *pread = (CHbReadSpecResult*)HbFrame_Operation::genParam(HbReadSpecResult,0,NULL);
                            pread->setResult(pframe->DataBuf[0]); //表示当前读取是否是成功的。0表示成功。1表示失败
                            CHbReadSpec *preadspec = (CHbReadSpec*)popspec;
                            llrp_u16_t opspecid = preadspec->getOpSpecID();
                            pread->setOpSpecID(opspecid); //这里放入数据区操作ID
                            CMemoryBank *pbank = preadspec->getMemoryBank();
                            pread->setReadData(MCUToSecureComm::getTagDataFromTagFrame(pframe,pbank));
                            prepdata->addAccessSpecResult(pread);
                            //printf("Hbreadspec result end ...................\n");
                        }
                            break;
                        }
                    }
                }else if(pframe->OperId==3){//是个性化读分区数据
                    //printf("has access:operid==3.................................\n");
                    CParameter *popspec = popres->pOpSpec;
                    //printf("popsec=0x%x\n",popspec);
                    if(popspec!=NULL){
                        //printf("has access:operid==3:a0.................................\n");
                        //printf("popspec->m_pType->m_TypeNum+PARAM_BASE=%d\n",popspec->m_pType->m_TypeNum+PARAM_BASE);
                        switch(popspec->m_pType->m_TypeNum+PARAM_BASE){
                        case HbReadSpec:
                        {
                            //printf("has access:operid==3:a1.................................\n");
                            CHbCustomizedReadSpecResult *pread = (CHbCustomizedReadSpecResult*)HbFrame_Operation::genParam(HbCustomizedReadSpecResult,0,NULL);
                            pread->setResult(pframe->DataBuf[0]);
                            CHbReadSpec *preadspec = (CHbReadSpec*)popspec;
                            llrp_u16_t opspecid = preadspec->getOpSpecID();
                            pread->setOpSpecID(opspecid);
                            CReadDataInfo * info = MCUToSecureComm::getCustomFromTagFrame(pframe);
                            if(info!=NULL){
                                pread->setReadDataInfo(info);
                            }
                            prepdata->addAccessSpecResult(pread);
                        }
                            break;
                        case HbWriteSpec:

                            break;
                        }
                    }
                }else{

                }//end of if
            }
        }
    }
    return prepdata;
}

CTagSelectAccessReport* OperationReport_Manager::genSelectAccessReport(int reportdata_count,unsigned char carId){

    if(this->m_SelecAccessResults.size()<=0){
        return NULL;
    }


    CSelectSpec *pselectspec= m_SelecAccessResults.front()->ptagSelectResult->at(0)->pSelectSpec;
    //CAntennaSpec *pantennaspec = *(pselectspec->beginAntennaSpec());
    //CRfSpec *prfspec = (*pantennaspec->beginRfSpec());
    CSelectReportSpec *pselecreport = pselectspec->getSelectReportSpec();

    if(pselecreport==NULL){//没有报告规则，则使用默认规则
        printf("no selectreportspec,use default!\n");
        pselecreport = g_pMainApplication->m_pParamManager->getDefaultSelectReportSpec();
        pselectspec->setSelectReportSpec(pselecreport);//这里加入SelectSpec以方便删除
    }

    llrp_u8_t selreptrig =  pselecreport->getSelectReportTrigger();
    switch(selreptrig){
    case SelectReportTrigger_Unconditional://无触发条件，认为是一直上报
        break;
    case SelectReportTrigger_Antenna:
    {
        //天线规则用完或标签数据达到N条，则上报
        llrp_u16_t n = pselecreport->getNValue();
        if(this->m_SelecAccessResults.size()>=n){

        }else{
            //遍历天线规则，如全部用过，则上报。
            /*bool allused = true;
            for(list<TagAntennaSpec*>::iterator it=pTagSelect->tagAntennaSpeclist.begin();
                    it!=pTagSelect->tagAntennaSpeclist.end();it++){
                if(!(*it)->isUsed){
                    allused = false;
                    break;
                }
            }
            if(allused==true){
                needselectreport = true;
            }*/
            return NULL;
        }

    }
        break;
    case SelectReportTrigger_Label:
    //标签选则规则停止则上报
    {
        //选择规则停止或标签数据达到N条，则上报
        llrp_u16_t n = pselecreport->getNValue();
        //printf("SelectReportTrigger_Label.........................\n");
        //printf("m_SelecAccessResults.size()=%d,n=%d\n",m_SelecAccessResults.size(),n);
        if(this->m_SelecAccessResults.size()>=n||pselectspec->getSelectCurrentState()!=SelectCurrentState_Active){
            //printf("needselectreport............................................\n");

        }else{
            return NULL;
        }
    }
        break;
    case SelectReportTrigger_NoReport:
        return NULL;
        break;
    }

    CTagSelectAccessReport *ptagreport = (CTagSelectAccessReport*)HbFrame_Operation::genMessage(TagSelectAccessReport,0);
    int repcount = 0; //控制单个报告中，最大TagReportData数
    int ncount = pselecreport->getNValue(); //用以控制一次只打包规定的TagReportData
    if(ncount==0){ //等于零时，表示打包数量无限制，则将该数设置为最大充许数量
        ncount = reportdata_count;
    }
    while(m_SelecAccessResults.size()>0&&ncount>0&&repcount<reportdata_count){
        Tag_SelectAccessResult *ptagselectaccessresult = m_SelecAccessResults.front();
        m_SelecAccessResults.pop();

        CTagReportData *prepdata = this->genTagReportData(ptagselectaccessresult->ptagSelectResult,ptagselectaccessresult->ptagAccessOpResults,carId);
        if(prepdata!=NULL){
            //printf("prepdata!=NULL!\n");
            ptagreport->addTagReportData(prepdata);
            ncount--;
            repcount++;
        }
				delete ptagselectaccessresult;  //2018.01.11修正内存未删除的问题
    }

    return ptagreport;

}

CTagSelectAccessReport * OperationReport_Manager::frontSelectAccessReport(){
    CTagSelectAccessReport *preport = NULL;
    
    preport = m_SelectAccessReports.front();

    return preport;
}

/**
 * @brief OperationReport_Manager::popSelectAccessReport
 * 从队列中删除最前面的元素
 */
void OperationReport_Manager::popSelectAccessReport(){
    
    //CTagSelectAccessReport *preport = m_SelectAccessReports.front();
    m_SelectAccessReports.pop();
    //delete preport;
    
}

//void OperationReport_Manager::sendReportToComm(Base_Comm *pComm){
//    CMessage *pmessage = HbFrame_Operation::copyMessage()
//}

void OperationReport_Manager::run(){
    int count =  0; //为了避免过多占用CPU，这里做一个限制

    if(m_SelecAccessResults.size()<resualt_num){
        //先将非continue操作结果OpspecResult打包成SelectAccessResult（一次Select的结果，包含Select操作和Access操作的结果）
				//将含有的SelectAccessResult上报
				while(m_pOpSpecExec->getOpResultSize()>0&&count<resualt_num){
            //printf("has data need report!\n");
            Tag_SelectAccessResult *pselectaccessresult =  this->getSAResFromOpRes();
						//打印监控上报时的内存
					  //printf("----------size:%d---------------pselectaccessresult:0X%8X\n",m_pOpSpecExec->getOpResultSize(),(unsigned int)pselectaccessresult);					
            if(pselectaccessresult!=NULL){
								//printf("pselectaccessresult is not null!\n");
                m_SelecAccessResults.push(pselectaccessresult);
            }else{
                //printf("pselectaccessresult is null!\n");
            }
            count++;
        }        
        //再检查continue操作结果。
        count = 0;
        while(m_pOpSpecExec->getSelectAccessResultSize()>0&&count<resualt_num){
            m_SelecAccessResults.push(m_pOpSpecExec->frontSelectAccessResult());
            m_pOpSpecExec->popSelectAccessResult();
            count++;
        }
        
    }
    //将SelectAccessResult队列中的SelectAccessResult打包成报告，最多1个打包一个。
    if(m_SelectAccessReports.size()<=resualt_num){
        //printf("m_SelectAccessReports.size()<=10\n");
				//获取当前的消息车道号
				unsigned char id = g_pMainApplication->m_read_manage->current_dev;
        CTagSelectAccessReport *pselectaccessreport = this->genSelectAccessReport(1,id);

        if(pselectaccessreport!=NULL){
		  	printf("----------size:%d---------------pselectaccessreport:0X%8X\n",m_SelectAccessReports.size(),(unsigned int)pselectaccessreport);						
            //printf("gen report.....................\n");
            //HbFrame_Operation::printMessage(pselectaccessreport);
            m_SelectAccessReports.push(pselectaccessreport);
            //printf("report size =%d\n",m_SelectAccessReports.size());
        }
    }
}



