/*
 * TagAccessSpec.h
 *
 *  Created on: 2016-3-18
 *      Author: root
 */

#ifndef TAG_ACCESSSPEC_H_
#define TAG_ACCESSSPEC_H_

#include "HbFrame_Operation.h"
#include "tag_spec.h"

class Tag_AccessSpec :public Tag_Spec {
public:
    Tag_AccessSpec(CAddAccessSpec *pSpec);
    virtual ~Tag_AccessSpec();

public:
	llrp_u32_t accessSpecID;
	bool isValid;  //是否有效，无效则可以删除，主要是为了不直接删除，而是在使用完毕后再删除
private:
	CAddAccessSpec *pAddAccessSpec;
	CAccessSpec *pAccessSpec;
public:
	void setAccessSpec(CAddAccessSpec *pSpec);
	CAccessSpec * getAccessSpec();
    CAddAccessSpec * getAddAccessSpec();
};

#endif /* TAGACCESSSPEC_H_ */
