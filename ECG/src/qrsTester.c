#include "qrsTester.h"
#include "qrs.h"
#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void storeArrayTest(){
	int arr[5];
	storeArray(5,arr,0);
	storeArray(6,arr,1);
	printf("Store array: %d", arr[0]);
	printf("Store array: %d", arr[1]);

}

void searchPeakTest(){
	int arr[]={1,2,3,4,6,5,9,1};
	printf("Peak? %d \n", searchPeak(arr,3));
	printf("Peak? %d \n", searchPeak(arr,6));
	printf("Peak? %d \n", searchPeak(arr,7));
	printf("Peak? %d \n", searchPeak(arr,4));

}

void findAvgTest(){
	int arr[]={1,2,3,4,6,5,9,1,0};
	printf("Average? %d \n", findAvg(arr));
}


extern int PEAKS[100];
extern int Index[100];
extern int THRESHOLD1,THRESHOLD2,SPKF,NPKF, RR_LOW, RR_HIGH, RR, RR_MISS;

void peakDetectionTest(){
	FILE *file = openfile("test2.txt");
	int x[32] ;
	for(int i=0; i < 32; i++){
		x[i]= getNextData(file);
	}
	for(int i =0 ; i < 32;i++){
		peakDetection(x, i,0);

		printf("THRESHOLD1 %d & THRESHOLD2 %d & SPKF %d & NPKF %d  & RRLOW %d &RRHIGH %d & RR %d & RRMISS %d\n", THRESHOLD1,THRESHOLD2,SPKF,NPKF, RR_LOW, RR_HIGH, RR, RR_MISS);
	}
	for(int j =0; j < 32; j++){
		//printf("Peaks ? %d and index %d \n",PEAKS[j],Index[j]);
	}
}

void calculateRRTest(){
	int x[] = {1,2,3,4,5,6,57,67,324,7,723,56};
	printf("RR = %d",calculateRR(7,x));
	printf("RR = %d",calculateRR(0,x));

}




