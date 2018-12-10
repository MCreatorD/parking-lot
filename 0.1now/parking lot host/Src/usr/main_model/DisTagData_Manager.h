#ifndef _DISTAGDATA_MANAGER_H_
#define _DISTAGDATA_MANAGER_H_

#include "hbframe_operation.h"

#include "CarMsgCompare.h"


#define UTC_TIME         0
#define VEHICLE_NUMBER   1
#define CID_INFO         2
#define SYXZ_INFO        3
#define CCRQ_INFO		 4
#define CLLX_INFO		 5
#define PL_INFO			 6
#define GL_INFO			 7
#define HPZL_INFO        8
#define JYYXQ_INFO       9
#define QZBFQ_INFO       10
#define CSYS_INFO        11
#define ZKZL_INFO		 12

//extern char Car_num[9];

class DisTagData_Manager{
	
	public:
		DisTagData_Manager();
	
	private:
		//�������鰴˳��ֱ��ʾ
		//ʱ�䣬���ƺţ�CID�ţ�ʹ�����ʣ��������ڣ��������ͣ����������ʣ��������࣬������Ч��
		//ǿ�Ʊ����ڣ�������ɫ���ؿ�������
		unsigned char m_NeedUpdates[20];
		
	
		string m_DisContents[20];
		llrp_u8v_t m_CurrentTID;
		
		CarMsgCompare *m_pCarMsg;
	
	private:
		void setDataInfo(CReadDataInfo *pDataInfo);
	public:
		void setDisTagData(CTagSelectAccessReport *pReport);
	
};

#endif 