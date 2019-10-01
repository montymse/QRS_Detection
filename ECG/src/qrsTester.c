#include "qrsTester.h"
#include "qrs.h"
#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void storeArrayTest(){
	int arr[33];
	storeArray(5,arr,0);
	printf("Expected Input: %d \t Actual Input: %d \n",5, arr[0]);
	storeArray(6,arr,1);
	printf("Expected Input: %d \t Actual Input: %d \n",6, arr[1]);
	storeArray(7,arr,1);
	printf("Expected Input: %d \t Actual Input: %d \n",7, arr[1]);


}

void searchPeakTest(){
	int arr0[]={1,2,3,4,6,5,9,1};

	printf("Expected Peak: %d \t Actual Peak: %d \n",0, searchPeak(arr0,3,arr0[4]));
	printf("Expected Peak: %d \t Actual Peak: %d \n",0, searchPeak(arr0,0,arr0[1]));
	printf("Expected Peak: %d \t Actual Peak: %d \n",arr0[4],searchPeak(arr0,4,arr0[5]));
	printf("Expected Peak: %d \t Actual Peak: %d \n",arr0[4],searchPeak(arr0,36,arr0[5]));

}

void findAvgTest(){
	int arr0[]={1,2,3,4,6,5,9,1,0};
	int arr1[8]={0};
	int arr2[8]={3,6};
	printf("Expected average: %d \t Actual average: %d \n",3, findAvg(arr0));
	printf("Expected average: %d \t Actual average: %d \n",0, findAvg(arr1));
	printf("Expected average: %d \t Actual average: %d \n",1, findAvg(arr2));

}


void calculateRRTest(){
	int x[33];
	for (int i=0; i<33; i++) {
		x[i]=10*i;
	}
	x[12]=300;
	printf("Expected RR: %d \t \t Actual RR: %d \n",0,calculateRR(0,x));
	printf("Expected RR: %d \t Actual RR: %d \n",10,calculateRR(1,x));
	printf("Expected RR: %d \t Actual RR: %d \n",190,calculateRR(44,x));


}

void TestQRS() {
	findAvgTest();
	printf("\n \n");
	calculateRRTest();
	printf("\n \n");
	searchPeakTest();
	printf("\n \n");
	storeArrayTest();
}




