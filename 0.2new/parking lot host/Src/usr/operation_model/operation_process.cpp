#include "operation_process.h"
#include <stdio.h>

#include "general_functions.h"
#include "systick.h"
#include "key_exit.h"
#include "main.h"
Operation_Process::Operation_Process()
{
    printf("read all persis spec .............................\n");
    vector<CAddSelectSpec*> addselectspecs = m_pOpSpecManager->readAllPersisSelect();
    vector<CAddAccessSpec*> addaccessspecs = m_pOpSpecManager->readAllPersisAccess();
    printf("read all persis spec end .............................\n");
    ////////////////////////////////////////////////////////////////////////
    m_pOpSpecManager = new OperationSpec_Manager();
    m_pOpReportManager = new OperationReport_Manager();

    this->initOperationExecute();
    m_pOpReportManager->setOpExec(m_pOpspecExecute);

    //添加读出的持久化的规则，无顺序要求
    for(int i=0;i<addselectspecs.size();i++){
        m_pOpSpecManager->addSelectSpec(addselectspecs.at(i),false);
    }
    for(int i=0;i<addaccessspecs.size();i++){
        m_pOpSpecManager->addAccessSpec(addaccessspecs.at(i),false);
    }

}

Operation_Process::~Operation_Process(){
    delete m_pOpReportManager;
}

void Operation_Process::initOperationExecute(){
		//m_pOpspecExecute = new OperationSpec_Execute_Base();
		if(RF_USE_GBFPGA){
			m_pOpspecExecute = (OperationSpec_Execute_Base *)(new Operationspec_Execute_GB());
		}else if(RF_USE_HBFPGA){
			m_pOpspecExecute = (OperationSpec_Execute_Base *)(new OperationSpec_Execute_HB());
		}
}

int Operation_Process::dealMessage(CMessage *pMessage,Base_Comm *pComm){
    llrp_u32_t messageid = pMessage->getMessageID();
    llrp_u64_t messagedevsn = pMessage->getDeviceSN(); //取出命令消息的deviceSN,新规范中，可能会要求只对和设备SN一致的消息响应。
    CMessage *pack = NULL;
    CParameter *pstatus = NULL;

    pstatus = HbFrame_Operation::genParam(Status,0,NULL);

    //printf("Operation_Process:message name is %s\n",pMessage->m_pType->m_pName);
    switch(pMessage->m_pType->m_TypeNum){
    case AddSelectSpec:
			
        if(m_pOpSpecManager->addSelectSpec((CAddSelectSpec*)pMessage,true)==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
         pack = HbFrame_Operation::genMessage(AddSelectSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case DeleteSelectSpec:
        if(m_pOpSpecManager->deleteSelectSpec(((CDeleteSelectSpec*)pMessage)->getSelectSpecID())==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
         pack = HbFrame_Operation::genMessage(DeleteSelectSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case DisableSelectSpec:
        if(m_pOpSpecManager->disableSelectSpec(((CDisableSelectSpec*)pMessage)->getSelectSpecID())==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
         pack = HbFrame_Operation::genMessage(DisableSelectSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case EnableSelectSpec:
        if(m_pOpSpecManager->enableSelectSpec(((CEnableSelectSpec*)pMessage)->getSelectSpecID())==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
         pack = HbFrame_Operation::genMessage(EnableSelectSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case StartSelectSpec:
        if(m_pOpSpecManager->startSelectSpec(((CStartSelectSpec*)pMessage)->getSelectSpecID())==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
        pack = HbFrame_Operation::genMessage(StartSelectSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case StopSelectSpec:
        if(m_pOpSpecManager->stopSelectSpec(((CStopSelectSpec*)pMessage)->getSelectSpecID())==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
         pack = HbFrame_Operation::genMessage(StopSelectSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case AddAccessSpec:
        if(m_pOpSpecManager->addAccessSpec((CAddAccessSpec*)pMessage,true)==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
        pack = HbFrame_Operation::genMessage(AddAccessSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case DeleteAccessSpec:
        if(m_pOpSpecManager->deleteAccessSpec(((CDeleteAccessSpec*)pMessage)->getAccessSpecID())==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
            //printf("a0...............\n");
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
            //printf("a1...............\n");
        }
        pack = HbFrame_Operation::genMessage(DeleteAccessSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case DisableAccessSpec:
        if(m_pOpSpecManager->disableAccessSpec(((CDisableAccessSpec*)pMessage)->getAccessSpecID())==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
        pack = HbFrame_Operation::genMessage(DisableAccessSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case EnableAccessSpec:
        if(m_pOpSpecManager->enableAccessSpec(((CEnableAccessSpec*)pMessage)->getAccessSpecID())==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
        pack = HbFrame_Operation::genMessage(EnableAccessSpecAck,messageid);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        break;
    case GetSelectSpec:
    {
        pack = HbFrame_Operation::genMessage(GetSelectSpecAck,messageid);
        vector<CSelectSpec*> specs = m_pOpSpecManager->getSelectSpecs();
        for(int i=0;i<specs.size();i++){
            ((CGetSelectSpecAck*)pack)->addSelectSpec(specs.at(i));
        }
        ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success); //这里认为总是可以查询成功。
        HbFrame_Operation::addParamToMessage(pstatus,pack);
     }
        break;
    case GetAccessSpec:
    {
        pack = HbFrame_Operation::genMessage(GetAccessSpecAck,messageid);
        vector<CAccessSpec*> specs = m_pOpSpecManager->getAccessSpecs();
        for(int i=0;i<specs.size();i++){
            ((CGetAccessSpecAck*)pack)->addAccessSpec(specs.at(i));
        }
        ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success); //这里认为总是可以查询成功。
        HbFrame_Operation::addParamToMessage(pstatus,pack);
     }
        break;
    default:
        break;
    }
		
		if(pack!=NULL){
			if(!pComm->immediateSendMessage(pack)){
					printf("------------Send operat spec ack fail!----------------\n");
					//wangchun
			}else{
					printf("------------Send operat spec ack success----------------!\n");
			}
			
			delete pack;
			//Delay_ms(100);
			return 0;
		}else{
			return -1;
		}
    
}

void Operation_Process::run(){

    //执行单元空闲时，执行规则
    if(m_pOpspecExecute->isExecIdle()==true){
        //printf("b0......................\n");
        Tag_SelectSpec *ptagselect = m_pOpSpecManager->nextTagSelectSpec();

        if(ptagselect!=NULL){
            //printf("spec id = %d\n",ptagselect->getSelectSpec()->getSelectSpecID());
            //printf("b1......................\n");
            if(ptagselect->isValid==true){
                //printf("b2......................\n");
                //如果当前是Disable装态，则不执行任当前select，指向下一次Select执行。
                if(ptagselect->getSelectSpec()->getSelectCurrentState()==SelectCurrentState_Disabled){
                    return;
                }
                // printf("b3......................\n");
                //根据启动条件判断是否改变相应规则的状态
                ESelectSpecStartTriggerType starttriggertype = ptagselect->getSelectSpec()->getSelectSpecStartTrigger()->getSelectSpecStartTriggerType();
                //printf("starttriggertype = %d\n",starttriggertype);
                switch(starttriggertype){
                case SelectSpecStartTriggerType_Unconditional:
                    //无条件，只能由上位机的startSelectSpec指令触发
                    break;
                case SelectSpecStartTriggerType_Immediately:
                    //立即触发，则收到AddSelectSpec后，立即执行
                    if(ptagselect->getSelectSpec()->getSelectCurrentState()!=SelectCurrentState_Active&&
                            ptagselect->getSelectSpec()->getSelectCurrentState()==SelectCurrentState_Inactive){
                        //printf("SelectCurrentState_Inactive\n");
                        ptagselect->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Active);
                    }
                    break;
                case SelectSpecStartTriggerType_Periodic:
                    //周期触发，按规范应等待offset后再触发，这里简化为立即触发
                    /*if(ptagselect->getSelectSpec()->getSelectCurrentState()!=SelectCurrentState_Active&&
                            ptagselect->getSelectSpec()->getSelectCurrentState()==SelectCurrentState_Inactive){
                        //printf("SelectCurrentState_Inactive\n");
                        ptagselect->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Active);
                    }*/
                    //2017.12.25日改为按规范进行周期触发模式。
                    if(ptagselect->getSelectSpec()->getSelectCurrentState()!=SelectCurrentState_Active&&
                            ptagselect->getSelectSpec()->getSelectCurrentState()==SelectCurrentState_Inactive){
                        //printf("SelectCurrentState_Inactive\n");
                        llrp_u64_t currentutc = General_Functions::getCurrentUTC();
                        CPeriodicTrigger *ppertrg = ptagselect->getSelectSpec()->getSelectSpecStartTrigger()->getPeriodicTrigger();
                        llrp_u32_t t = 10000; //默认10秒触发一次
                        if(ppertrg!=NULL){
                            t = ppertrg->getPeriod();
                        }
                        //printf("t=%d\n",t);
                        if(currentutc-ptagselect->periodTrgUTC>=t*1000){
                            //printf("................................period trg !...........................\n");
                            ptagselect->periodTrgUTC = General_Functions::getCurrentUTC();
                            ptagselect->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Active);
                        }

                    }
                    break;
                case SelectSpecStartTriggerType_GPI:
                    //监测GPI值，一旦满足要求设置为Active状态。因硬件无此功能，未做
                    //ptagselect->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Disabled);
										if(KEY_TYPE==TRIG_DOWN){
											//printf("KEY_TYPE==TRIG_DOWN............................\n");	
											ptagselect->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Active);
										}
										break;
                }
                //pselectspec->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Active); //这里暂时先简化为强制有效，实际应该根据开始条件来判断是否启动
                //printf("b4......................\n");
                if(ptagselect->getSelectSpec()->getSelectCurrentState()==SelectCurrentState_Active){
                    printf("start select spec............................................\n");
                    m_pOpspecExecute->startSelectSpec(ptagselect);
                }
           }
        }else{
           // printf("select spec is NULL.....................\n");
        }
    }

    //调用清除无效规则的方法以清除无效规则
    m_pOpSpecManager->releaseInvalidSpecs();
		
		///////////////////////////////////////////////////////
		this->m_pOpspecExecute->run();
		this->m_pOpReportManager->run();

}

