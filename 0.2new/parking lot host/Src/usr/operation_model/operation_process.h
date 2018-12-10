#ifndef OPERATION_PROCESS_H
#define OPERATION_PROCESS_H

#include "general.h"

#include "model_base.h"
#include "operationspec_manager.h"
#include "operationreport_manager.h"
#include "operationspec_execute_Base.h"
#include "operationspec_execute_gb.h"
#include "operationspec_execute_hb.h"
#include "rf_oper_base.h"

 /**
 * @brief The Operation_Process class
 * 主业务流控制类，用以控制业务流程
 *  by lijin 2018.01.12，由linux版的程序改写而来。
 * 主要功能是通过规则管理类对象完成业务操作规是的添加删除等操作，
 * 通过规则执行类执行相应规则，完成业务操作流程，
 * 并通过报告生成类对象生成业务操作结果报告。
 * 该类对外提供添加删除业务规则接口，提供业务规则启动停止接口，
 * 提供业务操作结果报告输出接口。
 */

class Operation_Process:public Model_Base
{
public:
    Operation_Process();
    ~Operation_Process();
private:
    OperationSpec_Manager *m_pOpSpecManager;
    OperationReport_Manager *m_pOpReportManager;
		OperationSpec_Execute_Base *m_pOpspecExecute;
		
private:
    void initOperationExecute();
public:

    inline OperationSpec_Manager* getOpSpecManager(){
        return m_pOpSpecManager;
    }
    inline OperationReport_Manager* getOpReportManager(){
        return m_pOpReportManager;
    }

    inline OperationSpec_Execute_Base* getOpExecute(){
        return m_pOpspecExecute;
    }
		




    int dealMessage(CMessage *pMessage, Base_Comm *pComm);
    
public:
    void run();

};

#endif // OPERATION_PROCESS_H
