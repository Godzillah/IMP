/**
 * author  : Maroš Orsák (xorsak02)
 * file	   : rtc.c
 * created : 12.11.2019
 */

#include "../libs/rtc.h"

void enableRegisterSpaceClock() {
	SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;
	printf("\r\n[INFO] - RTC module register space clock enabled...");
}

/**
 * Function which, clearing all register using SWR bit.
 */
void clearRtcRegisters() {
	printf("\r\n[INFO] - Clearing all RTC register except for the SWR bit.");
	RTC->CR  = RTC_CR_SWR_MASK;
	RTC->CR  &= ~RTC_CR_SWR_MASK;
	printf("\r\n[INFO] - RTC module reset done.");
}

/**
 * Function which, clears pending interrupt request and enable RTC
 */
void clearPendingInterrupt() {
	// Clears nested vectored interrupt controller pending interrupt request
	NVIC_ClearPendingIRQ(66);
	// enable the interrupt for RTC
	NVIC_EnableIRQ(66);
	printf("\r\n[INFO] - NVIC interrupt for RTC module enabled.");
}

void enableOscillator() {
	printf("\r\n[INFO] - RTC module oscillator enabling.");
	RTC->CR |= RTC_CR_OSCE_MASK;
	printf("\r\n[INFO] - RTC module oscillator enabled.");
}

void waitUntilOscillatorWillBeStable() {
	// after setting this bit, wait the oscillator startup time before enabling the time counter to allow the 32.768kHz clock time to stabilize
	for(unsigned int i=0; i<0x600000; i++);
	printf("\r\n[INFO] - RTC module oscillator stable.");
}

/**
 * Set Time compensation register to zero
 */
void setTcrToZero() {
	RTC->TCR = RTC_TCR_CIR(0) | RTC_TCR_TCR(0);
}


void setTsrAndTarRegisters(uint32_t seconds, uint32_t alarm) {
	printf("\r\n[INFO] - Setting TSR:|%X| and TAR:|%X|", seconds, alarm);
	RTC->TSR = seconds;
	RTC->TAR = alarm;
}

/**
 * Enable Time Counter Enable, for incrementing value of TSR register using TCE mask
 */
void enableTce() {
	printf("\r\n[INFO] - Enabling Time Counter Enable, which will increment TSR register using TCE MASK");
	RTC->SR |= RTC_SR_TCE_MASK;
}

/**
 * seconds setting TSR register, from where we want to starting counting
 * alarm   setting TAR register, form where we want to interruption
 */
void initRealTimeClock(uint32_t seconds, uint32_t alarm) {
	printf("\r[INFO] - This example generates an interrupt every 5 seconds!");
	enableRegisterSpaceClock();
	clearRtcRegisters();
	clearPendingInterrupt();
	enableOscillator();
	waitUntilOscillatorWillBeStable();
	setTcrToZero();
	setTsrAndTarRegisters(seconds, alarm);
	enableTce();
}
