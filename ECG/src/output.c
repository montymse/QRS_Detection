#include "qrs.h"
#include "filters.h"
#include "sensor.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void outputResults(int arr[], int Rposition, int position, int warningIntervals){
	if(warnings(warningIntervals,Rposition)){
		printf("Warning!");
		printf("Latest R-peak %d",arr[Rposition]);
		printf("Time-value %d", position );
		printf("Pulse" );
	}
	else{
		printf("Latest R-peak %d",arr[Rposition]);
		printf("Time-value %d", position );
		printf("Pulse" );
	}
}


int warnings(int nInterval, int value){
	if (nInterval >= 5 || value < 2000 ){
		return 1 ;
	} else {
		return 0;
	}
}
