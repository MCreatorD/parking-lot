/*
 * TagSelectSpec.h
 *
 *  Created on: 2016-3-18
 *      Author: root
 */

#ifndef TAG_SELECTSPEC_H_
#define TAG_SELECTSPEC_H_

#include <list>
#include <vector>
using namespace std;

#include "HbFrame_Operation.h"
#include "tag_accessspec.h"
#include "tag_spec.h"

class Tag_SelectSpec :public Tag_Spec{
public:
    Tag_SelectSpec(CAddSelectSpec *pSpec);
    virtual ~Tag_SelectSpec();

public:
	bool isValid; //标识是否有效，删除时，将其置为false，然后再在外部根据其状态对对象进行删除操作。
	llrp_u32_t selectSpecID;
    //list<TagAntennaSpec*> tagAntennaSpeclist;

    vector<Tag_AccessSpec*> tagAccessSpecs; //按顺序记录当前Select下属的TagAccessSpec

	bool hasContinueOperation; //当前Access是否包含continue操作（实际就是是否有匹配条件）

    //int currentReadUserCount; //当前读多分区的数量

	bool hasReadRepeat; //标志第一个Op又用操作的用户区是否与Select中的相重复

private:

	CAddSelectSpec *pAddSelectSpec; //为方便管理，将消息指针传进来，在析构时，应将该消息删除
	CSelectSpec *pSelectSpec;

public:
	void setSelectSpec(CAddSelectSpec *pSpec);
	CSelectSpec* getSelectSpec();
    CAddSelectSpec *getAddSelectSpec();
    void pushTagAccess(Tag_AccessSpec *pSpec); //将TagAccess指针放入
    void eraseTagAccess(Tag_AccessSpec *pSpec); //删除TagAccess
    //void setCurrentTagAccessSpec(Tag_AccessSpec *pTagAccessSpec);

public:
    //以下记录当前正在进行的Select的相关参数
    llrp_u16_t  currentRfSpecID;
    llrp_u16_t  currentAntSpecIndex;
    Tag_AccessSpec *currentpTagAccessSpec;//当前正在使用的TagAccessSele
    vector<int> currentOperBankIDs; //当前操作的多分区号集合。

public:
    bool isSelectSpecFinish;
    llrp_u64_t specStartUTC;//规则开始的UTC时间，单位是微秒
    llrp_u64_t periodTrgUTC; //用以记录每次周期触发发生的时间。
};

#endif /* TAGSELECTSPEC_H_ */
