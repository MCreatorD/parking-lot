/*
 * Tag_SelectSpec.cpp
 *
 *  Created on: 2016-3-18
 *      Author: root
 */

#include "tag_selectspec.h"
#include <stdio.h>

Tag_SelectSpec::Tag_SelectSpec(CAddSelectSpec *pSpec) {
	// TODO Auto-generated constructor stub
	pAddSelectSpec = NULL;
	pSelectSpec = NULL;
	//pAttchedAccessSpec = NULL;
	isValid = true;
    this->setSelectSpec(pSpec);
    this->currentpTagAccessSpec = NULL;
	hasContinueOperation = false;
    //currentReadUserCount = 0;
	hasReadRepeat = false;

     periodTrgUTC = 0;
}

Tag_SelectSpec::~Tag_SelectSpec() {
	// TODO Auto-generated destructor stub

    //将所拥有的TagAccess释放一次
    for(vector<Tag_AccessSpec*>::iterator itr = tagAccessSpecs.begin();
            itr!=tagAccessSpecs.end();itr++)
    {
        (*itr)->release();
        printf("1:access release......................\n");
    }

    if(pAddSelectSpec!=NULL){//析构时，删除消息本身。即在Tag_SelectSpec被删除时，消息也被删除
        delete pAddSelectSpec;
    }
}

/**
 * @brief Tag_SelectSpec::setSelectSpec
 * @param pSpec
 * 设置类中的AddSelectSpec指针及SelectSpec指针
 * 添加时，采用的是复制对象的方法
 */
void Tag_SelectSpec::setSelectSpec(CAddSelectSpec *pSpec){

    this->pAddSelectSpec = (CAddSelectSpec*)HbFrame_Operation::copyMessage(pSpec);
    //this->pAddSelectSpec = pSpec;
    //printf("pAddSelectSpec.state=%d\n",pAddSelectSpec->getSelectSpec()->getSelectCurrentState());
    //delete pSpec;
    //printf("pAddSelectSpec.state=%d\n",pAddSelectSpec->getSelectSpec()->getSelectCurrentState());

    pSelectSpec = pAddSelectSpec->getSelectSpec();
    this->selectSpecID = pSelectSpec->getSelectSpecID();
//    for(list<CAntennaSpec*>::iterator it=pSelectSpec->beginAntennaSpec();
//            it!=pSelectSpec->endAntennaSpec();it++){
//        TagAntennaSpec *pa = new TagAntennaSpec(*it);
//        tagAntennaSpeclist.push_back(pa);
//    }
}

CSelectSpec* Tag_SelectSpec::getSelectSpec(){
	return this->pSelectSpec;
}

CAddSelectSpec *Tag_SelectSpec::getAddSelectSpec(){
    return this->pAddSelectSpec;
}

void Tag_SelectSpec::pushTagAccess(Tag_AccessSpec *pSpec){ //将TagAccess指针放入
    pSpec->retain(); //20171108新加，保留Access，以保证Access不会在Select还未删除时被先删除
    //printf("tag access retain....................\n");
    tagAccessSpecs.push_back(pSpec);
}

/*
 * 将TagAccess集合中所有指定的TagAccess删除
 * 注意，TagAceess本身并未被删除
 */
void Tag_SelectSpec::eraseTagAccess(Tag_AccessSpec *pSpec){
    vector<Tag_AccessSpec*>::iterator itr = tagAccessSpecs.begin();
	while (itr!=tagAccessSpecs.end())
	{
		if(*itr==pSpec)
	    {
            (*itr)->release(); //20171108新加
			itr = tagAccessSpecs.erase(itr);
            printf("0:access release......................\n");
	    }
		else
	    itr++;
	}
}

/**
 * @brief Tag_SelectSpec::setCurrentTagAccessSpec
 * @param pTagAccessSpec
 * 设置selectspec的当前有效access规则，同时，设置相应变量
 */
//void Tag_SelectSpec::setCurrentTagAccessSpec(Tag_AccessSpec *pTagAccessSpec){
//    this->currentTagAccessSpec = pTagAccessSpec;
//    CRfSpec *prfspec = this->getSelectSpec()->beginAntennaSpec()
//}

//Struct_TagBank_RWInfo Tag_SelectSpec::getBankinfoFromMemBank(CMemoryBank *pMemoryBank){
//    Struct_TagBank_RWInfo bankinfo;

//    bankinfo.BankNum = pMemoryBank->getMemoryBankID();
//    llrp_u8_t memid = pMemoryBank->getMemoryBankID();
//    llrp_u16_t pointer = pMemoryBank->getPointer();
//    llrp_u16_t count = pMemoryBank->getCount();

//    if(pMemoryBank->getReadType()==0){//按长度读
//        //printf("d2\n");
//        if(memid==0||memid==2){ //user0，user2才有上下半区的概念
//            if(pointer>=HALF_USER_POINT){//起点在下半区
//                bankinfo.BankReadFlag = 0; //下半区
//            }else{//起点在上半区
//                if(pointer+count-1>=HALF_USER_POINT){
//                    bankinfo.BankReadFlag = 2;//全区
//                }else{
//                    bankinfo.BankReadFlag = 1;//上半区
//                }
//            }
//        }else{
//            bankinfo.BankReadFlag = 2; //其它区全部只能是全区
//        }
//    }else if(pMemoryBank->getReadType()==1){//按分区类型读
//        //printf("d3\n");
//        bankinfo.BankReadFlag = pMemoryBank->getBankType();
//    }

//    bankinfo.BankCryptFlag = 0x00;
//    bankinfo.BankReadSpeedFlag = 1; //暂定为默认的1(user0,user2只能用高速读)
//    bankinfo.BankReadPoint = 0x00;
//    bankinfo.BankReadCount = 0x00;

//    return bankinfo;
//}

//void Tag_SelectSpec::setCurrentSelect(CAccessSpec *pAccessSpec,CAntennaSpec *pAntennaSpec,CRfSpec *pRfSpec){
//    pCurrentAntennaSpec = pAntennaSpec;
//    pCurrentRfSpec = pRfSpec;

//    llrp_u8_t selecttype = pRfSpec->getSelectType();

//    if(pAccessSpec==NULL){
//        if(selecttype==0){//是盘点

//        }else{//是读
//            Struct_TagBank_RWInfo bankinfos[6]; //最多6个分区。规范中分区5不能读，故最多5个分区
//            int bankcount = 0;
//            CMemoryBank *pbank = pRfSpec->getMemoryBank();
//            if(pbank!=NULL){
//                bankinfos[bankcount++] = this->getBankinfoFromMemBank(pbank);
//            }
//            currentReadUserCount = bankcount;
//        }

//    }
//}
