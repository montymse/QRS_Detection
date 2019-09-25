#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "performanceTest.h"
#include "qrs.h"
#include "filters.h"
#include "sensor.h"

#define ARRAYSIZE 32


int PerformancePeak() {
	clock_t start, end;
	double cpu_time_used;
	FILE *file = openfile("x_mwi_div_after.txt");
	int x[32] ;

	start = clock();

	int i=0;

	while (!feof(file)) {

		x[i%32]= getNextData(file);

		peakDetection(x, i);

		i++;
	}

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Cpu time used for peakdetection %f\n", cpu_time_used);


	return (int) cpu_time_used;
}

int PerformanceFilters() {
	clock_t start, end;
	double cpu_time_used;

	start = clock();
	FILE * ecgFile = openfile("ECG.txt");


		//x is the input array, y is the output array

		int x[ARRAYSIZE]={ INT_MAX };
		int y[ARRAYSIZE];

		int LowPass[ARRAYSIZE];
		int HighPass[ARRAYSIZE];
		int Deriv[ARRAYSIZE];
		int Square[ARRAYSIZE];

		//Counter
		int counter=0;
		//Peakdetection algoritmen kører så længe der er input
		while (!feof(ecgFile)) {
			counter=0;
			while (counter<ARRAYSIZE) {
					x[counter]= getNextData(ecgFile);
					LowPass[counter] = lowPassFilter(LowPass, x, counter);
					HighPass[counter] = highPassFilter(HighPass, LowPass, counter);
					Deriv[counter] = derivativeFilter(HighPass, counter);
					Square[counter] = squaringFilter(Deriv, counter);
					y[counter]=mwiFilter(Square,counter);

					counter++;
			}
		}

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Cpu time used for the filters %f\n", cpu_time_used);



	return (int) cpu_time_used;
}


int PerformanceMain() {
	clock_t start, end;
	double cpu_time_used;


	start = clock();
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
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Cpu time used for the main program: %f\n", cpu_time_used);



	return (int) cpu_time_used;
}
