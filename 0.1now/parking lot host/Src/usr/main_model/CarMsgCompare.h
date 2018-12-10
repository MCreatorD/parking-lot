#ifndef CARMSGCOMPARE_H
#define CARMSGCOMPARE_H

#include <map>
#include <string>
using namespace std;
//#include <QDebug>
#define BIGORSMALL true  // true ΪС��
#define ERROR_MSG  "ERROR"
union unShortChar {
    short int s;
    char      ch[2];
};

class CarMsgCompare
{
private:
    map<short int, string> mDataType;  //���������ձ� <������,�������> <0x88, "����">
    map<int, string> mProvince_CodeAndName; //ʡ�ݴ������ʡ�� <ʡ�ݴ��룬ʡ��> <11,"����">
    map<char, int> mProvince_BitAndCode;    //�����ƶ���ʡ�ݴ��� <�����Ʊ��룬ʡ�ݴ���> <0000001,11>��������
    map<char, string> mProvince_BitAndName; //ʡ�ݶ��ն����ƴ��� <�����Ʊ��룬ʡ������> <0000001, "����">
    map<char, string> mProvinceCodeAndBit; //ʡ�ݼ�� <�����ƣ�ʡ�ݼ��> <0000001, "��">
    map<char, int> mDealCodeNum; //���ƴ�����Ŷ��ն����� <������,���>
    map<char, char> mDealCodeBit; //���ƴ�����ն����� <�����ƣ����ƴ���> <00000, A>      �ṩ�ӿ�
    map<char, string> mCarUseType; //ʹ�����ʶ����Ʊ���� <�����Ʊ��룬ʹ������> <1000,"����Ӫ">   �ṩ�ӿ�
    map<short int, int> mCarTypeNumAndBit; //����������Ŷ��ն����Ʊ��� <�����Ʊ��룬�����������> <000000001, 1>
    map<short int, string> mCarTypeAndBit; //�����������ƶ��ն����Ʊ��� <�����Ʊ��룬��������> <000000001, "������ͨ����">
    map<short int, string> mCarTypeBitAndCode; //���������������ճ������ʹ���   <000000001, "K11">
    map<char, string> mCarPlateType; //������������Ʊ���  <0001, "С������">
    map<char, char> mSerialNum; //��Ŷ����Ʊ���   <�����Ʊ��룬��Ԫ>
    map<char, string> mCarColor; //������ɫ <0001,"">
public:
    CarMsgCompare();
    ~CarMsgCompare();


    string GetUseType(char code); //ȡ��ʹ������
    string GetDealCode(char* code);  //ȡ�÷��ƴ��� ����"��A" "��B"
    string GetCarColor(char code);  // ȡ�ó�����ɫ
    string GetCarType(char* code);  // ȡ�ó�������
    string GetCarNum(char* code,int codenum); //ȡ�ú��ƺ������
    string GetPlateType(char code);  //��ú�������
    //�����������ݣ�msgΪ5�ֽڣ�typeΪ0��ʾ��ȡʡ�����ƣ�typeΪ1�����ȡʡ�ݼ��
    //����0����ͨ������ط��п���1��ʾ�³�����Ԥװ��
    string GetCardInfo(unsigned char* msg );



private:
    //��ʼ��
    void init();
    void init_dataType();   //��ʼ�� ���������ձ� <������,�������> <0x88, "����">
    void init_Province_CodeAndName(); //��ʼ�� ʡ�ݴ������ʡ�� <ʡ�ݴ��룬ʡ��> <11,"����">
    void init_mProvince_BitAndCode(); //�����ƶ���ʡ�ݴ��� <�����Ʊ��룬ʡ�ݴ���> <0000001,11>��������
    void init_mProvin_BitAndName(); //ʡ�ݶ��ն����ƴ��� <�����Ʊ��룬ʡ������> <0000001, "����">
    void init_mProvinceCodeAndBit(); //ʡ�ݼ�� <�����ƣ�ʡ�ݼ��> <0000001, "��">
    void init_mDealCodeNum(); //���ƴ�����Ŷ��ն����� <������,���>
    void init_mDealCodeBit();  //���ƴ�����ն����� <�����ƣ����ƴ���> <00000, A>
    void init_mCarUseType();   //ʹ�����ʶ����Ʊ����
    void init_mCarTypeNumAndBit(); //����������Ŷ��ն����Ʊ��� <1, 000000001>
    void init_mCarTypeAndBit();  //�����������ƶ��ն����Ʊ���  <000000001, "������ͨ����">
    void init_mCarTypeBitAndCode();  //���������������ճ������ʹ���   <"������ͨ����", "K11">
    void init_mCarPlateType(); //������������Ʊ���  <0001, "С������">
    void init_mSerialNum();    //��Ŷ����Ʊ���   <�����Ʊ��룬��Ԫ>
    void init_mCarColor();     //������ɫ <0001,"">

};

#endif // CARMSGCOMPARE_H
