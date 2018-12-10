#ifndef OPERATIONSPEC_EXECUTE_GB_H
#define OPERATIONSPEC_EXECUTE_GB_H

#include "operationspec_execute_base.h"
#include "rf_oper_gb.h"

/**
 * @brief The Operationspec_Execute_GB class
 * by lijin,2017.10.18
 */

class Operationspec_Execute_GB:public OperationSpec_Execute_Base
{
public:
    Operationspec_Execute_GB();
    ~Operationspec_Execute_GB();

private:
		Rf_Oper_GB *m_pGBRfOper;

private:
    MCU_TO_SECURE_FRAME *convertGBFrameToHBSelectFrame(STRUCT_RF2M_FRAME* pGBFrame,CRfSpec *pRfSpec);
    MCU_TO_SECURE_FRAME *convertGBFrameToHBAccessFrame(STRUCT_RF2M_FRAME* pGBFrame,CRfSpec *pRfSpec);
public:
		
    bool singleSelectAccess(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,CAntennaSpec *pAntennaSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec);
		
		void run();

};

#endif // OPERATIONSPEC_EXECUTE_GB_H
