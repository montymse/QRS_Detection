#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qrs.h"
#include "filters.h"
#include "sensor.h"


int PerformancePeak() {
	clock_t start, end;
	double cpu_time_used;
	FILE *file = openfile("test2.txt");
	int x[32] ;
	for(int i=0; i < 32; i++){
		x[i]= getNextData(file);
	}

	start = clock();
	for(int i =0 ; i < 32;i++){
			peakDetection(x, i);

		}	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("cpu time used %f", cpu_time_used);


	return (int) cpu_time_used;
}



