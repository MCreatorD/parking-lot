#include "OperationSpec_Execute_HB.h"
#include <stdio.h>

#include "systick.h"
#include "main_application.h"
#include "general_functions.h"

#include "buzzer_led.h"
#include "testReadTag.h"
#include "communication.h"
#include "rx485_rev.h"
//extern char m_SelectStep_temp;
OperationSpec_Execute_HB::OperationSpec_Execute_HB(){

	m_pHBRfOper = (Rf_Oper_HB *)m_pRfOper;
	m_pCurrentSelectAccessResult = NULL;
}

OperationSpec_Execute_HB::~OperationSpec_Execute_HB(){

}

/*
 * 新的读卡操作流程改为每轮操作都是由CPU发起。
 * 流程如下：
 * 根据SelectSpec和AccessSpec配置安全模块的工作参数，如Spec未变，则不重新配置
 * CPU通过SPI接口给FPGA配置本次射频操作的频道号，天线号参数
 * CPU发出开始本次射频操作的IO信号给FPGA
 * CPU循环等待FPGA本张标签读写操作结束的IO信号。
 * 等待期间反复监测安全模块是否有数据送出。有则读取。
 * 收到FPGA读写操作结束的信号后，跳出循环。并从安全模块读完所有可能还没读取的数据。
 * 完成上述操作后，根据当前的Select和Access规则，决定是否需要进行continue操作。
 * 如需进行continue操作，则返回循环等待FPGA读写操作结束阶段。
 * 如不需要，则向FPGA发出本张标签操作结束的IO信号。
 * 发出后，等待FPGA本轮操作结束的信号。如等待超时，则返回循环等待FPGA读写操作结束阶段。
 * 注：此时，就是让FPGA对读写区域内其它的多张标签进行操作。如FGPA检测到不再有新的标签需要操作，
 * 则会发出本轮操作结束的信号。
 * 如等到该信号后，则向FPGA发出结束射频操作的IO信号，通知FPGA结束本次射频操作。
 * //如一次singleselect执行完毕，则返回真，未执行完毕，返回假
 */

static unsigned int read_speed = 0;
static unsigned char first_pop = 0;
bool OperationSpec_Execute_HB::singleSelectAccess(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,CAntennaSpec *pAntennaSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec){

	unsigned char tmp_ack = 0;
	

	
	read_speed++;
	
	//开始读卡后转发数据
	switch(m_SelectStep){
		case 0://配置安全模块读卡模式
		{
			printf("--------CASE 0--------\n");
			///////////////////////////////////////////////////
			//配置安全模块及射频工作参数，如工作参数未变动，则不重新配
			m_pHBRfOper->setSelectAccessParam(pTagSelectSpec,pTagAccessSpec,antSpecIndex,pRfSpec);	
			m_SelectStep = 1; //进入下一步
			break;
		}
		case 1://开始读卡
		{
			  printf("--------CASE 1--------\n");
        //开始射频操作
				m_pHBRfOper->startRfOper();
				rfOper_OvertimerCount = 50;//超时设为100ms
				m_SelectStep = 2;		
			break;
		}
		case 2://处理等待一次读卡结束
		{
			//////////////////////////////////////////////////////////////////////////////
			//if(pTagSelectSpec->hasContinueOperation==false){ //无continue操作	
				if(g_pMainApplication->m_read_manage->current_dev != 0)//不是主节点才等待前端返回
				{
					tmp_ack = Device_end;//后修改成切换出去防止死等的尴尬迟钝
				}	
				else{
					tmp_ack = 1;//主机到第二步肯定是执行完了的
				}

        if(tmp_ack == 1)
				{//射频单元读卡结束
				    	g_pMainApplication->m_read_manage->current_dev_count++;
					    //操作结束，则从安全模块读取可能的数据。
							Device_end = tmp_ack = 0;
							m_SelectStep = 1; //进入下一次从开始读卡开始，读卡设备都是自动读完停止
							while(m_pHBRfOper->m_pM2SecComm->isSecReadyForComm())
							{
								STRUCT_M2SEC_FRAME *pframe = m_pHBRfOper->readTagData();								
								//printf("(pframe!=NULL) start ------- \n");
						    if(pframe!=NULL)
								{		
										//printf("0:read one frame!\n");
										//MCUToSecureComm::printfSecFrame(pframe);
										//this->m_TagObTagNCount++;	
										if(first_pop == 0)
										{
											first_pop = 1;
											read_speed = 0;
											OpspecResult *popresult = new OpspecResult();						
											popresult->pOpResultFrame = pframe;
											popresult->setOpParams(pTagSelectSpec);	
											
//											//记录当前读取到的标签信息时的天线号
//											popresult->operAntennaID = g_pMainApplication->m_read_manage->current_dev;
											this->pushOpResult(popresult);	
										  //打印监控上报时的内存
										//printf("----------size:%d---------------popresult:0X%8X\n",m_OpResults.size(),(unsigned int)popresult);	
											return true;											
										}
									
										MCUToSecureComm::removeFrame(pframe);
										//控制读卡速度
										if(read_speed < 20)
										{
											return false;
										}
									    read_speed = 0;
										  first_pop = 0;
										  return false;
//										OpspecResult *popresult = new OpspecResult();						
//										popresult->pOpResultFrame = pframe;
//										popresult->setOpParams(pTagSelectSpec);	
//										this->pushOpResult(popresult);	
//									  //打印监控上报时的内存
//								  	//printf("----------size:%d---------------popresult:0X%8X\n",m_OpResults.size(),(unsigned int)popresult);	
//										return true;										
								}
								//printf("(pframe!=NULL) end  ------- \n");
							}
							return false;											
				}	
				else//一直没有就使用超时
				{
					if(rfOper_OvertimerCount!=0)
						return false;									
					else{
							g_pMainApplication->m_read_manage->current_dev_count++;
							m_SelectStep = 1;										
							return false;	
					}					
				}					
			}	
	   	//}
			break;			
		}				
	return false;

}



void OperationSpec_Execute_HB::run(){
    OperationSpec_Execute_Base::run();
}


