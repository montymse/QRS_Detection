#include "qrs.h"
#include "filters.h"
#include "sensor.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern int warningIntervals, Rposition, position;
extern int RPEAKS[];


int Pulse (int NumberofPeaks, int NumberofSamples) {
	int val = (NumberofSamples/250);
	int diff = 250-(NumberofSamples%250);

	if (val==0) { //Round up to 1 if val is null
		return NumberofPeaks/1;
	}

	if (diff<=125) { //Ceiling
		return NumberofPeaks/(val+1);
	}

	else {
		return NumberofPeaks/val;
	}
}


int warnings(int nInterval, int value){
	if (nInterval >= 5 || value < 2000 ){
		return 1 ;
	} else {
		return 0;
	}
}

void outputResults(int numberofsamples, double Time){
	if(warnings(warningIntervals,Rposition)){
		printf("Warning! \t");
		printf("Latest R-peak %d \t",RPEAKS[Rposition]);
		printf("Time-value, %d \t", Time);
		printf("Pulse %d \n\n\n", Pulse(position,numberofsamples));
	}
	else{
		printf("Latest R-peak %d",RPEAKS[Rposition]);
		printf("Time-value, %d", Time);
		printf("Pulse %d", Pulse(position,numberofsamples));
	}
}


