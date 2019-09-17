#include "qrs.h"
#include "filters.h"
#include <stdio.h>
#include <stdlib.h>


int x_size;
int peak;
int n;
int x[];
int peaks_max;
int PEAKS[],Rpeak[];
int THRESHOLD1,THRESHOLD2, NPKF, SPKF;
int RR, RR_LOW,RR_HIGH, RR_MISS,RR_AVERAGE1, RR_AVERAGE2;

//Constants for QSR. saadman*
#define RR_AVG_GAP 8 //Size of the R interval gap
#define PULSE_AVG_GAP 5 //Size of the pulse interval gap
#define MAX_RR_PEAKS RR_AVG_GAP + 3 //Need to be exactly this size to work (RR_AVG_GAP + 3 )
#define SAMPLING_FREQUENCY 250
#define MIN_HEARTRATE 600 // The slowest possible hear rate (The highest difference in n between two heart beats)
#define AVGHEARTRATE SAMPLING_FREQUENCY/9*6
#define MAX_HEARTRATE 50 // The highest possible heart rate (The lowest difference in n between two heart beats)
#define MAX_PEAKS 15 //Maximum number of peaks to be stored, needs to store enough peaks, so that we can find peaks in the searchback call (unsure what the minimum is for this number) (For the provided input file, the minimum number is 10)


void peakDetection()
{
	int x[n % x_size];
	//All peaks that are found, are stored in a list named PEAKS
	if(searchPeak(x)){
		 peak = getPeak();
		 storePeak(peak);
		 //The algorithm then checks if they exceed THRESHOLD1. If they do, they are classified as an R-peak.
		 if (peak < THRESHOLD1){
			 NPKF = 0.125 * peak + 0.875 * NPKF ;
			 THRESHOLD1 = NPKF  + 0.25*(SPKF- NPKF);
			 THRESHOLD2 = 0.5* THRESHOLD1;
		 }
		 else{
			calculateRR();
			//RR??

			//equation 9
			NPKF = 0.125 * peak + 0.875 * NPKF ;


			if(RR_LOW < RR > RR_HIGH){
				//Store peak as Rpeak
				 peak = getPeak();
				 storeRpeak(peak);
				 //SPKF
				 SPKF = 0.125 * peak + 0.875 * SPKF ;
				 //Store RR in RecentRR_OK

				 //Store RR in RecentRR

				 //RR_AVERAGE2 = avg of RecentRR_OK

				 //RR_AVERAGE1 = avg of RecentRR
				 RR_LOW  = 0.92  * RR_AVERAGE2;
				 RR_HIGH = 1.16  * RR_AVERAGE2;
				 RR_MISS  = 1.66  * RR_AVERAGE2;
				 THRESHOLD1 = NPKF  + 0.25*(SPKF- NPKF);
				 THRESHOLD2 = 0.5* THRESHOLD1;

			}
			else{
				//5.3 Searchback
				if(RR > RR_MISS){
					SPKF = 0.25 * peak[n] + 0.75* SPKF;
					//should be peak2 not peak !
					if (peak  < THRESHOLD2){
						if(RR > RR_MISS){
							SPKF = 0.25 * peak[n] + 0.75* SPKF;
						}
					}
					else{
					//Store peak as Rpeak
					peak = getPeak();
					storeRpeak(peak);
					//SPKF
					SPKF = 0.25 * peak + 0.75 * SPKF ;

					//Store RR in RecentRR


					//RR_AVERAGE1 = avg of RecentRR
					RR_LOW  = 0.92  * RR_AVERAGE1;
					RR_HIGH = 1.16  * RR_AVERAGE1;
					RR_MISS  = 1.66  * RR_AVERAGE1;
					THRESHOLD1 = NPKF  + 0.25*(SPKF- NPKF);
					THRESHOLD2 = 0.5* THRESHOLD1;
					}
				}
			}
		 }
	}
}


//5.1 Searching for peaks
int searchPeak(int x[], int n){
	if (x[n-1 % x_size] < x[n % x_size] > x[n+1 %x_size]){
		return 1;
	}
	return 0;
}

//5.2 Finding R-peaks
int getPeak(void){
	return x[n -1 % x_size];
}

void storePeak(int peak){
	PEAKS[n % peaks_max] = peak;
}

int calculateRR(){
	int R = RR;
	RR = 0 ;
	return R;
}

/*
int RR_AVERAGE1(){

	int RR_AVG1;
	return RR_AVG1;
}

int RR_AVERAGE2(){
	int RR_AVG2;
	return RR_AVG2;
}
*/
void storeRpeak(int peak){
	Rpeak[n % peaks_max] = peak;
}








