#include "rf_manager.h"
#include "systick.h"
#include "adc_dac.h"
#include "rf_oper.h"
#include "cancellation.h"
Rf_Manager::Rf_Manager()
{
    m_pRfOper = NULL;
}

/**
 * @brief Rf_Manager::dealMessage
 * @param pMessage
 * @param commID
 * @return
 * 处理射频管理消息
 */
int Rf_Manager::dealMessage(CMessage *pMessage,Base_Comm *pComm){
		llrp_u32_t messageid = pMessage->getMessageID();
    if(pMessage->m_pType->m_TypeNum!=ManufacturerCommand){
        return -1;
    }
    CManufacturerCommand *pcommd = (CManufacturerCommand*)pMessage;
    llrp_u8v_t bytes = pcommd->getByteStream();
    printf("bytes is ");
    for(int i=0;i<bytes.m_nValue;i++){
        printf("0x%02x,",bytes.m_pValue[i]);
    }
    printf("\n");

    STRUCT_ManufacturerFrame manuframe;
    manuframe.OperID = bytes.m_pValue[0];
    manuframe.Datalen_H = bytes.m_pValue[1];
    manuframe.Datalen_L = bytes.m_pValue[2];
    manuframe.DataBuf = bytes.m_pValue+3;

    CManufacturerReport *preportmessage =  (CManufacturerReport *)ExtendHbFrame_Operation::genMessage(ManufacturerReport,0);
    switch(manuframe.OperID){
    case 0x80: //开始定标
    case 0x81: //结束定标
    case 0x82://功率微调
    {
//        llrp_u8v_t bytes = m_pRfOper->RfPowerCalibration(&manuframe); //注意这里会根据不同的射频版本做不同的定标处理
//        if(bytes.m_nValue==0){
//            printf("powercalibration fail!\n");
//        }else{
//            printf("powercalibration success!\n");
//        }
//        preportmessage->setByteStream(bytes);
    }
        break;
    case 0x83: //读取定标数据
    {
//        llrp_u8v_t bytes = m_pRfOper->getPowerCalibrationBytes();
//        preportmessage->setByteStream(bytes);
    }
        break;
    case 0x84: //手动对消
    {
			//先退出低功耗

        //开始射频操作
			  RFPowerON(0);	
			  Cancellation();
//				//开启前先关再开单载波
//			  m_pRfOper->switchCarrier(4,0x00,0);
//			  Delay_ms(100);
//		   	  m_pRfOper->switchCarrier(4,0x00,1);	
//			
//			  
//			  //关闭单载波
//			  m_pRfOper->switchCarrier(4,0x00,0);	

				llrp_u8v_t bytes = llrp_u8v_t(5);   //响应
				bytes.m_pValue[0] = 0x04;  					//操作标识
				bytes.m_pValue[1] = 0x00;           //帧长度
				bytes.m_pValue[2] = 0x02;           //帧长度
				bytes.m_pValue[3] = 0x04; 			    //帧内容	天线号
			  bytes.m_pValue[4] = 0x00;             // 0表示成功。1表示失败。
				preportmessage->setByteStream(bytes);
			  if(preportmessage!=NULL){
					pComm->immediateSendMessage(preportmessage,pMessage->getMessageID());

					//delete preportmessage;
				}
    }
        break;
    case 0x85://开启关闭单载波
    {
        llrp_u8v_t bytes = llrp_u8v_t(7);
        bytes.m_pValue[0] = 0x05;
        bytes.m_pValue[1] = 0x04;
        bytes.m_pValue[2] = 0x00;
        bytes.m_pValue[3] = manuframe.DataBuf[0];
        bytes.m_pValue[4] = manuframe.DataBuf[1];
        bytes.m_pValue[5] = manuframe.DataBuf[2];
        if(manuframe.DataBuf[2]==0){//关					
//            if(m_pRfOper->switchCarrier(manuframe.DataBuf[0],manuframe.DataBuf[1],0)){
//                bytes.m_pValue[6] = 0;
//            }else{
//                bytes.m_pValue[6] = 1;
//            }
						RFPowerON(0);	
					  bytes.m_pValue[6] = 0;
        }else{//开
            //2017-03-21新加，开启载波前，先关一次，以确保成功开闭
//            m_pRfOper->switchCarrier(manuframe.DataBuf[0],manuframe.DataBuf[1],0);
//            Delay_ms(100);
//            if(m_pRfOper->switchCarrier(manuframe.DataBuf[0],manuframe.DataBuf[1],1)){
//                bytes.m_pValue[6] = 0;
//            }else{
//                bytes.m_pValue[6] = 1;
//            }
						RFPowerOFF();
						bytes.m_pValue[6] = 0;
						
        }
        preportmessage->setByteStream(bytes);
    }
        break;
    case 0x88://查询泄漏对消状态
    {		
//        string statestr = m_pRfOper->convertADDataToString();
//        int len = statestr.length();
//        llrp_u8v_t bytes = llrp_u8v_t(statestr.length()+3);
//        bytes.m_pValue[0] = 0x08;
//        bytes.m_pValue[1] = len;
//        bytes.m_pValue[2] = len>>8;
//        memcpy(bytes.m_pValue+3,statestr.c_str(),statestr.length());
//        preportmessage->setByteStream(bytes);
    }
        break;
    case 0x8A://2016-11-14新加漫速对消
    {
			//开启前先关再开单载波
//			  m_pRfOper->switchCarrier(4,0x00,0);
//			  Delay_ms(100);
//		   	  m_pRfOper->switchCarrier(4,0x00,1);	
//			
//			//	Cancellation00(); //对消
//			  
//			  //关闭单载波
//			  m_pRfOper->switchCarrier(4,0x00,0);	
    }
        break;
    default:
        return -1;
    }//end of switch();
    if(preportmessage!=NULL){
				if(!pComm->immediateSendMessage(preportmessage,messageid)){
            printf("Send rf mananger message fail!\n");
        }
    }
    delete preportmessage;
    return 0;
}

void Rf_Manager::run(){
	
}
