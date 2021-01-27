/**
 * author  : Maro� Ors�k (xorsak02)
 * file	   : testUtils.c
 * created : 14.11.2019
 */

#include "../libs/testUtils.h"

int assertEqualsInt(int excepted, int actual) {
	return excepted == actual ? 0 : -1;
}

void help() {
	printf("\r[INFO] - Please choose type of test from the following list:");
	printf("\r\n\t Type -> 1 - RTC test with incrementing tar register");
	printf("\r\n\t Type -> 2 - RTC test with overflow tar register");
	printf("\r\n\t Type -> 3 - MCU buttocns test");
	printf("\r\n\t Type -> 4 - CRC cards test with 16-bit");
	printf("\r\n\t Type -> 5 - CRC cards test with 32-bit");
	printf("\r\n\t Type -> 6 - Watchdog deadlock test\n");
}

void sleep(long long miliseconds) {
  for(long long i = 0; i < miliseconds; i++);
}
