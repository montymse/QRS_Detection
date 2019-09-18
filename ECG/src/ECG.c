/*
 ============================================================================
 Name        : ECG.c
 Author      : Tala
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"
#include "filters.h"
#include "filterTester.h"
#include "qrs.h"
#include "qrsTester.h"

int main(void) {
	//storeArrayTest();
	//searchPeakTest();

	findAvgTest();

	/*
	testLowPassFilter();
	testHighPassFilter();
	testDerivativeFilter();
	testSquaringFilter();
	testMwiFilter();
	testAllFiltersChainedTogether();
	*/
	return EXIT_SUCCESS;
}




