#ifndef OPERATIONREPORT_MANAGER_H
#define OPERATIONREPORT_MANAGER_H

#include <vector>
#include <queue>
using namespace std;

#include "tag_selectaccessresult.h"
#include "tag_selectspec.h"
#include "tag_accessspec.h"
#include "class_retain.h"
#include "base_comm.h"
#include "operationspec_execute_base.h"




/**
 * @brief The OperationReport_Manager class
 * by lijin 2018.01.05
 * 该类主要负责将业务操作结果打包成业务报告。
 * 该类提供业务规则及相应结果数据输入接口。
 * 提供业务报告输出接口。
 *
 */

class OperationReport_Manager
{
public:
    OperationReport_Manager();

private:
    OperationSpec_Execute_Base *m_pOpSpecExec;
    int BankID_Index; //分区代号的序列号

    vector<OpspecResult*> m_TempOpsecResults; //用以打包OpspecResult的临时队列

    queue<Tag_SelectAccessResult*> m_SelecAccessResults; //continue操作专用的结果集合

    queue<CTagSelectAccessReport*> m_SelectAccessReports;//报告的队列

private:
    CParameter* findOpspecInAccessCommand(int userid,CAccessCommand *pAccessCommand);

    //2017.12.26新加，将Select报告和Access报告打包在一个TagReportData中
    CTagReportData* genTagReportData(vector<OpspecResult *> * pSelectResult,vector<OpspecResult *> * pAccessResults,unsigned char carid);

    Tag_SelectAccessResult * wrapOpspecResults(vector<OpspecResult*>* pOpspecResults,Tag_SelectSpec *pTagSelectSpec);
    Tag_SelectAccessResult * getSAResFromOpRes();
    CTagSelectAccessReport* genSelectAccessReport(int reportdata_count,unsigned char carId);

public:
    inline void setOpExec(OperationSpec_Execute_Base *pOpExec){
        m_pOpSpecExec = pOpExec;
    }
    inline int getSelectAccessReportsSize(){
        return m_SelectAccessReports.size();
    }

    CTagSelectAccessReport * frontSelectAccessReport();
    void popSelectAccessReport();
    //void sendReportToComm(Base_Comm *pComm);
public:
    void run();
    inline void clearTempOpResults(){
        for(int i=0;i<m_TempOpsecResults.size();i++){
            printf("delete temp popresult\n");
            OpspecResult *popresult = m_TempOpsecResults.at(i);
            delete popresult;
        }
        m_TempOpsecResults.clear();
    }
};

#endif // OPERATIONREPORT_MANAGER_H
