#ifndef OPERATIONSPEC_MANAGER_H
#define OPERATIONSPEC_MANAGER_H

#include <list>
using namespace std;

#include "tag_accessspec.h"
#include "tag_selectspec.h"
#include "hbframe_operation.h"

/**
 * @brief The OperationSpec_Manager class
 * by lijin 2017.02.15
 * 操作规则（Select和Access）管理类
 * 该类主要负责存贮下发的操作规则，
 * 并负责添加删除操作规则，
 * 改变操作规则的状态。
 * 该类对外提供添加删除业务规则接口，
 * 提供业务规则查询接口，
 * 提供业务规则状态改变接口（就绪，工作中，无效等状态）
 */

class OperationSpec_Manager
{
public:
    OperationSpec_Manager();
    ~OperationSpec_Manager();
private:
//    map<llrp_u32_t,Tag_SelectSpec *>*  m_pIDToSelectSpec; //selectID到SelectSpec的映射
//    map<llrp_u32_t,Tag_AccessSpec *>* m_pIDToAccessSpec;
    list<Tag_SelectSpec*> *m_pSelectSpecList;
    list<Tag_AccessSpec*> *m_pAccessSpecList;

    list<Tag_SelectSpec*>::iterator m_SelectSpecList_IT;
public:
    inline list<Tag_SelectSpec*> *getSelectSpecList(){
        return this->m_pSelectSpecList;
    }
    inline list<Tag_AccessSpec*> *getSelectAccessList(){
        return this->m_pAccessSpecList;
    }
    Tag_SelectSpec* nextTagSelectSpec();
    vector<CSelectSpec*> getSelectSpecs();
    vector<CAccessSpec*> getAccessSpecs();

private:
    vector<Tag_SelectSpec*>findValidSelectByID(llrp_u32_t selectid);
    vector<Tag_AccessSpec*> findValidAccessByID(llrp_u32_t selectid);
    void setSelectFromAccess(Tag_SelectSpec *pSpec);
    void pushAccessToSelect(Tag_AccessSpec *pSpec);
    void removeAccessFromSelect(Tag_AccessSpec *pSpec);
public:
    bool addSelectSpec(CAddSelectSpec *pAddSelectSpec,bool isNeedSave);
    bool disableSelectSpec(llrp_u32_t specid);
    bool enableSelectSpec(llrp_u32_t specid);
    bool deleteSelectSpec(llrp_u32_t specid);
    bool startSelectSpec(llrp_u32_t specid);
    bool stopSelectSpec(llrp_u32_t specid);
    bool addAccessSpec(CAddAccessSpec *pAddAccessSpec,bool isNeedSave);
    bool disableAccessSpec(llrp_u32_t specid);
    bool enableAccessSpec(llrp_u32_t specid);
    bool deleteAccessSpec(llrp_u32_t specid);
public:
    Tag_SelectSpec *requestValidSelectSpec(llrp_u32_t selectid);
    void releaseInvalidSpecs();

private:
    void writePersisSelect(CAddSelectSpec *pAddSelectSpec);
    void writePersisAccess(llrp_u32_t accessid,CAccessSpec *pAccessSpec);
    CSelectSpec* ReadPersisSelect(llrp_u32_t selectid);
    CAccessSpec* ReadPersisAccess(llrp_u32_t accessid);
    bool deletePersisSelect(llrp_u32_t selectid);
    bool deletePersisAccess(llrp_u32_t accessid);

public:
    vector<CAddSelectSpec*> readAllPersisSelect();
    vector<CAddAccessSpec*> readAllPersisAccess();

private:
		
public:
	  CAddSelectSpec *m_pCurrentSelectSpec;
		void initDefaultSelectSpec();

public:
		//void activeGPISelectSpec();
};

#endif // OPERATIONSPEC_MANAGER_H
