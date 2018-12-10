#ifndef RF_MANAGER_H
#define RF_MANAGER_H

#include <functional>
using namespace std;

#include "HbFrame_Operation.h"
#include "ExtendHbFrame_Operation.h"
#include "rf_oper_base.h"
#include "model_base.h"

#include "systick.h"
/**
 * @brief The Rf_Manager class
 * by lijin,2017.04.07
 * 用于管理射频相关配置，模式等
 */

class Rf_Manager:public Model_Base
{
public:
    Rf_Manager();
private:
    Rf_Oper_Base *m_pRfOper;


public:
    inline void setRfOper(Rf_Oper_Base *pRfOper){

			m_pRfOper = pRfOper;
			
	

    }
		
public:

    int dealMessage(CMessage *pMessage,Base_Comm *pComm); 
public:
    void run(); 

};

#endif // RF_MANAGER_H
