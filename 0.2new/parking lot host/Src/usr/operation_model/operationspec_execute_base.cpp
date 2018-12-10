#include "operationspec_execute_base.h"

#include "general.h"
#include "general_functions.h"
#include "systick.h"

#include "rf_oper_gb.h"
#include "main_application.h"
#include "key_exit.h"
#include "rx485_rev.h"
#include "rx485_send.h"
#include "RX485_uart.h"
#include "communication.h"
//#define SIM_EXEC_MODE 

OperationSpec_Execute_Base::OperationSpec_Execute_Base(){
    m_pExecSelectSpec = NULL;
		
	if(RF_USE_GBFPGA){
		m_pRfOper = new Rf_Oper_GB();
	}
	else if(RF_USE_HBFPGA){
		m_pRfOper = new Rf_Oper_HB();
	}
	

    isIdle = true;
}

OperationSpec_Execute_Base::~OperationSpec_Execute_Base(){

}

/**
*	返回值表示当前操作是否完成
*/
bool OperationSpec_Execute_Base::singleSelectAccess(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,CAntennaSpec *pAntennaSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec){

    ///////////////////////////////////////////////////
    //printf("start single oper.....................................\n");

	if(simRun_Count>0){
		return false;
	}else{
		simRun_Count = 50; //每50ms执行一次
	}
	
	if(this->m_OpResults.size()>resualt_num){
		return true;
	}
	
	STRUCT_M2SEC_FRAME *pframe = this->getSimFrame();
	if(pframe!=NULL){

			//MCUToSecureComm::printfSecFrame(pframe);
			this->m_TagObTagNCount++;
			this->m_TagObTLastUTC = General_Functions::getCurrentUTC();
			OpspecResult *popresult = new OpspecResult();
			popresult->pOpResultFrame = pframe;

			popresult->setOpParams(pTagSelectSpec);
			this->pushOpResult(popresult);
	}
	return true;
    //printf("end single oper.......................\n");
}

void OperationSpec_Execute_Base::execSelectSpec(){

    CSelectSpec *pselectspec = m_pExecSelectSpec->getSelectSpec();
    //m_pExecSelectSpec->isSelectSpecFinish = false;
    //m_pExecSelectSpec->specStartUTC = General_Functions::getCurrentUTC();
    if(this->isSelectStop()==false&&this->forceExitExecute==false){

        //m_pExecSelectSpec->isSelectSpecFinish = false;
        //遍历TagAntennaSpec列表
        
        //for(list<CAntennaSpec*>::iterator antspec_it=pselectspec->beginAntennaSpec();
        //    antspec_it!=pselectspec->endAntennaSpec();antspec_it++){
            CAntennaSpec *pantennaspec = *antSpec_It;
            //2017.12.25新加
            m_AntennaStartUTC = General_Functions::getCurrentUTC();
            m_TagObTagNCount = 0;
            m_TagObTryCount = 0;
            m_TagObTLastUTC = General_Functions::getCurrentUTC();
            m_TagObTrgStartUTC = General_Functions::getCurrentUTC();
            //////////////////////////////////////////////////////////////////////////
            if(isAntennaStop(pantennaspec)==false){ //这里判断antennaspec是否满足停止条件
                m_TagObTryCount++; //执行AntennaSpec次数自增
                //printf("a4..........................\n");
                //遍历CRfSpec列表，依次执行RfSpec，至所有RfSpec执行一次
                //for(list<CRfSpec *>::iterator rfspec_it=pantennaspec->beginRfSpec();
                //    rfspec_it!=pantennaspec->endRfSpec();rfspec_it++){
                    //printf("a5..........................\n");
                    CRfSpec * prfspec = *RfSpec_It;
                    if(prfspec==NULL){
                        printf("prfspec is NULL......!\n");
                    }
#ifndef SIM_EXEC_MODE
                    this->m_pRfOper->setAntCFG(pantennaspec,prfspec);
#endif
                    if(this->m_OpResults.size()<resualt_num){
                        if(m_pExecSelectSpec->tagAccessSpecs.size()>0){//有相应AccessSpec
                            //for(int i=0;i<m_pExecSelectSpec->tagAccessSpecs.size();i++){//遍历当前select下的所有AccessSpec，对处于Active状态的Access逐一执行
                                Tag_AccessSpec *ptagaccess = m_pExecSelectSpec->tagAccessSpecs.at(accessSpecIndex);
                                if(ptagaccess->isValid&&ptagaccess->getAccessSpec()->getAccessCurrentState()==AccessCurrentState_Active){

                                    if(singleSelectAccess(m_pExecSelectSpec,ptagaccess,pantennaspec,antSpecIndex,prfspec)){
																			accessSpecIndex = (accessSpecIndex+1)%m_pExecSelectSpec->tagAccessSpecs.size();																		
																			if(accessSpecIndex==0){//accessSpecIndex回到初始值，则表示AccessSpec规则已执行完,则开始执行下一条RfSpec
																				RfSpec_It++;
																				if(RfSpec_It==pantennaspec->endRfSpec()){ //所有RfSpec执行完，回到初始值
																						RfSpec_It = pantennaspec->beginRfSpec();
																				}
																			}
																		}

                                }
                            //}
                        }else{//无AccesSpec
                            accessSpecIndex = 0;	
                            if(singleSelectAccess(m_pExecSelectSpec,NULL,pantennaspec,antSpecIndex,prfspec)){
															RfSpec_It++;
															if(RfSpec_It==pantennaspec->endRfSpec()){ //所有RfSpec执行完，回到初始值
																	RfSpec_It = pantennaspec->beginRfSpec();
//																antSpec_It++;
//																if(antSpec_It!=pselectspec->endAntennaSpec()){ //antspec未执行完
//																	RfSpec_It = (*antSpec_It)->beginRfSpec(); //指向下一条antspec的起始
//																}else{ //antspec执行完，再回到初始值
//																	antSpec_It = pselectspec->beginAntennaSpec();
//																}
															}
														}
                            //printf("b1........................................\n");
                        }
                    }
                //}//end of for list<CRfSpec *>
            }//end of if
						else{
							antSpec_It++;
							antSpecIndex++;
							if(antSpec_It!=pselectspec->endAntennaSpec()){ //antspec未执行完
								RfSpec_It = (*antSpec_It)->beginRfSpec(); //指向下一条antspec的起始
							}else{ //antspec执行完，再回到初始值，同时标记SelectSpec已执行完
								antSpec_It = pselectspec->beginAntennaSpec();
								antSpecIndex = 0;
								m_pExecSelectSpec->isSelectSpecFinish = true; //标记SelectSpec规则执行完一次
							}
						}
            
        //}//end of for list<TagAntennaSpec*>

        
    }//end of if
		else{
        printf("end select spec........................******************************\n");
        endSelectSpec();			
		}

}

/**
 * 开始执行SelectSpec的方法
 * 标签数据的返回在另一方法中实现
 * @brief OperationSpec_Execute_Base::startSelectSpec
 * @param pSpec
 */
void OperationSpec_Execute_Base::startSelectSpec(Tag_SelectSpec *pSpec){


#ifndef SIM_EXEC_MODE
    printf("OperationSpec_Execute_New:startSelectSpec!\n");
    //开始select前，停止可能没结束的射频操作，并读取以清除安全模块内的缓存数据
    this->forceExitExecute = false;
    m_pRfOper->stopRfOper();    //需要改写
    m_pRfOper->resetAA();
    m_pRfOper->resetCurrentSpec();
    m_pRfOper->initAntSwitch();
    //printf("B1..................\n");


    //强制清除上一次没有完成上传的读卡数据
    while(!m_OpResults.empty()){
        OpspecResult *p = m_OpResults.front();
				//打印监控上报时的内存
				printf("----------size:%d---------------p:0X%8X\n",m_OpResults.size(),(unsigned int)p);				
        delete p;
        m_OpResults.pop();
		
    }
#endif

    m_pExecSelectSpec = pSpec;
    //printf("m_pExecSelectSpec->retain()\n");
    m_pExecSelectSpec->retain();

		//开始前初始化执行规则相关的变量
		pSpec->specStartUTC = General_Functions::getCurrentUTC();
		antSpecIndex = 0;
		accessSpecIndex = 0;
		
		if(pSpec->getSelectSpec()->beginAntennaSpec()!=pSpec->getSelectSpec()->endAntennaSpec()){
			antSpec_It = pSpec->getSelectSpec()->beginAntennaSpec();
			CAntennaSpec *pantspec = *antSpec_It;
			if(pantspec->beginRfSpec()!=pantspec->endRfSpec()){
				RfSpec_It = pantspec->beginRfSpec();
			}
		}
		pSpec->isSelectSpecFinish = false;
    printf("start select success.............................\n");
//		m_SelectStep = 0; //重置读卡步骤为0	
		KEY_TYPE = read_start;
    isIdle = false;
		
}

/**
 * @brief OperationSpec_Execute_Base::endSelectSpec
 * 结束规则的执行。          
 */
void OperationSpec_Execute_Base::endSelectSpec(){

    //2017.12.25日新加，根据当前规则触发方式改变规则状态
    if(this->forceExitExecute==false){ //非强制性退出，即正常退出，则更新规则状态。
        if(m_pExecSelectSpec->getSelectSpec()->getSelectSpecStartTrigger()->getSelectSpecStartTriggerType()==SelectSpecStartTriggerType_Immediately){

            m_pExecSelectSpec->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Disabled);
        }else{ //其它触发方式
            if(m_pExecSelectSpec->getSelectSpec()->getSelectCurrentState()==SelectCurrentState_Active){
                m_pExecSelectSpec->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Inactive);
            }
        }
   }

    //关闭射频操作
    //释放一次规则
    //printf("m_pExecSelectSpec->release()\n");
    m_pExecSelectSpec->release();
    //置为空闲
    isIdle = true;

#ifndef SIM_EXEC_MODE
    //通知射频结束操作
    printf("Select action is stoped!...........................\n");
    m_pRfOper->stopRfOper();

    ////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////

    //printf("\nreadcount=%d!\n",readcount);
    //操作结束后，应强制清除可能未处理的数据。即直接放弃未及时处理成报告的数据(多分区时会导致读卡规则一直被占用不能释放)
    //清除未处理的帧缓存
    Delay_ms(1000); //休眠一秒以保证缓存区内的数据尽量上传。尤其是在单次读时，作用明显。
    while(m_OpResults.size()>0){
        printf("delete popresult\n");
        OpspecResult *popresult = this->frontOpResult();
        this->popOpResult();
        delete popresult;
    }
    //再把临时缓冲区内的数据清空
    g_pMainApplication->getOpProcess()->getOpReportManager()->clearTempOpResults();
    //printf("end of while\n");

#endif
}

bool OperationSpec_Execute_Base::isSelectStop(){

    //2017.12.5日更改为按规范停止
    //printf("c0\n");
    if(m_pExecSelectSpec->isValid==false){
        //printf("c1\n");
        return true;
    }else{
        //printf("c2\n");
        if(m_pExecSelectSpec->getSelectSpec()->getSelectCurrentState()==SelectCurrentState_Active){
            //Active状态则查询停止条件是否满足
            CSelectSpecStopTrigger *pstoptrigger = m_pExecSelectSpec->getSelectSpec()->getSelectSpecStopTrigger();
            bool isstop = false;
            switch(pstoptrigger->getSelectSpecStopTriggerType()){
            case SelectSpecStopTriggerType_Unconditional://无触发条件，当规则执行完毕，即结束。
                //printf("SelectSpecStopTriggerType_Unconditional\n");
                if(m_pExecSelectSpec->isSelectSpecFinish==true){
                    //printf("b0\n");
                    isstop = true;
                }else{
                    //printf("b1\n");
                    isstop = false;
                }
                break;
            case SelectSpecStopTriggerType_Persistent://持续执行或当前规则执行完毕，即结束
            {
                llrp_u32_t durationvalue = pstoptrigger->getDurationValue();
                llrp_u64_t startutc = m_pExecSelectSpec->specStartUTC;
                llrp_u64_t currentutc = General_Functions::getCurrentUTC();
                if(currentutc-startutc>=durationvalue*1000){
                    //printf("Select spec **************************************over!\n");
                    isstop = true;
                }else if(m_pExecSelectSpec->isSelectSpecFinish==true){
                    isstop = true;
					//KeyFuncIndex = 0;
                }else{
                    isstop = false;
                }
            }
                break;
            case SelectSpecStopTriggerType_GPI: //GPI触发，设备不支持GPI，故等同无触发条件处理
                if(KEY_TYPE==TRIG_UP){ //松手检测 停止
									//删除上位机下发的读卡规则和停止自身
	//							 this->deleteSelectSpec(1);
								//deleteSelectSpec();	
								isstop = true;
					   // KeyFuncIndex = 17;
				}else{
						isstop = false;
					 }
                break;
            }
           // printf("isstop .........=%d\n",isstop);
            return isstop;
        }else{//非Active状态返回真
            //printf("c2\n");
            return true;
        }
    }
}

/**
 * @brief OperationSpec_Execute_Base::isAntennaStop
 * @return
 * 判断antennaspec是否停止
 */
bool OperationSpec_Execute_Base::isAntennaStop(CAntennaSpec *pAntennaSpec){

    CAntennaSpecStopTrigger *pantstoptrg = pAntennaSpec->getAntennaSpecStopTrigger();
    llrp_u8_t stoptype = pantstoptrg->getAntennaSpecStopTriggerType();
    bool isstop = false;
    switch(stoptype){
    case AntennaSpecStopTriggerType_SelectSpecStop://无触发条件，当SelectSpec停止时停止
        isstop = false;
        break;
    case AntennaSpecStopTriggerType_Persistent://按持续时间停止
     {
        llrp_u32_t durationvalue = pantstoptrg->getDurationValue();
        llrp_u64_t currentutc = General_Functions::getCurrentUTC();
        if(currentutc-m_AntennaStartUTC>=durationvalue*1000){
            isstop = true;
        }else{
            isstop = false;
        }
    }
        break;
    case AntennaSpecStopTriggerType_GPI://GPI触发停止，因设备无此功能，直接返回真
        isstop = true;
        break;
    case AntennaSpecStopTriggerType_LabelRule://按标签触发规则停止。
    {
        CTagObservationTrigger *ptagobtrg = pantstoptrg->getTagObservationTrigger();
        if(ptagobtrg!=NULL){
            llrp_u8_t tagtrgtype = ptagobtrg->getTriggerType();
            switch(tagtrgtype){
            case TriggerType_NLabels://标签个数达到，或超时
            {
                llrp_u16_t n = ptagobtrg->getNumberOfTags();
                if(m_TagObTagNCount>=n){
                    isstop = true;
                }else{
                    llrp_u32_t timeout = ptagobtrg->getTimeout();
                    llrp_u64_t currentutc = General_Functions::getCurrentUTC();
                    if(currentutc-m_TagObTrgStartUTC>=timeout*1000&&timeout!=0){
                        isstop = true;
                    }else{
                        isstop = false;
                    }
                }
            }
                break;
            case TriggerType_TMilliseconds://在规定毫秒数内或超时时间内没有清点到更多标签则停止
            {
                llrp_u16_t t = ptagobtrg->getTValue();
                llrp_u64_t currentutc = General_Functions::getCurrentUTC();
                //printf(".........................t=%d......................................\n",t);
                if(currentutc-m_TagObTLastUTC>=t*1000){
                    //printf("a0....................\n");
                    isstop = true;
                }else{
                    llrp_u32_t timeout = ptagobtrg->getTimeout();
                    if(currentutc-m_TagObTrgStartUTC>=timeout*1000&&timeout!=0){//超时则结束，如超时时间为0则表示无超时设定
                        //printf("a1....................\n");
                        isstop = true;
                    }else{
                        //printf("a2....................\n");
                        isstop = false;
                    }
                }
            }
                break;
            case TriggerType_ATimes://尝试规定次数以发现所有标签，实际理解为A次AntennaSpec操作
            {
                llrp_u16_t a = ptagobtrg->getNumberOfAttempts();
                //printf("a=%d,m_TagObTryCount=%d\n",a,m_TagObTryCount);
                if(m_TagObTryCount>=a){
                    isstop = true;
                }else{
                    llrp_u32_t timeout = ptagobtrg->getTimeout();
                    llrp_u64_t currentutc = General_Functions::getCurrentUTC();
                    if(currentutc-m_TagObTrgStartUTC>=timeout*1000&&timeout!=0){
                        isstop = true;
                    }else{
                        isstop = false;
                    }
                }
            }
                break;
            }
        }else{ //无触发规则，返回假
            isstop = true;
        }
    }
        break;
    default:
        return true;
    }
    //printf("is antennaspec stop is %d\n",isstop);
    return isstop;
}

/**
 * @brief OperationSpec_Execute_Base::updateSelectSpecState
 * @param pTagSelectSpec
 * 更新SelectSpec状态
 */
void OperationSpec_Execute_Base::updateSelectSpecState(Tag_SelectSpec *pTagSelectSpec){

}

/**
 * @brief OperationSpec_Execute_Base::updateAccessSpecState
 * @param pTagAccessSpec
 * 更新AccessSpec状态
 */
void OperationSpec_Execute_Base::updateAccessSpecState(Tag_AccessSpec *pTagAccessSpec){

}

vector<OpspecResult*>*  OperationSpec_Execute_Base::genSelectResult(STRUCT_M2SEC_FRAME *pframe,Tag_SelectSpec *pTagSelectSpec){
    if(pframe==NULL){
        return  NULL;
    }

    //注：这里的 select只可能有一条，为统一处理方便，也用vector存贮
    vector<OpspecResult *> *pselectresults = new vector<OpspecResult *>();

    //放入Select结果
    OpspecResult *popres = new OpspecResult();
    popres->pOpResultFrame = pframe;
    popres->setOpParams(pTagSelectSpec,NULL,NULL);
    pselectresults->push_back(popres);

    return pselectresults;
}

void  OperationSpec_Execute_Base::genAccessResult(STRUCT_M2SEC_FRAME *pframe,Tag_SelectSpec *pTagSelectSpec,CParameter *popspec,vector<OpspecResult*>* pAccessResult ){

    //放入Access结果
    OpspecResult *popres = new OpspecResult();
    popres->pOpResultFrame = pframe; //注意，这里有可能是空
    popres->setOpParams(pTagSelectSpec,popspec);
    pAccessResult->push_back(popres);
}

STRUCT_M2SEC_FRAME *OperationSpec_Execute_Base::getSimFrame(){
    unsigned char simbuf[] = {0xab,0x52,0x60,0x00,0x03,0x00,0xe8,0x99,0x00,0x02,0x58,0x30,0xbf,0xb6,
                              0x09,0xad,0xd9,0x1c,0xb5,0xc4,0x01,0x00,0x00,0x01,0x88,0x05,0x00,0x03,0x00,0x00,
                              0x40,0x08,0x02,0x88,0x02,0x00,0x13,0x01,0x03,0x88,0x01,0x00,0x04,0x04,0x88,0x02,
                              0x00,0x35,0x01,0x05,0x88,0x02,0x00,0x91,0x00,0x08,0x88,0x01,0x00,0x01,0x09,0x88,
                              0x05,0x00,0x1a,0x1b,0x00,0x00,0x02,0x0a,0x88,0x02,0x00,0x2e,0x00,0x0b,0x88,0x01,
                              0x00,0x0e,0x0c,0x88,0x02,0x00,0x45,0x00,0x0d,0x88,0x01,0x00,0x00,0x06,0x88,0x01,
                              0x00,0x3c,0x00,0x00,0xd4,0xe4,0xa4};
	
//    unsigned char simbuf[] = {0xab,0x52,0x27,0x00,0x02,0x04,0xe8,0x81,0x00,0x01,0x30,0x4c,0xc3,0xa6,
//                              0x08,0x67,0x83,0x20,0xb5,0xc4,0x01,0x00,0x00,0x37,0x44,0x25,0x2a,0xec,0xe7,0xfe,
//                              0xaa,0xbd,0x44,0x62,0x5a,0xf3,0x60,0x4e,0xb0,0xe5,0x81,0x29,0x54,0x28,
//														  };

    STRUCT_M2SEC_FRAME *pframe = m_pMCUToSecureComm->getFrameFromBuf(simbuf,sizeof(simbuf));
		return pframe;
}

/**
 * @brief OperationSpec_Execute_Base::simexecSelectSpec
 * 为调试而添加的虚拟执行方法，仅会产生虚拟的数据
 */

//void OperationSpec_Execute_Base::simexecSelectSpec(){
//    unsigned char simbuf[] = {0xab,0x52,0x60,0x00,0x03,0x00,0xe8,0x99,0x00,0x02,0x58,0x30,0xbf,0xb6,
//                              0x09,0xad,0xd9,0x1c,0xb5,0xc4,0x01,0x00,0x00,0x01,0x88,0x05,0x00,0x03,0x00,0x00,
//                              0x40,0x08,0x02,0x88,0x02,0x00,0x13,0x01,0x03,0x88,0x01,0x00,0x04,0x04,0x88,0x02,
//                              0x00,0x35,0x01,0x05,0x88,0x02,0x00,0x91,0x00,0x08,0x88,0x01,0x00,0x01,0x09,0x88,
//                              0x05,0x00,0x1a,0x1b,0x00,0x00,0x02,0x0a,0x88,0x02,0x00,0x2e,0x00,0x0b,0x88,0x01,
//                              0x00,0x0e,0x0c,0x88,0x02,0x00,0x45,0x00,0x0d,0x88,0x01,0x00,0x00,0x06,0x88,0x01,
//                              0x00,0x3c,0x00,0x00,0xd4,0xe4,0xa4};
//    isIdle = false;
//    while(m_pExecSelectSpec->isValid==true&&m_pExecSelectSpec->getSelectSpec()->getSelectCurrentState()==SelectCurrentState_Active){
//        if(this->m_OpResults.size()<=100){
//            //printf("a0..........................\n");
//            OpspecResult *popresult = new OpspecResult();
//            STRUCT_M2SEC_FRAME *pframe = m_pMCUToSecureComm->getFrameFromBuf(simbuf,sizeof(simbuf));
//            popresult->pOpResultFrame = pframe;
//            //printf("a1..........................\n");
//            popresult->setOpParams(m_pExecSelectSpec);
//            this->pushOpResult(popresult);
//            //printf("a3..........................\n");
//            //printf("m_OpResults.size=%d.................\n",m_OpResults.size());
//        }
//        usleep(10000);
//    }
//    if(m_pExecSelectSpec->isValid==false){
//        printf("spec is invalid!..........\n");
//    }else if(m_pExecSelectSpec->getSelectSpec()->getSelectCurrentState()!=SelectCurrentState_Active){
//        printf("getSelectCurrentState()=%d\n",m_pExecSelectSpec->getSelectSpec()->getSelectCurrentState());
//    }

//}


void OperationSpec_Execute_Base::run(){
    //printf("OperationSpec_Execute_Base:run.....\n");
    if(isIdle==false){

        this->execSelectSpec();

    }else{
        //Delay_ms(100);
    }
}

/**
 * @brief OperationSpec_Execute_Base::pushOpResult
 * @param pOpResult
 * 线程安全的进队列方法
 */
void OperationSpec_Execute_Base::pushOpResult(OpspecResult *pOpResult){

		m_OpResults.push(pOpResult);

}

 void OperationSpec_Execute_Base::pushSelectAccessResult(Tag_SelectAccessResult *pSelectAccessResult){
     //printf("0:selectaccessresultes size =%d\n",m_SelectAccessResults.size());
     if(m_SelectAccessResults.size()>resualt_num){
         return;
     }
     
     m_SelectAccessResults.push(pSelectAccessResult);

 }

/**
 * @brief OperationSpec_Execute_Base::frontOpResult
 * @return
 * 线程安全的取队列首元素方法。
 */
OpspecResult* OperationSpec_Execute_Base::frontOpResult(){
    OpspecResult *popresult = NULL;
    
    popresult = m_OpResults.front();
    
    return popresult;
 }

/**
 * @brief OperationSpec_Execute_Base::popOpResult
 * 线程安全的删除队列首元素方法，但对象内存并没有被删除
 */
void OperationSpec_Execute_Base::popOpResult(){
   
    m_OpResults.pop();
    
}

Tag_SelectAccessResult* OperationSpec_Execute_Base::frontSelectAccessResult(){
    Tag_SelectAccessResult *presult = NULL;
    
    presult = m_SelectAccessResults.front();
    
    return presult;
}

void OperationSpec_Execute_Base::popSelectAccessResult(){
    
    m_SelectAccessResults.pop();
    
}

