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
#include <limits.h>

#include "sensor.h"
#include "filters.h"
#include "filterTester.h"
#include "qrs.h"
#include "qrsTester.h"
#include "output.h"
#include "outputTester.h"
#include "performanceTest.h"

#define ARRAYSIZE 32


int main(void) {
	//testFilters();
	//WarningTest();

	//PulseTest();
	//Hello();

	//storeArrayTest();
	//searchPeakTest();
	//findAvgTest();
	//peakDetectionTest();
	//calculateRRTest();

	PerformancePeak();
	PerformanceFilters();
	PerformanceMain();


	FILE * ecgFile = openfile("ECG.txt");

	//x is the input array, y is the output array
	int x[ARRAYSIZE]={ INT_MAX };
	int y[ARRAYSIZE];

	int LowPass[ARRAYSIZE];
	int HighPass[ARRAYSIZE];
	int Deriv[ARRAYSIZE];
	int Square[ARRAYSIZE];

	//Counters
	int element=0;
	int counter=0;
	//Peakdetection algoritmen kører så længe der er input
	while (!feof(ecgFile)) {
		for(int i=0; i < ARRAYSIZE; i++){
						x[i]= getNextData(ecgFile);
					}
		counter=0;

		while (counter<ARRAYSIZE) {
			if (x[counter]==INT_MAX) {
				break;
			}
			LowPass[counter] = lowPassFilter(LowPass, x, counter);
			HighPass[counter] = highPassFilter(HighPass, LowPass, counter);
			Deriv[counter] = derivativeFilter(HighPass, counter);
			Square[counter] = squaringFilter(Deriv, counter);
			y[counter]=mwiFilter(Square,counter);

			peakDetection(y, element);

			element++;
			counter++;
			}
		}

	return EXIT_SUCCESS;
}




