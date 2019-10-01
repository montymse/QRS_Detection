
#include "qrs.h"
#include "filters.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ARRAYSIZE 33


int peak;

int Index[ARRAYSIZE];
int RPEAKS[ARRAYSIZE];
int PEAKS[ARRAYSIZE];

int position=0;
int Rposition=0;

int THRESHOLD1 =2000;
int THRESHOLD2 =1000;
int NPKF =0;
int SPKF =0;
int warningIntervals=0;

int RR,RR_MISS;
int RR_LOW =0;
int RR_HIGH =INT_MAX;
int RecentRR_OK[8]={0,0,0,0,0,0,0,0};
int RecentRR[8]={0,0,0,0,0,0,0,0};
int RR_AVG1,RR_AVG2;



int searchback=0;

void peakDetection(int x[], int n, int next)
{
	searchback=0;

	//All peaks that are found, are stored in a list named PEAKS
	int search = searchPeak(x,n, next);
	if(search != 0){
		 peak = searchPeak(x,n, next);
		 storeArray(peak, PEAKS, (position)%32);
		 
		 storeArray(n,Index, (position)%32);

		 position++;
		 //The algorithm then checks if they exceed THRESHOLD1. If they do, they are classified as an R-peak.
		 if (peak < THRESHOLD1){
			 NPKF = 0.125 * peak + 0.875 * NPKF ;
			 THRESHOLD1 = NPKF  + 0.25*(SPKF- NPKF);
			 THRESHOLD2 = 0.5* THRESHOLD1;
		 }
		 else{
		    RR = calculateRR(position-1, Index);
		    warningIntervals++;

			if((RR_LOW < RR) && (RR < RR_HIGH)){
			    warningIntervals =0;
				//Store peak as Rpeak
				storeArray(peak, RPEAKS, (Rposition)%32);
				//SPKF
				SPKF = 0.125 * peak + 0.875 * SPKF ;

				//Store RR in RecentRR_OK
				storeArray(RR,RecentRR_OK, (Rposition)%8 );

				//Store RR in RecentRR
				storeArray(RR,RecentRR,  (Rposition)%8 );

				//RR_AVG1 = avg of RecentRR
				RR_AVG1 = findAvg(RecentRR);

				//RR_AVERAGE2 = avg of RecentRR_OK
				RR_AVG2 = findAvg(RecentRR_OK);

				RR_LOW  = 0.92  * RR_AVG2;
				RR_HIGH = 1.16  * RR_AVG2;
				RR_MISS  = 1.66  * RR_AVG2;
				THRESHOLD1 = NPKF  + 0.25*(SPKF- NPKF);
				THRESHOLD2 = 0.5* THRESHOLD1;
				Rposition++;
			}
			else{

				//5.3 Searchback
				if(RR > RR_MISS){
					searchback=1;
					searchBackwards(position-1);
				}
			}
		 }
	}
}



//5.1 Searching for peaks


int searchPeak(int x[], int n, int next){
	if (n==0) {
		return 0;
	}
	else if ((x[(n-1)%32] < x[n%32]) && (next < x[n%32])){
		return x[n%32];
	}
	else {
		return 0;
	}

}

//5.2 Finding R-peaks. 

//Calculates RR given the argument n, which is the current
//index position in PEAKS (n is the same as the position variable)

int calculateRR(int n,int x[]){
	if (n==0) {
		return x[0];
	} else {
		return (x[n%32]-x[(n-1)%32]);
	}
}


//Stores a given integer in a given array at given postion

void storeArray(int n, int arr[], int position){
	arr[position]=n;

}



//Find average of a given integer array of max length 8

int findAvg(int arr[]){
	int sum =0;
	int counter=8;
	for(int i =0; i <= 7 ;i++){
			sum += arr[i];
	}
	return sum / counter;
}

// Last part of QRS flowchart

// Int n here given as argument is the same as what position
//(in terms of index) that we are at in PEAKS
// (n is the same as the position variable)


void searchBackwards(int n){
	int i=32;
	while( i >= 0 ){
		int peak2 = RPEAKS[(n-1)%32];
		i--;
		if(peak2 > THRESHOLD2){
			
			//Store as peak in RPEAKS
			storeArray(peak, RPEAKS, Rposition%32);

			//Store RR in RecentRR
			storeArray(RR,RecentRR,Rposition%8);
		 	SPKF = 0.25 * peak + 0.75 * SPKF;

			//RR_AVG1 = avg of RecentRR
			RR_AVG1 = findAvg(RecentRR);

		 	RR_LOW  = 0.92  * RR_AVG1;
		 	RR_HIGH = 1.16  * RR_AVG1;
		 	RR_MISS  = 1.66  * RR_AVG1;
		 	THRESHOLD1 = NPKF  + 0.25*(SPKF- NPKF);
		 	THRESHOLD2 = 0.5* THRESHOLD1;
		 	Rposition++;
		 	break;
		} else{
			return searchBackwards(n-1);
		}
		return;
	}
}




