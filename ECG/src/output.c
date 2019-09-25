#include "qrs.h"
#include "filters.h"
#include "sensor.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void outputResults(int arr[], int Rposition, int numberofpeaks, int warningIntervals, int numberofsamples){
	if(warnings(warningIntervals,Rposition)){
		printf("Warning!");
		printf("Latest R-peak %d",arr[Rposition]);
		printf("Time-value");
		printf("Pulse" );
	}
	else{
		printf("Latest R-peak %d",arr[Rposition]);
		printf("Time-value");
		printf("Pulse %d", Pulse(numberofpeaks,numberofsamples));
	}
}


int Pulse (int NumberofPeaks, int NumberofSamples) {
	return NumberofPeaks/(NumberofSamples/250);
}


int warnings(int nInterval, int value){
	if (nInterval >= 5 || value < 2000 ){
		return 1 ;
	} else {
		return 0;
	}
}
