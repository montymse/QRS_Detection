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

int main(void) {
	//puts("!!!Hello Clair!!!");
	// FILE * file = openfile("ECG.txt");
	// getNextData(file);

	testLowPassFilter();
	testHighPassFilter();
	testDerivativeFilter();
	testSquaringFilter();
	testMwiFilter();
	testAllFiltersChainedTogether();

	return EXIT_SUCCESS;
}




