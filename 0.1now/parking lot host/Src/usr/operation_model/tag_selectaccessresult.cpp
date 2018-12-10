#include "tag_selectaccessresult.h"

Tag_SelectAccessResult::Tag_SelectAccessResult() {
	// TODO Auto-generated constructor stub
    ptagSelectResult = NULL;
    ptagAccessOpResults = NULL;
}

Tag_SelectAccessResult::~Tag_SelectAccessResult() {
	// TODO Auto-generated destructor stub
    //在析构中删除用过的对象。
    if(ptagSelectResult!=NULL){
        for(int i=0;i<ptagSelectResult->size();i++){
            delete ptagSelectResult->at(i);
        }
        delete ptagSelectResult;
    }

    if(ptagAccessOpResults!=NULL){
        for(int i=0;i<ptagAccessOpResults->size();i++){
            delete ptagAccessOpResults->at(i);
        }
        delete ptagAccessOpResults;
    }
}
