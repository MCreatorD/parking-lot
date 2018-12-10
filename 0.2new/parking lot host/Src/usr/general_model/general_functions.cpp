#include "general_functions.h"
//#include <sys/time.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
#include "pcf8563.h"
General_Functions::General_Functions()
{
}

vector<string> General_Functions::splitString(string str,string pattern)
{
    string::size_type pos;
    vector<string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();

    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}

/**
 * @brief General_Functions::getCurrentUTC
 * @return
 * 返回当前UTC时间。单位是微秒
 */
unsigned long long General_Functions::getCurrentUTC()
{
//	//需要 填写获取RTC
//		long long  res = pcf8563Utc(readAllPcf8563Time()); 
//		res = res *1000000;	
//    /*struct timeval nowTime;
//    gettimeofday(&nowTime, NULL);
//    unsigned long long utc = (unsigned long long)nowTime.tv_sec * 1000000 + (unsigned long long)nowTime.tv_usec;
//    return utc;*/
	long long  res  = 0;
	return res;
}

char *General_Functions::IPV4ToChar(llrp_u32_t ip){
    /*struct in_addr t; //注意，这里要求输入的IP是大端模式的。所以要将IP颠倒字节序

    unsigned char tmp;
    tmp = *(((unsigned char *)&ip)+0);
    *(((unsigned char *)&ip)+0) = *(((unsigned char *)&ip)+3);
    *(((unsigned char *)&ip)+3) = tmp;
    tmp = *(((unsigned char *)&ip)+1);
    *(((unsigned char *)&ip)+1) = *(((unsigned char *)&ip)+2);
    *(((unsigned char *)&ip)+2) = tmp;

    t.s_addr = ip;

    return inet_ntoa(t); //注意，这里返回的指针是静态内存中的指针，超过其作用范围，即会失效。
		*/
}
