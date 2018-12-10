#ifndef CARMSGCOMPARE_H
#define CARMSGCOMPARE_H

#include <map>
#include <string>
using namespace std;
//#include <QDebug>
#define BIGORSMALL true  // true 为小端
#define ERROR_MSG  "ERROR"
union unShortChar {
    short int s;
    char      ch[2];
};

class CarMsgCompare
{
private:
    map<short int, string> mDataType;  //数据类别对照表 <类别代码,类别名称> <0x88, "卡号">
    map<int, string> mProvince_CodeAndName; //省份代码对照省份 <省份代码，省份> <11,"北京">
    map<char, int> mProvince_BitAndCode;    //二进制对照省份代码 <二进制编码，省份代码> <0000001,11>（北京）
    map<char, string> mProvince_BitAndName; //省份对照二进制代码 <二进制编码，省份名称> <0000001, "北京">
    map<char, string> mProvinceCodeAndBit; //省份简称 <二进制，省份简称> <0000001, "京">
    map<char, int> mDealCodeNum; //发牌代码序号对照二进制 <二进制,序号>
    map<char, char> mDealCodeBit; //发牌代码对照二进制 <二进制，发牌代码> <00000, A>      提供接口
    map<char, string> mCarUseType; //使用性质二进制编码表 <二进制编码，使用性质> <1000,"非运营">   提供接口
    map<short int, int> mCarTypeNumAndBit; //车辆类型序号对照二进制编码 <二进制编码，车辆类型序号> <000000001, 1>
    map<short int, string> mCarTypeAndBit; //车辆类型名称对照二进制编码 <二进制编码，车辆类型> <000000001, "大型普通货车">
    map<short int, string> mCarTypeBitAndCode; //车辆类型名车对照车辆类型代码   <000000001, "K11">
    map<char, string> mCarPlateType; //号牌种类二进制编码  <0001, "小型汽车">
    map<char, char> mSerialNum; //序号二进制编码   <二进制编码，码元>
    map<char, string> mCarColor; //车身颜色 <0001,"">
public:
    CarMsgCompare();
    ~CarMsgCompare();


    string GetUseType(char code); //取得使用性质
    string GetDealCode(char* code);  //取得发牌代号 返回"苏A" "皖B"
    string GetCarColor(char code);  // 取得车身颜色
    string GetCarType(char* code);  // 取得车辆类型
    string GetCarNum(char* code,int codenum); //取得号牌号码序号
    string GetPlateType(char code);  //获得号牌种类
    //解析卡号数据，msg为5字节，type为0表示获取省份名称，type为1代表获取省份简称
    //返回0代表交通管理机关发行卡，1表示新车出厂预装卡
    string GetCardInfo(unsigned char* msg );



private:
    //初始化
    void init();
    void init_dataType();   //初始化 数据类别对照表 <类别代码,类别名称> <0x88, "卡号">
    void init_Province_CodeAndName(); //初始化 省份代码对照省份 <省份代码，省份> <11,"北京">
    void init_mProvince_BitAndCode(); //二进制对照省份代码 <二进制编码，省份代码> <0000001,11>（北京）
    void init_mProvin_BitAndName(); //省份对照二进制代码 <二进制编码，省份名称> <0000001, "北京">
    void init_mProvinceCodeAndBit(); //省份简称 <二进制，省份简称> <0000001, "京">
    void init_mDealCodeNum(); //发牌代码序号对照二进制 <二进制,序号>
    void init_mDealCodeBit();  //发牌代码对照二进制 <二进制，发牌代码> <00000, A>
    void init_mCarUseType();   //使用性质二进制编码表
    void init_mCarTypeNumAndBit(); //车辆类型序号对照二进制编码 <1, 000000001>
    void init_mCarTypeAndBit();  //车辆类型名称对照二进制编码  <000000001, "大型普通货车">
    void init_mCarTypeBitAndCode();  //车辆类型名车对照车辆类型代码   <"大型普通货车", "K11">
    void init_mCarPlateType(); //号牌种类二进制编码  <0001, "小型汽车">
    void init_mSerialNum();    //序号二进制编码   <二进制编码，码元>
    void init_mCarColor();     //车身颜色 <0001,"">

};

#endif // CARMSGCOMPARE_H
