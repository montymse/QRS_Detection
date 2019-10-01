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
	FILE *fileNext = openfile("x_mwi_div_after.txt");
	getNextData(fileNext);
	int x[32] ;

	start = clock();

	int i=0;

	while (!feof(file)) {

		x[i%32]= getNextData(file);

		peakDetection(x,i,getNextData(fileNext));

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

		int xInput[LOW_PASS_INPUT_SIZE] = { 0 };
		int y[ARRAYSIZE];

		int yLowPass[LOW_PASS_OUTPUT_SIZE] = { 0 };
		int yHighPass[HIGH_PASS_OUTPUT_SIZE] = { 0 };
		int yDeriv[DERIVATIVE_OUTPUT_SIZE] = { 0 };
		int ySquare[SQUARING_OUTPUT_SIZE] = { 0 };

		//Counter
		int inputCounter=0;
		//Peakdetection algoritmen kører så længe der er input
		while (!feof(ecgFile)) {
			xInput[inputCounter% LOW_PASS_INPUT_SIZE]= getNextData(ecgFile);
			yLowPass[inputCounter % LOW_PASS_OUTPUT_SIZE] = lowPassFilter(yLowPass, xInput, inputCounter);
			yHighPass[inputCounter % HIGH_PASS_OUTPUT_SIZE] = highPassFilter(yHighPass, yLowPass, inputCounter);
			yDeriv[inputCounter % DERIVATIVE_OUTPUT_SIZE] = derivativeFilter(yHighPass, inputCounter);
			ySquare[inputCounter % SQUARING_OUTPUT_SIZE] = squaringFilter(yDeriv, inputCounter);
			y[inputCounter%32] = mwiFilter(ySquare, inputCounter);
			inputCounter++;
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
		FILE * ecgFileNext = openfile("ECG.txt");
		getNextData(ecgFileNext);

		//x is the input array, y is the output array
		int xInput[LOW_PASS_INPUT_SIZE] = { 0 };
		int xNext[LOW_PASS_INPUT_SIZE] = { 0 };
		int y[ARRAYSIZE] = { 0 };

		int yLowPass[LOW_PASS_OUTPUT_SIZE] = { 0 };
		int yHighPass[HIGH_PASS_OUTPUT_SIZE] = { 0 };
		int yDeriv[DERIVATIVE_OUTPUT_SIZE] = { 0 };
		int ySquare[SQUARING_OUTPUT_SIZE] = { 0 };

		int yLowPassNext[LOW_PASS_OUTPUT_SIZE] = { 0 };
		int yHighPassNext[HIGH_PASS_OUTPUT_SIZE] = { 0 };
		int yDerivNext[DERIVATIVE_OUTPUT_SIZE] = { 0 };
		int ySquareNext[SQUARING_OUTPUT_SIZE] = { 0 };
		//Counters
		int inputCounter=0;
		int next=0;

		//Peakdetection algoritmen kører så længe der er input
				while (!feof(ecgFile)) {

						xInput[inputCounter% LOW_PASS_INPUT_SIZE]= getNextData(ecgFile);
						yLowPass[inputCounter % LOW_PASS_OUTPUT_SIZE] = lowPassFilter(yLowPass, xInput, inputCounter);
						yHighPass[inputCounter % HIGH_PASS_OUTPUT_SIZE] = highPassFilter(yHighPass, yLowPass, inputCounter);
						yDeriv[inputCounter % DERIVATIVE_OUTPUT_SIZE] = derivativeFilter(yHighPass, inputCounter);
						ySquare[inputCounter % SQUARING_OUTPUT_SIZE] = squaringFilter(yDeriv, inputCounter);
						y[inputCounter%32] = mwiFilter(ySquare, inputCounter);
						//fprintf(FILTEREDDATA,"%d\n", mwiFilter(ySquare, inputCounter));


						xNext[inputCounter% LOW_PASS_INPUT_SIZE]= getNextData(ecgFileNext);
						yLowPassNext[inputCounter % LOW_PASS_OUTPUT_SIZE] = lowPassFilter(yLowPassNext, xNext, inputCounter);
						yHighPassNext[inputCounter % HIGH_PASS_OUTPUT_SIZE] = highPassFilter(yHighPassNext, yLowPassNext, inputCounter);
						yDerivNext[inputCounter % DERIVATIVE_OUTPUT_SIZE] = derivativeFilter(yHighPassNext, inputCounter);
						ySquareNext[inputCounter % SQUARING_OUTPUT_SIZE] = squaringFilter(yDerivNext, inputCounter);
						next = mwiFilter(ySquareNext, inputCounter);

						peakDetection(y, inputCounter, next);

						inputCounter++;
					}
				fclose(ecgFile);
				fclose(ecgFileNext);

				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("Cpu time used for the main program: %f\n", cpu_time_used);

	return (int) cpu_time_used;
}
