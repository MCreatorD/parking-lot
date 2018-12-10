#include "CarMsgCompare.h"


CarMsgCompare::CarMsgCompare()
{
    this->init();
}

CarMsgCompare::~CarMsgCompare()
{

}

void CarMsgCompare::init()
{
    //init_dataType();
    //init_Province_CodeAndName();
    //init_mProvince_BitAndCode();
    //init_mProvin_BitAndName();
    init_mProvinceCodeAndBit();
    init_mDealCodeNum();
    init_mDealCodeBit();
    init_mCarUseType();
    //init_mCarTypeAndBit();
    //init_mCarTypeBitAndCode();
    init_mCarPlateType();
    init_mSerialNum();
    //init_mCarColor();
}

//数据类别对照表 <类别代码,类别名称> <0x88, "卡号">
void CarMsgCompare::init_dataType()
{
    short int data;
    data = 0x8801; mDataType.insert(pair<short int, string>(data,"卡号") );
    data = 0x8802; mDataType.insert(pair<short int, string>(data, "发牌代号") );
    data = 0x8803; mDataType.insert(pair<short int, string>(data, "使用性质") );
    data = 0x8804; mDataType.insert(pair<short int, string>(data, "出厂日期") );
    data = 0x8805; mDataType.insert(pair<short int, string>(data, "车辆类型") );
    data = 0x8806; mDataType.insert(pair<short int, string>(data, "功率") );
    data = 0x8807; mDataType.insert(pair<short int, string>(data, "排量") );
    data = 0x8808; mDataType.insert(pair<short int, string>(data, "号牌种类") );
    data = 0x8809; mDataType.insert(pair<short int, string>(data, "号牌号码序号") );
    data = 0x880A; mDataType.insert(pair<short int, string>(data, "检验有效期") );
    data = 0x880B; mDataType.insert(pair<short int, string>(data, "强制报废期") );
    data = 0x880C; mDataType.insert(pair<short int, string>(data, "核定载客/总质量") );
    data = 0x880D; mDataType.insert(pair<short int, string>(data, "车身颜色") );
}
//省份代码对照省份 <省份代码，省份> <11,"北京">
void CarMsgCompare::init_Province_CodeAndName()
{
    mProvince_CodeAndName.insert(pair<int, string>(11, "北京"));
    mProvince_CodeAndName.insert(pair<int, string>(12, "天津"));
    mProvince_CodeAndName.insert(pair<int, string>(13, "河北"));
    mProvince_CodeAndName.insert(pair<int, string>(14, "山西"));
    mProvince_CodeAndName.insert(pair<int, string>(15, "内蒙古"));
    mProvince_CodeAndName.insert(pair<int, string>(21, "辽宁"));
    mProvince_CodeAndName.insert(pair<int, string>(22, "吉林"));
    mProvince_CodeAndName.insert(pair<int, string>(23, "黑龙江"));
    mProvince_CodeAndName.insert(pair<int, string>(31, "上海"));
    mProvince_CodeAndName.insert(pair<int, string>(32, "江苏"));
    mProvince_CodeAndName.insert(pair<int, string>(33, "浙江"));
    mProvince_CodeAndName.insert(pair<int, string>(34, "安徽"));
    mProvince_CodeAndName.insert(pair<int, string>(35, "福建"));
    mProvince_CodeAndName.insert(pair<int, string>(36, "江西"));
    mProvince_CodeAndName.insert(pair<int, string>(37, "山东"));
    mProvince_CodeAndName.insert(pair<int, string>(41, "河南"));
    mProvince_CodeAndName.insert(pair<int, string>(42, "湖北"));
    mProvince_CodeAndName.insert(pair<int, string>(43, "湖南"));
    mProvince_CodeAndName.insert(pair<int, string>(44, "广东"));
    mProvince_CodeAndName.insert(pair<int, string>(45, "广西"));
    mProvince_CodeAndName.insert(pair<int, string>(46, "海南"));
    mProvince_CodeAndName.insert(pair<int, string>(50, "重庆"));
    mProvince_CodeAndName.insert(pair<int, string>(51, "四川"));
    mProvince_CodeAndName.insert(pair<int, string>(52, "贵州"));
    mProvince_CodeAndName.insert(pair<int, string>(53, "云南"));
    mProvince_CodeAndName.insert(pair<int, string>(54, "西藏"));
    mProvince_CodeAndName.insert(pair<int, string>(61, "陕西"));
    mProvince_CodeAndName.insert(pair<int, string>(62, "甘肃"));
    mProvince_CodeAndName.insert(pair<int, string>(63, "青海"));
    mProvince_CodeAndName.insert(pair<int, string>(64, "宁夏"));
    mProvince_CodeAndName.insert(pair<int, string>(65, "新疆"));
    mProvince_CodeAndName.insert(pair<int, string>(71, "香港"));
    mProvince_CodeAndName.insert(pair<int, string>(82, "澳门"));
}
//二进制对照省份代码 <二进制编码，省份代码> <0000001,11>（北京）
void CarMsgCompare::init_mProvince_BitAndCode()
{
    char bin = 0x00; //二进制编码

    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 11)); //"北京")); //0000001
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 12)); //"天津")); //0000010
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 13)); //"河北")); //0000011
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 14)); //"山西")); //0000100
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 15)); //"内蒙古")); //0000101
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 21)); //"辽宁"));  //0000110
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 22)); //"吉林"));  //0000111
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 23)); //"黑龙江")); //0001000
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 31)); //"上海"));  //0001001
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 32)); //"江苏"));  //0001010
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 33)); //"浙江"));  //0001011
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 34)); //"安徽"));  //0001100
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 35)); //"福建"));  //0001101
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 36)); //"江西"));  //0001110
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 37)); //"山东"));  //0001111

    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 41)); //"河南"));  //0010000
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 42)); //"湖北"));  //0010001
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 43)); //"湖南"));  //0010010
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 44)); //"广东"));  //0010011
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 45)); //"广西"));  //0010100
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 46)); //"海南"));  //0010101
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 50)); //"重庆"));  //0010110
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 51)); //"四川"));  //0010111
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 52)); //"贵州"));  //0011000
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 53)); //"云南"));  //0011001
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 54)); //"西藏"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 61)); //"陕西"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 62)); //"甘肃"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 63)); //"青海"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 64)); //"宁夏"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 65)); //"新疆"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 71)); //"香港"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 82)); //"澳门"));
}
//省份对照二进制代码 <二进制编码，省份名称> <0000001, "北京">
void CarMsgCompare::init_mProvin_BitAndName()
{
    char bin = 0x00; //二进制编码

    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "北京")); //0000001
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "天津")); //0000010
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "河北")); //0000011
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "山西")); //0000100
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "内蒙古")); //0000101
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "辽宁"));  //0000110
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "吉林"));  //0000111
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "黑龙江")); //0001000
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "上海"));  //0001001
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "江苏"));  //0001010
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "浙江"));  //0001011
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "安徽"));  //0001100
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "福建"));  //0001101
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "江西"));  //0001110
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "山东"));  //0001111

    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "河南"));  //0010000
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "湖北"));  //0010001
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "湖南"));  //0010010
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "广东"));  //0010011
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "广西"));  //0010100
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "海南"));  //0010101
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "重庆"));  //0010110
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "四川"));  //0010111
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "贵州"));  //0011000
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "云南"));  //0011001
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "西藏"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "陕西"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "甘肃"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "青海"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "宁夏"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "新疆"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "香港"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "澳门"));
}
//省份简称 <二进制，省份简称> <0000001, "京">
void CarMsgCompare::init_mProvinceCodeAndBit()
{
    char bin = 0x00;

    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "京"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "津"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "冀"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "晋"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "蒙"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "辽"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "吉"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "黑"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "沪"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "苏"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "浙"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "皖"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "闽"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "赣"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "鲁"));

    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "豫"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "鄂"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "湘"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "粤"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "桂"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "琼"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "渝"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "川"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "贵"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "云"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "藏"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "陕"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "甘"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "青"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "宁"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "新"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "港"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "澳"));
}
//发牌代码序号对照二进制 <二进制,序号>
void CarMsgCompare::init_mDealCodeNum()
{
    char bin;
    bin = 0x00;
    int num = 0;

    num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );  //num==16

    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
    bin++; num++; mDealCodeNum.insert( pair<char, int>(bin, num) );
}
//发牌代码对照二进制 <二进制，发牌代码> <00000, 'A'>
void CarMsgCompare::init_mDealCodeBit()
{
    char bin= 0x00;

     mDealCodeBit.insert( pair<char, char>(bin, 'A') );
    bin++;  mDealCodeBit.insert( pair<char, char>(bin, 'B') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'C') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'D') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'E') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'F') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'G') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'H') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'J') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'K') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'L') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'M') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'N') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'P') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'Q') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'R') );

    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'S') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'T') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'U') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'V') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'W') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'X') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'Y') );
    bin++; mDealCodeBit.insert( pair<char, char>(bin, 'Z') );

}

void CarMsgCompare::init_mCarUseType()
{
    char hex;
    hex = 0x08; mCarUseType.insert( pair<char, string>(hex, "非营运") );
    hex = 0x01; mCarUseType.insert( pair<char, string>(hex, "公路客运、旅游客运") );
    hex = 0x02; mCarUseType.insert( pair<char, string>(hex, "公交客运") );
    hex = 0x03; mCarUseType.insert( pair<char, string>(hex, "出租客运") );
    hex = 0x04; mCarUseType.insert( pair<char, string>(hex, "货运") );
    hex = 0x05; mCarUseType.insert( pair<char, string>(hex, "租赁") );
    hex = 0x0C; mCarUseType.insert( pair<char, string>(hex, "警用、消防、救护、工程抢险") );
    hex = 0x0F; mCarUseType.insert( pair<char, string>(hex, "教练车") );
    hex = 0x0D; mCarUseType.insert( pair<char, string>(hex, "幼儿校车、小学生校车、其他校车") );
    hex = 0x0E; mCarUseType.insert( pair<char, string>(hex, "危险品运输") );
    hex = 0x07; mCarUseType.insert( pair<char, string>(hex, "其他") );

}

void CarMsgCompare::init_mCarTypeNumAndBit()
{

}

void CarMsgCompare::init_mCarTypeAndBit()
{
    short int bin;
    bin = 0x0000;
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "大型普通客车") ); //000000001  K11
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "大型双层客车") ); //000000010
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "大型卧铺客车") ); //000000011
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "大型铰接客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "大型越野客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "大型轿车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "大型专用客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "大型专用校车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型普通客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型双层客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型卧铺客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型铰接客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型越野客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型轿车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型专用客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型专用校车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "小型普通客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "小型越野客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "小型桥车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "小型专用客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "小型专用校车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "小型面包车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型普通客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型越野客车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型轿车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型面包车") );   //000011010 K49

    bin = 0x0040; //001000000 Q11
    mCarTypeAndBit.insert( pair<short int, string>(bin, "重型半挂牵引车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型全挂牵引车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型半挂牵引车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型全挂牵引车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型半挂牵引车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型全挂牵引车") );

    bin = 0x0050; //001010000 Z11
    mCarTypeAndBit.insert( pair<short int, string>(bin, "大型非载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "大型载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型非载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "小型非载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "小型载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型非载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型非载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型非载货专项作业车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型载货专项作业车") );

    bin = 0x0060;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "普通正三轮摩托车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻便正三轮摩托车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "正三载客轮摩托车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "正三轮载货摩托车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "侧三轮摩托车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "普通二轮摩托车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻便二轮摩托车") );

    bin = 0x0068; mCarTypeAndBit.insert( pair<short int, string>(bin, "无轨电车") );
    bin = 0x0069; mCarTypeAndBit.insert( pair<short int, string>(bin, "有轨电车") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "三轮汽车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轮式装载机械") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轮式挖掘机械") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轮式平地机械") );

    bin = 0x0080;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "重型普通货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型箱式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型封闭货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型罐式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型平板货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型集装厢车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型特殊结构货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型仓栅式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型车辆运输车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型箱式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型罐式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型平板自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型集装箱自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型特殊结构自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型仓栅式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型普通货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型箱式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型封闭货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型罐式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型平板货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型集装箱车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型特殊结构货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型仓栅式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型车辆运输车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型箱式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型罐式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型平板自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型集装箱自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型特殊结构自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型仓栅式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型普通货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型厢式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型封闭货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型罐式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型平板货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型特殊结构货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型仓栅式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型车辆运输车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型箱式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型罐式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型平板自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型特殊结构自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型仓栅式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型普通货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型厢式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型封闭货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型罐式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型特殊结构货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型仓栅式货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型车辆运输车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型厢式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型罐式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型特殊结构自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "微型仓栅式自卸货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "普通低速货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "厢式低速货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "罐式低速货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "自卸低速货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "仓栅式低速货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "厢式自卸低速货车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "罐式自卸低速货车") );

    bin = 0x0100;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "重型普通全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型厢式全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型罐式全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型平板全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型集装箱全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型仓栅式全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型旅居全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型专项作业全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型厢式自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型罐式自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型平板自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型集装箱自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型仓栅式自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型专项作业自卸全挂车") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型普通全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型厢式全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型罐式全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型平板全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型集装箱全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型仓栅式全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型旅居全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型专项作业全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型厢式自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型罐式自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型平板自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型集装箱自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型仓栅式自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型专项作业自卸全挂车") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型普通全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型厢式全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型罐式全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型平板全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型仓栅式全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型旅居全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型专项作业全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型厢式自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型罐式自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型平板自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型集装箱自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型仓栅式自卸全挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型专项作业自卸全挂车") );

    bin = 0x0180;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "重型普通半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型厢式半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型罐式半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型平板半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型集装箱半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型特殊结构半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型仓栅式半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型旅居半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型专项作业半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型低平板半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型车辆运输半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型罐式自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型平板自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型集装箱自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型特殊结构自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型仓栅式自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型专项作业自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型低平板自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型中置轴旅居挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型中置轴车辆运输车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "重型中置轴普通挂车") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型普通半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型厢式半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型罐式半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型平板半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型集装箱半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型特殊结构半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型仓栅式半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型旅居半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型专项作业半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型低平板半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型车辆运输半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型罐式自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型平板自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型集装箱自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型特殊结构自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型仓栅式自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型专项作业自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型低平板自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型中置轴旅居挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型中置轴车辆运输车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "中型中置轴普通挂车") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型普通半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型厢式半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型罐式半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型平板半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型仓栅式半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型旅居半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型专项作业半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型低平板半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型车辆运输半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型罐式自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型平板自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型集装箱自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型特殊结构自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型仓栅式自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型专项作业自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型低平板自卸半挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型中置轴旅居挂车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型中置轴车辆运输车") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "轻型中置轴普通挂车") );

    bin = 0x0000;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "其他") );

}


void CarMsgCompare::init_mCarTypeBitAndCode()
{
    short int bin;
    bin = 0x0000;
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K11")); // "大型普通客车") ); //000000001  K11
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K12")); // "大型双层客车") ); //000000010
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K13")); // "大型卧铺客车") ); //000000011
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K14")); // "大型铰接客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K15")); // "大型越野客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K16")); // "大型轿车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K17")); // "大型专用客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K18")); // "大型专用校车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K21")); // "中型普通客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K22")); // "中型双层客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K23")); // "中型卧铺客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K24")); // "中型铰接客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K25")); // "中型越野客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K26")); // "中型轿车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K27")); // "中型专用客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K28")); // "中型专用校车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K31")); // "小型普通客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K32")); // "小型越野客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K33")); // "小型桥车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K34")); // "小型专用客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K38")); // "小型专用校车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K39")); // "小型面包车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K41")); // "微型普通客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K42")); // "微型越野客车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K43")); // "微型轿车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K49")); // "微型面包车") );   //000011010 K49

    bin = 0x0040; //001000000 Q11
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q11")); // "重型半挂牵引车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q12")); // "重型全挂牵引车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q21")); // "中型半挂牵引车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q22")); // "中型全挂牵引车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q31")); // "轻型半挂牵引车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q32")); // "轻型全挂牵引车") );

    bin = 0x0050; //001010000 Z11
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z11")); // "大型非载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z12")); // "大型载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z21")); // "中型非载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z22")); // "中型载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z31")); // "小型非载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z32")); // "小型载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z41")); // "微型非载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z42")); // "微型载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z51")); // "重型非载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z52")); // "重型载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z71")); // "轻型非载货专项作业车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z72")); // "轻型载货专项作业车") );

    bin = 0x0060;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M11")); // "普通正三轮摩托车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M12")); // "轻便正三轮摩托车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M13")); // "正三载客轮摩托车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M14")); // "正三轮载货摩托车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M15")); // "侧三轮摩托车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M21")); // "普通二轮摩托车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M22")); // "轻便二轮摩托车") );

    bin = 0x0068; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "D11")); // "无轨电车") );
    bin = 0x0069; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "D12")); // "有轨电车") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "N11")); // "三轮汽车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "J11")); // "轮式装载机械") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "J12")); // "轮式挖掘机械") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "J13")); // "轮式平地机械") );

    bin = 0x0080;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H11")); // "重型普通货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H12")); // "重型箱式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H13")); // "重型封闭货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H14")); // "重型罐式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H15")); // "重型平板货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H16")); // "重型集装厢车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H17")); // "重型自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H18")); // "重型特殊结构货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H19")); // "重型仓栅式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1A")); // "重型车辆运输车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1B")); // "重型箱式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1C")); // "重型罐式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1D")); // "重型平板自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1E")); // "重型集装箱自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1F")); // "重型特殊结构自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1G")); // "重型仓栅式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H21")); // "中型普通货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H22")); // "中型箱式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H23")); // "中型封闭货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H24")); // "中型罐式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H25")); // "中型平板货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H26")); // "中型集装箱车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H27")); // "中型自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H28")); // "中型特殊结构货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H29")); // "中型仓栅式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2A")); // "中型车辆运输车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2B")); // "中型箱式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2C")); // "中型罐式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2D")); // "中型平板自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2E")); // "中型集装箱自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2F")); // "中型特殊结构自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2G")); // "中型仓栅式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H31")); // "轻型普通货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H32")); // "轻型厢式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H33")); // "轻型封闭货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H34")); // "轻型罐式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H35")); // "轻型平板货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H37")); // "轻型自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H38")); // "轻型特殊结构货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H39")); // "轻型仓栅式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3A")); // "轻型车辆运输车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3B")); // "轻型箱式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3C")); // "轻型罐式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3D")); // "轻型平板自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3F")); // "轻型特殊结构自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3G")); // "轻型仓栅式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H41")); // "微型普通货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H42")); // "微型厢式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H43")); // "微型封闭货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H44")); // "微型罐式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H45")); // "微型自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H46")); // "微型特殊结构货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H47")); // "微型仓栅式货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4A")); // "微型车辆运输车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4B")); // "微型厢式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4C")); // "微型罐式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4F")); // "微型特殊结构自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4G")); // "微型仓栅式自卸货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H51")); // "普通低速货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H52")); // "厢式低速货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H53")); // "罐式低速货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H54")); // "自卸低速货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H55")); // "仓栅式低速货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H5B")); // "厢式自卸低速货车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H5C")); // "罐式自卸低速货车") );

    bin = 0x0100;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G11")); // "重型普通全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G12")); // "重型厢式全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G13")); // "重型罐式全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G14")); // "重型平板全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G15")); // "重型集装箱全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G16")); // "重型自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G17")); // "重型仓栅式全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G18")); // "重型旅居全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G19")); // "重型专项作业全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1A")); // "重型厢式自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1B")); // "重型罐式自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1C")); // "重型平板自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1D")); // "重型集装箱自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1E")); // "重型仓栅式自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1F")); // "重型专项作业自卸全挂车") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G21")); // "中型普通全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G22")); // "中型厢式全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G23")); // "中型罐式全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G24")); // "中型平板全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G25")); // "中型集装箱全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G26")); // "中型自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G27")); // "中型仓栅式全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G28")); // "中型旅居全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G29")); // "中型专项作业全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2A")); // "中型厢式自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2B")); // "中型罐式自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2C")); // "中型平板自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2D")); // "中型集装箱自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2E")); // "中型仓栅式自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2F")); // "中型专项作业自卸全挂车") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G31")); // "轻型普通全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G32")); // "轻型厢式全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G33")); // "轻型罐式全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G34")); // "轻型平板全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G35")); // "轻型自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G36")); // "轻型仓栅式全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G37")); // "轻型旅居全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G38")); // "轻型专项作业全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3A")); // "轻型厢式自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3B")); // "轻型罐式自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3C")); // "轻型平板自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3D")); // "轻型集装箱自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3E")); // "轻型仓栅式自卸全挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3F")); // "轻型专项作业自卸全挂车") );

    bin = 0x0180;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B11")); // "重型普通半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B12")); // "重型厢式半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B13")); // "重型罐式半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B14")); // "重型平板半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B15")); // "重型集装箱半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B16")); // "重型自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B17")); // "重型特殊结构半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B18")); // "重型仓栅式半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B19")); // "重型旅居半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1A")); // "重型专项作业半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1B")); // "重型低平板半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1C")); // "重型车辆运输半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1D")); // "重型罐式自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1E")); // "重型平板自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1F")); // "重型集装箱自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1G")); // "重型特殊结构自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1H")); // "重型仓栅式自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1J")); // "重型专项作业自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1K")); // "重型低平板自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1U")); // "重型中置轴旅居挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1V")); // "重型中置轴车辆运输车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1W")); // "重型中置轴普通挂车") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B21")); // "中型普通半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B22")); // "中型厢式半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B23")); // "中型罐式半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B24")); // "中型平板半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B25")); // "中型集装箱半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B26")); // "中型自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B27")); // "中型特殊结构半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B28")); // "中型仓栅式半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B29")); // "中型旅居半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2A")); // "中型专项作业半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2B")); // "中型低平板半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2C")); // "中型车辆运输半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2D")); // "中型罐式自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2E")); // "中型平板自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2F")); // "中型集装箱自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2G")); // "中型特殊结构自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2H")); // "中型仓栅式自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2J")); // "中型专项作业自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2K")); // "中型低平板自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2U")); // "中型中置轴旅居挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2V")); // "中型中置轴车辆运输车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2W")); // "中型中置轴普通挂车") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B31")); // "轻型普通半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B32")); // "轻型厢式半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B33")); // "轻型罐式半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B34")); // "轻型平板半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B35")); // "轻型自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B36")); // "轻型仓栅式半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B37")); // "轻型旅居半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B38")); // "轻型专项作业半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B39")); // "轻型低平板半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3C")); // "轻型车辆运输半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3D")); // "轻型罐式自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3E")); // "轻型平板自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3F")); // "轻型集装箱自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3G")); // "轻型特殊结构自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3H")); // "轻型仓栅式自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3J")); // "轻型专项作业自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3K")); // "轻型低平板自卸半挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3U")); // "轻型中置轴旅居挂车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3V")); // "轻型中置轴车辆运输车") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3W")); // "轻型中置轴普通挂车") );

    bin = 0x0000;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "X99")); // "其他") );
}

void CarMsgCompare::init_mCarPlateType()
{
    char hex = 0x00;
    hex++; mCarPlateType.insert(pair<char, string>(hex, "大型汽车")); //0001
    hex++; mCarPlateType.insert(pair<char, string>(hex, "小型汽车")); //0010
    hex++; mCarPlateType.insert(pair<char, string>(hex, "使馆汽车")); //0011
    hex++; mCarPlateType.insert(pair<char, string>(hex, "领馆汽车")); //0100
    hex++; mCarPlateType.insert(pair<char, string>(hex, "境外汽车")); //0101
    hex++; mCarPlateType.insert(pair<char, string>(hex, "外籍汽车")); //0110
    hex++; mCarPlateType.insert(pair<char, string>(hex, "低速车"));   //0111
    hex++; mCarPlateType.insert(pair<char, string>(hex, "教练汽车")); //1000
    hex++; mCarPlateType.insert(pair<char, string>(hex, "摩托车"));   //1001
    hex++; mCarPlateType.insert(pair<char, string>(hex, "新能源汽车")); //1010
    hex++; mCarPlateType.insert(pair<char, string>(hex, "警用汽车"));  //1011
    hex++; mCarPlateType.insert(pair<char, string>(hex, "港澳两地车")); //1100
    hex++; mCarPlateType.insert(pair<char, string>(hex, "武警车辆"));  //1101
    hex++; mCarPlateType.insert(pair<char, string>(hex, "军队车辆"));  //1110
    hex = 0x00;
    mCarPlateType.insert(pair<char, string>(hex, "其他车辆")); //0000
}

void CarMsgCompare::init_mSerialNum()
{
    char bin = 0x00;
    mSerialNum.insert(pair<char, char>(bin, 'A')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'B')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'C')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'D')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'E')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'F')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'G')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'H')); bin++;
   // mSerialNum.insert(pair<char, char>(bin, 'I')); bin++; 保留
    bin++;
    mSerialNum.insert(pair<char, char>(bin, 'J')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'K')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'L')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'M')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'N')); bin++;
   // mSerialNum.insert(pair<char, char>(bin, 'O')); bin++; 保留
    bin++;
    mSerialNum.insert(pair<char, char>(bin, 'P')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'Q')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'R')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'S')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'T')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'U')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'V')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'W')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'X')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'Y')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'Z')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '0')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '1')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '2')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '3')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '4')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '5')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '6')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '7')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '8')); bin++;
    mSerialNum.insert(pair<char, char>(bin, '9')); bin++;
}

void CarMsgCompare::init_mCarColor()
{
    char colorbin = 0x00;
    mCarColor.insert(pair<char, string>(colorbin, "白")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "灰")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "黄")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "粉")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "红")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "紫")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "绿")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "蓝")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "棕")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "黑"));
    colorbin = 0x0F;
    mCarColor.insert(pair<char, string>(colorbin, "其他"));

}

//取得发牌代号 返回"京B"
string CarMsgCompare::GetDealCode(char* code)
{
    if( NULL == code)
    {
        return ERROR_MSG;
    }
    string dealCode = "";
    map<char, string>::iterator it_pro;
    //qDebug() << "into";
    //qDebug("%02x",code[0]);
    //code[0] = 0x10;
    it_pro = mProvinceCodeAndBit.find(code[0]);
    if( it_pro != mProvinceCodeAndBit.end() )
    {
        dealCode += it_pro->second;
    }
    else
    {
        dealCode.append("未找到");
    }

    //qDebug() << dealCode.c_str();
    //qDebug("%02x",code[1]);
    //code[1] = 0x13;
    map<char, char>::iterator it;
    it = mDealCodeBit.find(code[1]);
    if( it != mDealCodeBit.end() )
    {
        char tmp[10] = {0};
        sprintf(tmp,"%c",it->second);
        dealCode.append( tmp );
    }
    else
    {
        dealCode.append("未找到");
    }


    return dealCode;
}


//取得使用性质
string CarMsgCompare::GetUseType(char code)
{
    string useType;
    map<char, string>::iterator it;
    it = mCarUseType.find(code);
    if( it != mCarUseType.end() )
    {
        useType = it->second;
    }else{
        useType = "未找到";
    }
    return useType;
}


string CarMsgCompare::GetCarColor(char code)
{
    //qDebug("%02x",code);
    string color;
    map<char, string>::iterator it;
    it = mCarColor.find(code);
    if(it != mCarColor.end())
    {
        color = it->second;
    }else{
        color = "未找到";
    }
    return color;

}


string CarMsgCompare::GetCarType(char* code)
{
    string cartype;
    short i;
    unShortChar ct;

    ct.ch[0] = code[0];
    ct.ch[1] = code[1];

    i = ct.s;
    //map<short int, string> mCarTypeBitAndCode;
    map<short int, string>::iterator itbite;
    itbite = mCarTypeBitAndCode.find(i);
    if(itbite != mCarTypeBitAndCode.end())
    {
        cartype += itbite->second;
    }else{
        cartype += "未找到";
    }

    //map<short int, string> mCarTypeAndBit;
    map<short int, string>::iterator it;
    it = mCarTypeAndBit.find(i);
    if(it != mCarTypeAndBit.end())
    {
        cartype += it->second;
    }else{
        cartype += "未找到";
    }


    return cartype;
}


string CarMsgCompare::GetCarNum(char* code,int codenum)
{
    string carnum;
    for(int i = 0;i < codenum;i++)
    {
        char tmp = code[i];
        //qDebug("%02x",tmp);
        // map<char, char> mSerialNum;
        map<char, char>::iterator it;
        it = mSerialNum.find(tmp);
        if(it != mSerialNum.end())
        {
            carnum += it->second;
        }else{
            carnum += "未找到";
        }
        //qDebug() << carnum.c_str();
    }
    return carnum;
}

string CarMsgCompare::GetPlateType(char code)
{
    string plateType;
    map<char, string>::iterator it;
    it = mCarPlateType.find(code);
    if(it != mCarPlateType.end())
    {
        plateType = it->second;
    }
    else
    {
        plateType = "未找到";
    }
    return plateType;
}

//解析卡号数据，msg为5字节，type为0表示获取省份名称，type为1代表获取省份简称
//返回0代表交通管理机关发行卡，1表示新车出厂预装卡,-1表示出错
string CarMsgCompare::GetCardInfo(unsigned char* msg )
{
    if( NULL == msg )
    {
        return ERROR_MSG;
    }
    string card;
    int cardtype;
    if( 0x00 ==  ((msg[0]>>4) & 0x01) )
    {
        cardtype = 0;
        card += "交通管理机关发型卡-";
    }
    else{
        cardtype = 1;
        card += "新车出厂预装卡-";
    }
    // map<char, string> mProvince_BitAndName;
    char hex = 0x00;
    hex = ( ((msg[0]<<2)&0x3C) | ((msg[1]>>6)&0x03) ) & 0x3F;
    //qDebug("%02x",hex);
    map<char, string>::iterator it;
    it = mProvince_BitAndName.find(hex);
    if( it != mProvince_BitAndName.end() )
    {
        //char cord[3] = {0};
        //sprintf(cord, "%d-", it->second);
        card.append(it->second);
        card.append("-");
    }
    else
    {
        card.append( "未找到-" );
    }
    char sn[13];
    sn[0] = msg[1]&0x3F;
    sprintf(sn, "%d%d%d%d", (int)msg[1]&0x3F, (int)msg[2], (int)msg[3], (int)msg[4] );

    card.append(sn);


    return card;
}

