#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sensor.h"
#include "filters.h"


int PerformanceFilters() {
	clock_t start, end;
	double cpu_time_used;

	start = clock();
	 /* The code that has to be measured. */
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;



	return (int) cpu_time_used;
}
