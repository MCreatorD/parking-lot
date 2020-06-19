
#ifndef SPI_COMMUNICATION_H_
#define SPI_COMMUNICATION_H_

#include <stdint.h>

#define SPI_MAX_LEN 1024
using namespace std;

#define SPI1_Device  0
#define SPI2_Device  1
#define SIM_SPI0_Device 2
#define SIM_SPI1_Device 3

class SPI_Communication {
public:
	SPI_Communication();
	virtual ~SPI_Communication();

private:
	//uint8_t rxBuffer[SPI_MAX_LEN];
	//uint8_t txBuffer[SPI_MAX_LEN];

private:
//	//char *deviceName;
//	uint8_t SPIMode;
//	//uint8_t lsb;
//	uint8_t SPIBits;
//	uint32_t SPISpeed;
//	uint16_t SPIDelay;

	int SPI_ID; //SPI的设备代号

public:
	void initSPIDevice(int spiid); //初始化SPI，在类被使用前必须初始化

public:
	bool transfer(int spiid, uint8_t *pout, uint8_t *pin, uint16_t len);
	bool readSPIData(uint8_t *recbuf,int datalen);
	bool writeSPIData(uint8_t *sendbuf,int datalen);
};

#endif /* SPI_COMMUNICATION_H_ */
