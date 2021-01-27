/**
 * author  : Maroš Orsák (xorsak02)
 * file	   : wdog.c
 * created : 21.11.2019
 */

#include "../libs/wdog.h"

void wdogResetInvokeExample() {
	initClockAndPins();
	GPIOB_PDOR ^= LED_D9;                // turn on Diode 9 state
	GPIOB_PDOR ^= LED_D10;               // turn on Diode 10 state
	GPIOB_PDOR ^= LED_D11;               // turn on Diode 11 state
	GPIOB_PDOR ^= LED_D12;               // turn on Diode 12 state
	sleep(40000);

	WDOG_UNLOCK = 0x0000;

	printf("\r\n[IMPORTANT] - Microcontroller has been reseted %i times\n", WDOG_RSTCNT);
}





