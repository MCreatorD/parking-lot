/*
 * ManufacturerFrame.cpp
 *
 *  Created on: 2016-6-21
 *      Author: root
 */
#include "main_application.h"
#include "ManufacturerFrame.h"

ManufacturerFrame::ManufacturerFrame() {
	// TODO Auto-generated constructor stub
//    manufacturerFrame.OperID = operid;
//    manufacturerFrame.Datalen_H = datalen>>8;
//    manufacturerFrame.Datalen_L = datalen;
//    memcpy(manufacturerFrame.DataBuf,databuf,datalen);
}

ManufacturerFrame::~ManufacturerFrame() {
	// TODO Auto-generated destructor stub
}

void ManufacturerFrame::setManufacturerFrame(unsigned char *buf,int len){
    memcpy((unsigned char *)&this->manufacturerFrame,buf,len);
}

STRUCT_ManufacturerFrame *ManufacturerFrame::getManufactureFrame(){
    return &this->manufacturerFrame;
}
