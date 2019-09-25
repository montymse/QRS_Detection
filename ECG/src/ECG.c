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
#include "performancePeak.h"


int main(void) {
	//testFilters();
	//WarningTest();
	PerformancePeak();

	//PulseTest();
	//Hello();

	//storeArrayTest();
	//searchPeakTest();
	//findAvgTest();
	//peakDetectionTest();
	//calculateRRTest();


	//FILE * ecgFile = openfile("ECG.txt");

	//Setting the array size
	/*
	int arraysize=32;

	//x is the input array, y is the output array
	int x[arraysize], y[arraysize]={INT_MAX};
	int LowPass[arraysize], HighPass[arraysize],Deriv[arraysize],Square[arraysize]={INT_MAX};
	int element=0;
	int counter=0;

	//Peakdetection algoritmen kører så længe der er input
	while (!feof(ecgFile)) {
		for(int i=0; i < arraysize; i++){
				if (getNextData(ecgFile)!=INT_MAX) {
					x[i]= getNextData(ecgFile);
				}

				}
		counter=0;
		while (counter<arraysize && x[element%arraysize]!=INT_MAX) {
				peakDetection(x, element);
				element++;
				counter++;
		}
	}*/

	return EXIT_SUCCESS;
}




