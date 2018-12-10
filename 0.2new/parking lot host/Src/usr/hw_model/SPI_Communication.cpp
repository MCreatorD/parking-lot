/*
 * SPI_Communication.cpp
 *
 *  Created on: 2016-3-9
 *      Author: root
 */

#include <stdio.h>
#include <string.h>

#include "SPI_Communication.h"
#include "sim_spi.h"
#include "sim_spi1.h"
#include "spi.h"

SPI_Communication::SPI_Communication() {
	// TODO Auto-generated constructor stub

	//===========================================//
}

SPI_Communication::~SPI_Communication() {
	// TODO Auto-generated destructor stub
}

void SPI_Communication::initSPIDevice(int spiid){
	SPI_ID = spiid;	
	return;
}

//注意，这里的POUT指是对方的OUT，in指的是对方的in
bool SPI_Communication::transfer(int spiid, uint8_t *pout, uint8_t *pin, uint16_t len)
{
	uint8_t *tx = pin;
	uint8_t	*rx = pout;
	
	switch(spiid){
		case SPI1_Device:
			break;
		case SPI2_Device:
			SPI2_ReadWriteBuf(tx,rx,len);
			break;
		case SIM_SPI0_Device:
			Sim_SPI_ReadWriteBuf(tx,rx,len);
			break;
		case SIM_SPI1_Device:
			Sim_SPI1_ReadWriteBuf(tx,rx,len);
			break;
		default:
			return false;
	}
	return true;
}

bool SPI_Communication::readSPIData(uint8_t *recbuf,int datalen){
	//if(datalen>SPI_MAX_LEN) return false;
	//memset(txBuffer,0xFF,datalen); //读取时，发送的数据为任意数
	uint8_t *tempbuf = new uint8_t[datalen];
	if(transfer(SPI_ID,recbuf,tempbuf,datalen)==true){
		delete [] tempbuf;
		return true;
	}else{
		delete [] tempbuf;
		return false;
	}
}

bool SPI_Communication::writeSPIData(uint8_t *sendbuf,int datalen){
	//if(datalen>SPI_MAX_LEN) return false;
	//memset(rxBuffer,0x00,datalen);
	//memcpy(txBuffer,sendbuf,datalen);
	uint8_t *tempbuf = new uint8_t[datalen];
	if(transfer(SPI_ID,tempbuf,sendbuf,datalen)==true){
		delete [] tempbuf;
		return true;
	}else{
		delete [] tempbuf;
		return false;
	}
}



