/**
 * author  : Maroš Orsák (xorsak02)
 * file	   : rtc.h
 * created : 12.11.2019
 */

#include "MK60D10.h"
#include "libs/io.h"

void enableRegisterSpaceClock();
void clearRtcRegisters();
void clearPendingInterrupt();
void enableOscillator();
void waitUntilOscillatorWillBeStable();
void setTcrToZero();
void setTsrAndTarRegisters(uint32_t seconds, uint32_t alarm);
void enableTce();

void initRealTimeClock(uint32_t seconds, uint32_t alarm); // main function which encapsulate all divided functions
