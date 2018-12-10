#include "DisTagData_Manager.h"
#include "main_application.h"
#include "stdio.h"
#include "buzzer_led.h"
char Car_num[9] = "京A8888";

DisTagData_Manager::DisTagData_Manager(){
	
	m_pCarMsg = new CarMsgCompare();

}

void DisTagData_Manager::setDataInfo(CReadDataInfo *pDataInfo){
		static int dis_num = 1;
  			string current_contents[20];
				
				CFPDH* parafpdh = pDataInfo->getFPDH();   // 0x8802
				string vehicle_number;
        if(parafpdh != NULL)
        {
            string showdata = "";
            llrp_u8v_t fpdhdata = parafpdh->getFPDHData();
            char tmp[100] = {0};
            memcpy(tmp,(unsigned char *)fpdhdata.m_pValue,fpdhdata.m_nValue);
            char tmp_data[20] = {0};
            for(int i=0; i<fpdhdata.m_nValue; i++)
            {
                sprintf(tmp_data,"%02X",(unsigned char) tmp[i]);
                showdata += tmp_data;
                memset(tmp_data,0,sizeof(tmp_data));
            }

            unsigned char arg[2] = {0};
            arg[0] = fpdhdata.m_pValue[0];
            arg[1] = fpdhdata.m_pValue[1];

            string fpdh_info = m_pCarMsg->GetDealCode((char*)arg);
						
						vehicle_number = fpdh_info;

        }
				CHPHMXH* parahphmxh = pDataInfo->getHPHMXH(); //0x8809
        if(parahphmxh != NULL)
        {
            string showdata = "";
            llrp_u8v_t hphmxhdata = parahphmxh->getHPHMXHData();

            char tmp[100] = {0};
            memcpy(tmp,(unsigned char *)hphmxhdata.m_pValue,hphmxhdata.m_nValue);
            char tmp_data[20] = {0};
            for(int i=0; i<hphmxhdata.m_nValue; i++)
            {
                sprintf(tmp_data,"%02X",(unsigned char) tmp[i]);
                showdata += tmp_data;
                memset(tmp_data,0,sizeof(tmp_data));
            }

            unsigned char arg[10] = {0x00};
            for(int i = 0;i < hphmxhdata.m_nValue; i++)
            {
                arg[i] = hphmxhdata.m_pValue[i];

            }
            string hphmxh_info = m_pCarMsg->GetCarNum((char*)arg,hphmxhdata.m_nValue);
						vehicle_number = vehicle_number + hphmxh_info;
        }
				current_contents[VEHICLE_NUMBER] = vehicle_number;
				printf("vehicle_number is %s\n",vehicle_number.c_str());
	
				strcpy(Car_num,vehicle_number.c_str());
				
				for(int i=0;i<13;i++){
					if(m_DisContents[i]!=current_contents[i]){
						m_NeedUpdates[i] = 1;
					}else{
						m_NeedUpdates[i] = 0;
					}
				}			
}

void DisTagData_Manager::setDisTagData(CTagSelectAccessReport *pReport){
	memset(m_NeedUpdates,0,sizeof(m_NeedUpdates));
	for(list<CTagReportData*>::iterator it = pReport->beginTagReportData();
			it!=pReport->endTagReportData();it++){
			CTagReportData *ptagreportdata = *it;
			llrp_u8v_t tid = ptagreportdata->getTID();
			if(ptagreportdata->getSelectSpecResult()->m_pType->m_TypeNum == 517)  //校验517
			{
							printf("open TIM3 517\n");				
							TIM_Cmd(TIM3, ENABLE);//读卡结束打开闭定时器
							BUZZER_LED_H;	
							Delay_ms(50);
							BUZZER_LED_L;
			}
			//printf("ptagreportdata->getSelectSpecResult()->m_pType->m_TypeNum=%d\n",ptagreportdata->getSelectSpecResult()->m_pType->m_TypeNum);
			if(ptagreportdata->getSelectSpecResult()->m_pType->m_TypeNum+PARAM_BASE!=CustomizedSelectSpecResult){
				
				continue;
			}
			
			CCustomizedSelectSpecResult *pcustomresult = (CCustomizedSelectSpecResult*)ptagreportdata->getSelectSpecResult();
			if(pcustomresult->getReadDataInfo()==NULL){
				continue;
			}
			
			if(tid.m_nValue!=m_CurrentTID.m_nValue){
				memset(m_NeedUpdates,1,sizeof(m_NeedUpdates));
				//往各字段放入数据
				this->setDataInfo(pcustomresult->getReadDataInfo());
			}else if(memcmp(tid.m_pValue,m_CurrentTID.m_pValue,tid.m_nValue)!=0){
				memset(m_NeedUpdates,1,sizeof(m_NeedUpdates));
				//往各字段放入数据
				this->setDataInfo(pcustomresult->getReadDataInfo());
			}else{//tid相同，则只需更新时间
				//时间暂未做，故暂不更新数据
				memset(m_NeedUpdates,0,sizeof(m_NeedUpdates));
			}
	}
}