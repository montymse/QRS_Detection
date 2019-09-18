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


void peakDetectionTest(){


}
