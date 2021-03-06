/**
 * author  : Maro� Ors�k (xorsak02)
 * file	   : crc.h
 * created : 20.11.2019
 */
#ifndef SOURCES_CRC_H_
#define SOURCES_CRC_H_

#include "MK60D10.h"
#include "io.h"

void calc16CRCByHardware(uint32_t data, uint32_t polynomial_number);
void calc16CRCByHardwareExample();

void calc32CRCByHardware(uint32_t data, uint32_t polynomial_number);
void calc32CRCByHardwareExample();

#endif /* SOURCES_CRC_H_ */
