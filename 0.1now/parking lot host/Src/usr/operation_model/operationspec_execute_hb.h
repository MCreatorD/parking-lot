#ifndef OPERATIONSPEC_EXECUTE_HB_H
#define OPERATIONSPEC_EXECUTE_HB_H

#include "operationspec_execute_base.h"
#include "rf_oper_hb.h"

/**
 * The OperationSpec_Execute class
 * by lijin 2018.03.15
 * 行标操作规则类
*/

class OperationSpec_Execute_HB:public OperationSpec_Execute_Base
{
public:
    OperationSpec_Execute_HB();
    ~OperationSpec_Execute_HB();

private:
		Rf_Oper_HB *m_pHBRfOper;
		Tag_SelectAccessResult *m_pCurrentSelectAccessResult;
public:
		
    bool singleSelectAccess(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,CAntennaSpec *pAntennaSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec);
		
		void run();
};

#endif // OPERATIONSPEC_EXECUTE_H
