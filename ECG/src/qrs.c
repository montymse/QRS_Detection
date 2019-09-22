
#include "qrs.h"
#include "filters.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int peak;

int Index[100];
int position=0;

int PEAKS[100];
int Rpeak[100];

int THRESHOLD1 = 0;
int THRESHOLD2 =0;
int NPKF =0;
int SPKF = 0;


int RPEAKS[100];
int RR,RR_MISS;
int RR_LOW =0;
int RR_HIGH =INT_MAX;
int RecentRR_OK[8]={0,0,0,0,0,0,0,0};
int RecentRR[8]={0,0,0,0,0,0,0,0};
int RR_AVG1,RR_AVG2;


void peakDetection(int x[], int n, int r)
{
	//All peaks that are found, are stored in a list named PEAKS
	int search = searchPeak(x,n);
	if(search == 0){
		 peak = searchPeak(x,n);

		 storeArray(peak, PEAKS, position);
		 
		 int peakIndex=r*32+n;
		 storeArray(peakIndex,Index, position);

		 //The algorithm then checks if they exceed THRESHOLD1. If they do, they are classified as an R-peak.
		 if (peak < THRESHOLD1){
			 NPKF = 0.125 * peak + 0.875 * NPKF ;
			 THRESHOLD1 = NPKF  + 0.25*(SPKF- NPKF);
			 THRESHOLD2 = 0.5* THRESHOLD1;
		 }
		 else{
			int RR = calculateRR(position);


			if((RR_LOW < RR)  && (RR < RR_HIGH)){
				//Store peak as Rpeak
				 storeArray(peak, RPEAKS, position);

				//SPKF
				 SPKF = 0.125 * peak + 0.875 * SPKF ;

				//Store RR in RecentRR_OK

				storeArray(RR,RecentRR_OK, position%8);

				//Store RR in RecentRR
				storeArray(RR,RecentRR, position%8);


				 //RR_AVG1 = avg of RecentRR
				 RR_AVG1 = findAvg(RecentRR);

				 //RR_AVERAGE2 = avg of RecentRR_OK
				 RR_AVG2 = findAvg(RecentRR_OK);

				 RR_LOW  = 0.92  * RR_AVG2;
				 RR_HIGH = 1.16  * RR_AVG2;
				 RR_MISS  = 1.66  * RR_AVG2;
				 THRESHOLD1 = NPKF  + 0.25*(SPKF- NPKF);
				 THRESHOLD2 = 0.5* THRESHOLD1;

			}
			else{
				//5.3 Searchback
				if(RR > RR_MISS){
					searchBackwards(position);
				}
			}
		 }
	}
	position++;
}


//5.1 Searching for peaks


int searchPeak(int x[], int n){
	if (n<1) {

		if ((x[n-1] < x[n]) &&  (x[n] > x[n+1])){
			return x[n];
		} break;
	} else {
		 return x[n] > x[n+1];
	}
	return 0;

}

//5.2 Finding R-peaks. 

//Calculates RR given the argument n, which is the current
//index position in PEAKS (n is the same as the position variable)

int calculateRR(int n){
	if (n==0) {
		return Index[0];
	}
	return Index[n]-Index[n-1];
}


//Stores a given integer in a given array at given postion

int storeArray(int n, int arr[], int position){
	arr[position]=n;

	
//Find average of a given integer array of max length 8

int findAvg(int arr[]){
	int sum =0;
	int counter=0;
	for(int i =0; i <= 7 ;i++){
		if(arr[i] != 0){
			counter++;
			sum += arr[i];
		}
	}
	return sum / counter;
}

// Last part of QRS flowchart

// Int n here given as argument is the same as what position
//(in terms of index) that we are at in PEAKS
// (n is the same as the position variable)


void searchBackwards(int n){
	while( n-1 >= 0 ){
		int peak2 = PEAKS[n-i];
		if(peak2 > THRESHOLD2){
			
			//Store as peak in RPEAKS
			storeArray(peak, PEAKS, position);

			
			//Store RR in RecentRR
			storeArray(peak,RecentRR,position%8);

			//RR_AVG1 = avg of RecentRR
			RR_AVG1 = findAvg(RecentRR);

			//RR_AVERAGE2 = avg of RecentRR_OK
			RR_AVG2 = findAvg(RecentRR_OK);

		 	RR_LOW  = 0.92  * RR_AVG2;
		 	RR_HIGH = 1.16  * RR_AVG2;
		 	RR_MISS  = 1.66  * RR_AVG2;
		 	THRESHOLD1 = NPKF  + 0.25*(SPKF- NPKF);
		 	THRESHOLD2 = 0.5* THRESHOLD1;
		 	SPKF = 0.25 * peak2 + 0.75 * SPKF;
		 	break;
		} else{
			return searchBackwards(n-1);
		}
		return;
	}
}




