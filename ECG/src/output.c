#include "qrs.h"
#include "filters.h"
#include "sensor.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern int warningIntervals, Rposition, position;


int Pulse (int NumberofPeaks, int NumberofSamples) {





		return ((NumberofPeaks*15000)/NumberofSamples);

}


int warnings(int nInterval, int value){
	if ((nInterval >= 5) || (value < 2000 )){
		return 1 ;
	} else {
		return 0;
	}
}

void outputResults(int numberofsamples, double Time, int Rpeak) {


	if(warnings(warningIntervals,Rpeak)){
		printf("Warning! \t");
		printf("Latest R-peak %d \t",Rpeak);
		printf("Time-value, %f \t", Time);
		printf("Pulse %d \n\n\n", Pulse(position,numberofsamples));
	}
	else{
		printf("Latest R-peak %d \t",Rpeak);
		printf("Time-value, %f \t", Time);
		printf("Pulse %d \n\n\n", Pulse(position,numberofsamples));
	}

}


