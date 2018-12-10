#ifndef TAG_SELECTACCESSRESULT_H_
#define TAG_SELECTACCESSRESULT_H_

#include <vector>

using namespace std;

#include "HbFrame_Operation.h"
#include "OpspecResult.h"

/**
 * @brief The TagSelectAccessResult class
 * by lijin 2017.03.06
 * 用以记录一次完整的Select及Access操作的结果数据
 */

class Tag_SelectAccessResult {
public:
    Tag_SelectAccessResult();
    virtual ~Tag_SelectAccessResult();

public:
    vector<OpspecResult *>* ptagSelectResult; //标签操作结果集合，实际只可能有一个元素，为统一处理，也设为队列
	vector<OpspecResult *>* ptagAccessOpResults; //标签Access操作的结果集合

private:
    //以下是生成报告所需的资讯即SelectReportSpec中所规定的东西
};

#endif /* TAGSELECTACCESSRESULT_H_ */
