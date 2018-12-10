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

//���������ձ� <������,�������> <0x88, "����">
void CarMsgCompare::init_dataType()
{
    short int data;
    data = 0x8801; mDataType.insert(pair<short int, string>(data,"����") );
    data = 0x8802; mDataType.insert(pair<short int, string>(data, "���ƴ���") );
    data = 0x8803; mDataType.insert(pair<short int, string>(data, "ʹ������") );
    data = 0x8804; mDataType.insert(pair<short int, string>(data, "��������") );
    data = 0x8805; mDataType.insert(pair<short int, string>(data, "��������") );
    data = 0x8806; mDataType.insert(pair<short int, string>(data, "����") );
    data = 0x8807; mDataType.insert(pair<short int, string>(data, "����") );
    data = 0x8808; mDataType.insert(pair<short int, string>(data, "��������") );
    data = 0x8809; mDataType.insert(pair<short int, string>(data, "���ƺ������") );
    data = 0x880A; mDataType.insert(pair<short int, string>(data, "������Ч��") );
    data = 0x880B; mDataType.insert(pair<short int, string>(data, "ǿ�Ʊ�����") );
    data = 0x880C; mDataType.insert(pair<short int, string>(data, "�˶��ؿ�/������") );
    data = 0x880D; mDataType.insert(pair<short int, string>(data, "������ɫ") );
}
//ʡ�ݴ������ʡ�� <ʡ�ݴ��룬ʡ��> <11,"����">
void CarMsgCompare::init_Province_CodeAndName()
{
    mProvince_CodeAndName.insert(pair<int, string>(11, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(12, "���"));
    mProvince_CodeAndName.insert(pair<int, string>(13, "�ӱ�"));
    mProvince_CodeAndName.insert(pair<int, string>(14, "ɽ��"));
    mProvince_CodeAndName.insert(pair<int, string>(15, "���ɹ�"));
    mProvince_CodeAndName.insert(pair<int, string>(21, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(22, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(23, "������"));
    mProvince_CodeAndName.insert(pair<int, string>(31, "�Ϻ�"));
    mProvince_CodeAndName.insert(pair<int, string>(32, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(33, "�㽭"));
    mProvince_CodeAndName.insert(pair<int, string>(34, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(35, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(36, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(37, "ɽ��"));
    mProvince_CodeAndName.insert(pair<int, string>(41, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(42, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(43, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(44, "�㶫"));
    mProvince_CodeAndName.insert(pair<int, string>(45, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(46, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(50, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(51, "�Ĵ�"));
    mProvince_CodeAndName.insert(pair<int, string>(52, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(53, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(54, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(61, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(62, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(63, "�ຣ"));
    mProvince_CodeAndName.insert(pair<int, string>(64, "����"));
    mProvince_CodeAndName.insert(pair<int, string>(65, "�½�"));
    mProvince_CodeAndName.insert(pair<int, string>(71, "���"));
    mProvince_CodeAndName.insert(pair<int, string>(82, "����"));
}
//�����ƶ���ʡ�ݴ��� <�����Ʊ��룬ʡ�ݴ���> <0000001,11>��������
void CarMsgCompare::init_mProvince_BitAndCode()
{
    char bin = 0x00; //�����Ʊ���

    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 11)); //"����")); //0000001
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 12)); //"���")); //0000010
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 13)); //"�ӱ�")); //0000011
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 14)); //"ɽ��")); //0000100
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 15)); //"���ɹ�")); //0000101
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 21)); //"����"));  //0000110
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 22)); //"����"));  //0000111
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 23)); //"������")); //0001000
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 31)); //"�Ϻ�"));  //0001001
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 32)); //"����"));  //0001010
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 33)); //"�㽭"));  //0001011
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 34)); //"����"));  //0001100
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 35)); //"����"));  //0001101
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 36)); //"����"));  //0001110
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 37)); //"ɽ��"));  //0001111

    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 41)); //"����"));  //0010000
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 42)); //"����"));  //0010001
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 43)); //"����"));  //0010010
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 44)); //"�㶫"));  //0010011
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 45)); //"����"));  //0010100
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 46)); //"����"));  //0010101
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 50)); //"����"));  //0010110
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 51)); //"�Ĵ�"));  //0010111
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 52)); //"����"));  //0011000
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 53)); //"����"));  //0011001
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 54)); //"����"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 61)); //"����"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 62)); //"����"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 63)); //"�ຣ"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 64)); //"����"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 65)); //"�½�"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 71)); //"���"));
    bin++; mProvince_BitAndCode.insert(pair<char, int>(bin, 82)); //"����"));
}
//ʡ�ݶ��ն����ƴ��� <�����Ʊ��룬ʡ������> <0000001, "����">
void CarMsgCompare::init_mProvin_BitAndName()
{
    char bin = 0x00; //�����Ʊ���

    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����")); //0000001
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "���")); //0000010
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "�ӱ�")); //0000011
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "ɽ��")); //0000100
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "���ɹ�")); //0000101
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0000110
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0000111
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "������")); //0001000
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "�Ϻ�"));  //0001001
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0001010
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "�㽭"));  //0001011
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0001100
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0001101
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0001110
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "ɽ��"));  //0001111

    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0010000
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0010001
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0010010
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "�㶫"));  //0010011
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0010100
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0010101
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0010110
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "�Ĵ�"));  //0010111
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0011000
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));  //0011001
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "�ຣ"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "�½�"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "���"));
    bin++; mProvince_BitAndName.insert(pair<char, string>(bin, "����"));
}
//ʡ�ݼ�� <�����ƣ�ʡ�ݼ��> <0000001, "��">
void CarMsgCompare::init_mProvinceCodeAndBit()
{
    char bin = 0x00;

    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "³"));

    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "ԥ"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
    bin++; mProvinceCodeAndBit.insert(pair<char, string>(bin, "��"));
}
//���ƴ�����Ŷ��ն����� <������,���>
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
//���ƴ�����ն����� <�����ƣ����ƴ���> <00000, 'A'>
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
    hex = 0x08; mCarUseType.insert( pair<char, string>(hex, "��Ӫ��") );
    hex = 0x01; mCarUseType.insert( pair<char, string>(hex, "��·���ˡ����ο���") );
    hex = 0x02; mCarUseType.insert( pair<char, string>(hex, "��������") );
    hex = 0x03; mCarUseType.insert( pair<char, string>(hex, "�������") );
    hex = 0x04; mCarUseType.insert( pair<char, string>(hex, "����") );
    hex = 0x05; mCarUseType.insert( pair<char, string>(hex, "����") );
    hex = 0x0C; mCarUseType.insert( pair<char, string>(hex, "���á��������Ȼ�����������") );
    hex = 0x0F; mCarUseType.insert( pair<char, string>(hex, "������") );
    hex = 0x0D; mCarUseType.insert( pair<char, string>(hex, "�׶�У����Сѧ��У��������У��") );
    hex = 0x0E; mCarUseType.insert( pair<char, string>(hex, "Σ��Ʒ����") );
    hex = 0x07; mCarUseType.insert( pair<char, string>(hex, "����") );

}

void CarMsgCompare::init_mCarTypeNumAndBit()
{

}

void CarMsgCompare::init_mCarTypeAndBit()
{
    short int bin;
    bin = 0x0000;
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨ�ͳ�") ); //000000001  K11
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����˫��ͳ�") ); //000000010
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�������̿ͳ�") ); //000000011
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͽ½ӿͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ԽҰ�ͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͽγ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר�ÿͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר��У��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨ�ͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����˫��ͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�������̿ͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͽ½ӿͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ԽҰ�ͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͽγ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר�ÿͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר��У��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "С����ͨ�ͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "С��ԽҰ�ͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "С���ų�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "С��ר�ÿͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "С��ר��У��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "С�������") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢����ͨ�ͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢��ԽҰ�ͳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢�ͽγ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢�������") );   //000011010 K49

    bin = 0x0040; //001000000 Q11
    mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͱ��ǣ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ȫ��ǣ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͱ��ǣ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ȫ��ǣ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͱ��ǣ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ȫ��ǣ����") );

    bin = 0x0050; //001010000 Z11
    mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "С�ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "С���ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢�ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢���ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����ػ�ר����ҵ��") );

    bin = 0x0060;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "��ͨ������Ħ�г�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���������Ħ�г�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����ؿ���Ħ�г�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�������ػ�Ħ�г�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������Ħ�г�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ͨ����Ħ�г�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������Ħ�г�") );

    bin = 0x0068; mCarTypeAndBit.insert( pair<short int, string>(bin, "�޹�糵") );
    bin = 0x0069; mCarTypeAndBit.insert( pair<short int, string>(bin, "�й�糵") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ʽװ�ػ�е") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ʽ�ھ��е") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ʽƽ�ػ�е") );

    bin = 0x0080;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͷ�ջ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ�����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ�ᳵ") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͳ������䳵") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ����ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ����ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͷ�ջ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ�����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ�䳵") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͳ������䳵") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ����ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ����ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͷ�ջ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ�����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͳ������䳵") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ����ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢����ͨ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢����ʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢�ͷ�ջ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢�͹�ʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢����ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢������ṹ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢�Ͳ�դʽ����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢�ͳ������䳵") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢����ʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢�͹�ʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢������ṹ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "΢�Ͳ�դʽ��ж����") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ͨ���ٻ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ʽ���ٻ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ʽ���ٻ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ж���ٻ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��դʽ���ٻ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ʽ��ж���ٻ���") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��ʽ��ж���ٻ���") );

    bin = 0x0100;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ��ȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ��ȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����þ�ȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ��жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ����жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ����жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵ��жȫ�ҳ�") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ��ȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ��ȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����þ�ȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ��жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ����жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ����жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵ��жȫ�ҳ�") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ��ȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����þ�ȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ��жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ����жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ����жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��жȫ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵ��жȫ�ҳ�") );

    bin = 0x0180;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ���ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ���ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����þӰ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͵�ƽ���ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͳ��������ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ����ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ����ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͵�ƽ����ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����������þӹҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���������ᳵ�����䳵") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������������ͨ�ҳ�") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ���ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ���ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����þӰ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͵�ƽ���ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͳ��������ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ����ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ����ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͵�ƽ����ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����������þӹҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���������ᳵ�����䳵") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������������ͨ�ҳ�") );

    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ͨ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ʽ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ���ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����þӰ�ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵ��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͵�ƽ���ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͳ��������ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͹�ʽ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ƽ����ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���ͼ�װ����ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "��������ṹ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���Ͳ�դʽ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "����ר����ҵ��ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���͵�ƽ����ж��ҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "�����������þӹҳ�") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "���������ᳵ�����䳵") );
    bin++; mCarTypeAndBit.insert( pair<short int, string>(bin, "������������ͨ�ҳ�") );

    bin = 0x0000;
    mCarTypeAndBit.insert( pair<short int, string>(bin, "����") );

}


void CarMsgCompare::init_mCarTypeBitAndCode()
{
    short int bin;
    bin = 0x0000;
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K11")); // "������ͨ�ͳ�") ); //000000001  K11
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K12")); // "����˫��ͳ�") ); //000000010
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K13")); // "�������̿ͳ�") ); //000000011
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K14")); // "���ͽ½ӿͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K15")); // "����ԽҰ�ͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K16")); // "���ͽγ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K17")); // "����ר�ÿͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K18")); // "����ר��У��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K21")); // "������ͨ�ͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K22")); // "����˫��ͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K23")); // "�������̿ͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K24")); // "���ͽ½ӿͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K25")); // "����ԽҰ�ͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K26")); // "���ͽγ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K27")); // "����ר�ÿͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K28")); // "����ר��У��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K31")); // "С����ͨ�ͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K32")); // "С��ԽҰ�ͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K33")); // "С���ų�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K34")); // "С��ר�ÿͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K38")); // "С��ר��У��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K39")); // "С�������") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K41")); // "΢����ͨ�ͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K42")); // "΢��ԽҰ�ͳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K43")); // "΢�ͽγ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "K49")); // "΢�������") );   //000011010 K49

    bin = 0x0040; //001000000 Q11
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q11")); // "���Ͱ��ǣ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q12")); // "����ȫ��ǣ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q21")); // "���Ͱ��ǣ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q22")); // "����ȫ��ǣ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q31")); // "���Ͱ��ǣ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Q32")); // "����ȫ��ǣ����") );

    bin = 0x0050; //001010000 Z11
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z11")); // "���ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z12")); // "�����ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z21")); // "���ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z22")); // "�����ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z31")); // "С�ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z32")); // "С���ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z41")); // "΢�ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z42")); // "΢���ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z51")); // "���ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z52")); // "�����ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z71")); // "���ͷ��ػ�ר����ҵ��") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "Z72")); // "�����ػ�ר����ҵ��") );

    bin = 0x0060;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M11")); // "��ͨ������Ħ�г�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M12")); // "���������Ħ�г�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M13")); // "�����ؿ���Ħ�г�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M14")); // "�������ػ�Ħ�г�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M15")); // "������Ħ�г�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M21")); // "��ͨ����Ħ�г�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "M22")); // "������Ħ�г�") );

    bin = 0x0068; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "D11")); // "�޹�糵") );
    bin = 0x0069; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "D12")); // "�й�糵") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "N11")); // "��������") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "J11")); // "��ʽװ�ػ�е") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "J12")); // "��ʽ�ھ��е") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "J13")); // "��ʽƽ�ػ�е") );

    bin = 0x0080;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H11")); // "������ͨ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H12")); // "������ʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H13")); // "���ͷ�ջ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H14")); // "���͹�ʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H15")); // "����ƽ�����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H16")); // "���ͼ�װ�ᳵ") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H17")); // "������ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H18")); // "��������ṹ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H19")); // "���Ͳ�դʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1A")); // "���ͳ������䳵") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1B")); // "������ʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1C")); // "���͹�ʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1D")); // "����ƽ����ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1E")); // "���ͼ�װ����ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1F")); // "��������ṹ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H1G")); // "���Ͳ�դʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H21")); // "������ͨ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H22")); // "������ʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H23")); // "���ͷ�ջ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H24")); // "���͹�ʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H25")); // "����ƽ�����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H26")); // "���ͼ�װ�䳵") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H27")); // "������ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H28")); // "��������ṹ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H29")); // "���Ͳ�դʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2A")); // "���ͳ������䳵") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2B")); // "������ʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2C")); // "���͹�ʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2D")); // "����ƽ����ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2E")); // "���ͼ�װ����ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2F")); // "��������ṹ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H2G")); // "���Ͳ�դʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H31")); // "������ͨ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H32")); // "������ʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H33")); // "���ͷ�ջ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H34")); // "���͹�ʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H35")); // "����ƽ�����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H37")); // "������ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H38")); // "��������ṹ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H39")); // "���Ͳ�դʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3A")); // "���ͳ������䳵") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3B")); // "������ʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3C")); // "���͹�ʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3D")); // "����ƽ����ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3F")); // "��������ṹ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H3G")); // "���Ͳ�դʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H41")); // "΢����ͨ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H42")); // "΢����ʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H43")); // "΢�ͷ�ջ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H44")); // "΢�͹�ʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H45")); // "΢����ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H46")); // "΢������ṹ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H47")); // "΢�Ͳ�դʽ����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4A")); // "΢�ͳ������䳵") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4B")); // "΢����ʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4C")); // "΢�͹�ʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4F")); // "΢������ṹ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H4G")); // "΢�Ͳ�դʽ��ж����") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H51")); // "��ͨ���ٻ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H52")); // "��ʽ���ٻ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H53")); // "��ʽ���ٻ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H54")); // "��ж���ٻ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H55")); // "��դʽ���ٻ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H5B")); // "��ʽ��ж���ٻ���") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "H5C")); // "��ʽ��ж���ٻ���") );

    bin = 0x0100;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G11")); // "������ͨȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G12")); // "������ʽȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G13")); // "���͹�ʽȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G14")); // "����ƽ��ȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G15")); // "���ͼ�װ��ȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G16")); // "������жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G17")); // "���Ͳ�դʽȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G18")); // "�����þ�ȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G19")); // "����ר����ҵȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1A")); // "������ʽ��жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1B")); // "���͹�ʽ��жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1C")); // "����ƽ����жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1D")); // "���ͼ�װ����жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1E")); // "���Ͳ�դʽ��жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G1F")); // "����ר����ҵ��жȫ�ҳ�") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G21")); // "������ͨȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G22")); // "������ʽȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G23")); // "���͹�ʽȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G24")); // "����ƽ��ȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G25")); // "���ͼ�װ��ȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G26")); // "������жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G27")); // "���Ͳ�դʽȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G28")); // "�����þ�ȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G29")); // "����ר����ҵȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2A")); // "������ʽ��жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2B")); // "���͹�ʽ��жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2C")); // "����ƽ����жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2D")); // "���ͼ�װ����жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2E")); // "���Ͳ�դʽ��жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G2F")); // "����ר����ҵ��жȫ�ҳ�") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G31")); // "������ͨȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G32")); // "������ʽȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G33")); // "���͹�ʽȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G34")); // "����ƽ��ȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G35")); // "������жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G36")); // "���Ͳ�դʽȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G37")); // "�����þ�ȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G38")); // "����ר����ҵȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3A")); // "������ʽ��жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3B")); // "���͹�ʽ��жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3C")); // "����ƽ����жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3D")); // "���ͼ�װ����жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3E")); // "���Ͳ�դʽ��жȫ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "G3F")); // "����ר����ҵ��жȫ�ҳ�") );

    bin = 0x0180;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B11")); // "������ͨ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B12")); // "������ʽ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B13")); // "���͹�ʽ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B14")); // "����ƽ���ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B15")); // "���ͼ�װ���ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B16")); // "������ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B17")); // "��������ṹ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B18")); // "���Ͳ�դʽ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B19")); // "�����þӰ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1A")); // "����ר����ҵ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1B")); // "���͵�ƽ���ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1C")); // "���ͳ��������ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1D")); // "���͹�ʽ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1E")); // "����ƽ����ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1F")); // "���ͼ�װ����ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1G")); // "��������ṹ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1H")); // "���Ͳ�դʽ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1J")); // "����ר����ҵ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1K")); // "���͵�ƽ����ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1U")); // "�����������þӹҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1V")); // "���������ᳵ�����䳵") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B1W")); // "������������ͨ�ҳ�") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B21")); // "������ͨ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B22")); // "������ʽ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B23")); // "���͹�ʽ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B24")); // "����ƽ���ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B25")); // "���ͼ�װ���ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B26")); // "������ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B27")); // "��������ṹ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B28")); // "���Ͳ�դʽ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B29")); // "�����þӰ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2A")); // "����ר����ҵ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2B")); // "���͵�ƽ���ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2C")); // "���ͳ��������ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2D")); // "���͹�ʽ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2E")); // "����ƽ����ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2F")); // "���ͼ�װ����ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2G")); // "��������ṹ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2H")); // "���Ͳ�դʽ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2J")); // "����ר����ҵ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2K")); // "���͵�ƽ����ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2U")); // "�����������þӹҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2V")); // "���������ᳵ�����䳵") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B2W")); // "������������ͨ�ҳ�") );

    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B31")); // "������ͨ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B32")); // "������ʽ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B33")); // "���͹�ʽ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B34")); // "����ƽ���ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B35")); // "������ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B36")); // "���Ͳ�դʽ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B37")); // "�����þӰ�ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B38")); // "����ר����ҵ��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B39")); // "���͵�ƽ���ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3C")); // "���ͳ��������ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3D")); // "���͹�ʽ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3E")); // "����ƽ����ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3F")); // "���ͼ�װ����ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3G")); // "��������ṹ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3H")); // "���Ͳ�դʽ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3J")); // "����ר����ҵ��ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3K")); // "���͵�ƽ����ж��ҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3U")); // "�����������þӹҳ�") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3V")); // "���������ᳵ�����䳵") );
    bin++; mCarTypeBitAndCode.insert( pair<short int, string>(bin, "B3W")); // "������������ͨ�ҳ�") );

    bin = 0x0000;
    mCarTypeBitAndCode.insert( pair<short int, string>(bin, "X99")); // "����") );
}

void CarMsgCompare::init_mCarPlateType()
{
    char hex = 0x00;
    hex++; mCarPlateType.insert(pair<char, string>(hex, "��������")); //0001
    hex++; mCarPlateType.insert(pair<char, string>(hex, "С������")); //0010
    hex++; mCarPlateType.insert(pair<char, string>(hex, "ʹ������")); //0011
    hex++; mCarPlateType.insert(pair<char, string>(hex, "�������")); //0100
    hex++; mCarPlateType.insert(pair<char, string>(hex, "��������")); //0101
    hex++; mCarPlateType.insert(pair<char, string>(hex, "�⼮����")); //0110
    hex++; mCarPlateType.insert(pair<char, string>(hex, "���ٳ�"));   //0111
    hex++; mCarPlateType.insert(pair<char, string>(hex, "��������")); //1000
    hex++; mCarPlateType.insert(pair<char, string>(hex, "Ħ�г�"));   //1001
    hex++; mCarPlateType.insert(pair<char, string>(hex, "����Դ����")); //1010
    hex++; mCarPlateType.insert(pair<char, string>(hex, "��������"));  //1011
    hex++; mCarPlateType.insert(pair<char, string>(hex, "�۰����س�")); //1100
    hex++; mCarPlateType.insert(pair<char, string>(hex, "�侯����"));  //1101
    hex++; mCarPlateType.insert(pair<char, string>(hex, "���ӳ���"));  //1110
    hex = 0x00;
    mCarPlateType.insert(pair<char, string>(hex, "��������")); //0000
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
   // mSerialNum.insert(pair<char, char>(bin, 'I')); bin++; ����
    bin++;
    mSerialNum.insert(pair<char, char>(bin, 'J')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'K')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'L')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'M')); bin++;
    mSerialNum.insert(pair<char, char>(bin, 'N')); bin++;
   // mSerialNum.insert(pair<char, char>(bin, 'O')); bin++; ����
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
    mCarColor.insert(pair<char, string>(colorbin, "��")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "��")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "��")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "��")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "��")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "��")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "��")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "��")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "��")); colorbin++;
    mCarColor.insert(pair<char, string>(colorbin, "��"));
    colorbin = 0x0F;
    mCarColor.insert(pair<char, string>(colorbin, "����"));

}

//ȡ�÷��ƴ��� ����"��B"
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
        dealCode.append("δ�ҵ�");
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
        dealCode.append("δ�ҵ�");
    }


    return dealCode;
}


//ȡ��ʹ������
string CarMsgCompare::GetUseType(char code)
{
    string useType;
    map<char, string>::iterator it;
    it = mCarUseType.find(code);
    if( it != mCarUseType.end() )
    {
        useType = it->second;
    }else{
        useType = "δ�ҵ�";
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
        color = "δ�ҵ�";
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
        cartype += "δ�ҵ�";
    }

    //map<short int, string> mCarTypeAndBit;
    map<short int, string>::iterator it;
    it = mCarTypeAndBit.find(i);
    if(it != mCarTypeAndBit.end())
    {
        cartype += it->second;
    }else{
        cartype += "δ�ҵ�";
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
            carnum += "δ�ҵ�";
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
        plateType = "δ�ҵ�";
    }
    return plateType;
}

//�����������ݣ�msgΪ5�ֽڣ�typeΪ0��ʾ��ȡʡ�����ƣ�typeΪ1�����ȡʡ�ݼ��
//����0����ͨ������ط��п���1��ʾ�³�����Ԥװ��,-1��ʾ����
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
        card += "��ͨ������ط��Ϳ�-";
    }
    else{
        cardtype = 1;
        card += "�³�����Ԥװ��-";
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
        card.append( "δ�ҵ�-" );
    }
    char sn[13];
    sn[0] = msg[1]&0x3F;
    sprintf(sn, "%d%d%d%d", (int)msg[1]&0x3F, (int)msg[2], (int)msg[3], (int)msg[4] );

    card.append(sn);


    return card;
}

