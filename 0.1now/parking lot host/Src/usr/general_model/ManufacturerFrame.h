/*
 * ManufacturerFrame.h
 *
 *  Created on: 2016-6-21
 *      Author: root
 */

#ifndef MANUFACTURERFRAME_H_
#define MANUFACTURERFRAME_H_

typedef struct {
	unsigned char OperID;
	unsigned char Datalen_H;
	unsigned char Datalen_L;
	unsigned char *DataBuf;
	unsigned char CRC16_H; //考虑到llrp协议本身带较验，故crc校验未用
	unsigned char CRC16_L;

}STRUCT_ManufacturerFrame;

class ManufacturerFrame {
public:
    ManufacturerFrame();
	virtual ~ManufacturerFrame();

public:
	STRUCT_ManufacturerFrame manufacturerFrame;

public:
    void setManufacturerFrame(unsigned char *buf,int len);
    STRUCT_ManufacturerFrame *getManufactureFrame();
};

#endif /* MANUFACTURERFRAME_H_ */
