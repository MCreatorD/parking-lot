/*
 * Tag_AccessSpec.cpp
 *
 *  Created on: 2016-3-18
 *      Author: root
 */

#include "tag_accessspec.h"

Tag_AccessSpec::Tag_AccessSpec(CAddAccessSpec *pSpec) {
	// TODO Auto-generated constructor stub
    pAddAccessSpec = NULL;
	pAccessSpec = NULL;
	isValid = true;
	this->setAccessSpec(pSpec);
}

Tag_AccessSpec::~Tag_AccessSpec() {
	// TODO Auto-generated destructor stub
	if(pAddAccessSpec!=NULL){
		delete pAddAccessSpec;
	}
}

void Tag_AccessSpec::setAccessSpec(CAddAccessSpec *pSpec){
    this->pAddAccessSpec = (CAddAccessSpec*)HbFrame_Operation::copyMessage(pSpec);
	this->pAccessSpec = pAddAccessSpec->getAccessSpec();
	this->accessSpecID = pAccessSpec->getAccessSpecID();
}

CAccessSpec * Tag_AccessSpec::getAccessSpec(){
	return this->pAccessSpec;
}

CAddAccessSpec * Tag_AccessSpec::getAddAccessSpec(){
    return this->pAddAccessSpec;
}
