/*
 * OpspecResult.cpp
 *
 *  Created on: 2016-8-4
 *      Author: root
 */

#include "OpspecResult.h"
#include "MCUToSecureComm.h"

OpspecResult::OpspecResult() {
	// TODO Auto-generated constructor stub
	//this->isContinueOperation = true;
}

OpspecResult::~OpspecResult() {
	// TODO Auto-generated destructor stub
	MCUToSecureComm::removeFrame(pOpResultFrame);
    this->m_pTagSelectSpec->release();

}

void OpspecResult::setOpParams(Tag_SelectSpec *pTagSelectSpec){
    Tag_AccessSpec *pAccessSpec = NULL;
    if(pTagSelectSpec->currentpTagAccessSpec!=NULL){
        //printf("e0........................\n");
        pAccessSpec = pTagSelectSpec->currentpTagAccessSpec;
    }else{
        //printf("e1........................\n");
        pAccessSpec = NULL;
    }
    this->setOpParams(pTagSelectSpec,pAccessSpec,NULL);
}

void OpspecResult::setOpParams(Tag_SelectSpec *pTagSelectSpec,CParameter *pOpspec){
    Tag_AccessSpec *pAccessSpec = NULL;
    if(pTagSelectSpec->currentpTagAccessSpec!=NULL){
        //printf("e0........................\n");
        pAccessSpec = pTagSelectSpec->currentpTagAccessSpec;
    }else{
        //printf("e1........................\n");
        pAccessSpec = NULL;
    }
    this->setOpParams(pTagSelectSpec,pAccessSpec,pOpspec);
}

void OpspecResult::setOpParams(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,CParameter *pOpspec){
    //printf("pTagSelectSpec->retain()\n");
    pTagSelectSpec->retain(); //注意在这里Tag_AccessSpec未做保留处理。因为它不会被单独使用
    m_pTagSelectSpec = pTagSelectSpec;
    pSelectSpec = m_pTagSelectSpec->getSelectSpec();

    if(pTagAccessSpec!=NULL){
        pAccessSpec = pTagAccessSpec->getAccessSpec();
    }else{
        pAccessSpec = NULL;
    }
    pOpSpec = pOpspec;
    Op_SelectSpecID = m_pTagSelectSpec->getSelectSpec()->getSelectSpecID();
    Op_RfSpecID = m_pTagSelectSpec->currentRfSpecID;
    Op_AntennaSpecIndex = m_pTagSelectSpec->currentAntSpecIndex;
    Op_BankIDs = m_pTagSelectSpec->currentOperBankIDs;

}
