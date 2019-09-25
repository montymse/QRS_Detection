#include "output.h"
#include "outputTester.h"

#include <stdio.h>
#include <stdlib.h>


void PulseTest() {

	printf("Current pulse:  %d", Pulse(100,30));
	printf("Current pulse:  %d", Pulse(250,40));
	printf("Current pulse:  %d", Pulse(30,3));
	printf("Current pulse:  %d", Pulse(500,70));

}

void WarningTest(){
	printf("warnings %d \n", warnings(5,3000));
	printf("warnings %d\n", warnings(4,1000));
	printf("warnings %d\n", warnings(3,2500));
	printf("warnings %d\n", warnings(6,1000));
}

void Hello() {
	printf("Hello");
}
