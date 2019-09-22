#include "qrs.h"
#include "filters.h"
#include "sensor.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern int RPEAKS[100];
extern int Rposition, position;
extern int warningIntervals;

void outputResults(){
	if(warnings(warningIntervals,Rposition)){
		printf("Warning!");
		printf("Latest R-peak %d",RPEAKS[Rposition]);
		printf("Time-value %d", position );
		printf("Pulse" );
	}
	else{
		printf("Latest R-peak %d",RPEAKS[Rposition]);
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
