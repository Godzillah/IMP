/**
 * author  : Maroš Orsák (xorsak02)
 * file	   : testUtils.h
 * created : 14.11.2019
 */

#ifndef SOURCES_TESTUTILS_H_
#define SOURCES_TESTUTILS_H_

#include "libs/io.h"

void help();
void sleep(long long miliseconds);
int assertEqualsInt(int excepted, int actual);

#endif /* SOURCES_TESTUTILS_H_ */
