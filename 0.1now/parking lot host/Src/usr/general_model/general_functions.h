#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#include <string>
#include <vector>
using namespace std;

#include "HbFrame_Operation.h"

class General_Functions
{
public:
    General_Functions();

public:
    static vector<string> splitString(string str,string pattern);
    static unsigned long long getCurrentUTC();
    static char * IPV4ToChar(llrp_u32_t ip);
};

#endif // GENERAL_FUNCTIONS_H
