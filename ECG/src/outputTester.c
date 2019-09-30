#include "output.h"
#include "outputTester.h"

#include <stdio.h>
#include <stdlib.h>


void PulseTest() {

	printf("Expected pulse:  %d \t Actual pulse:   %d\n",37, Pulse(80,550));
	printf("Expected pulse:  %d \t Actual pulse:   %d\n",43, Pulse(60,350));
	printf("Expected pulse:  %d \t Actual pulse:   %d\n",24, Pulse(80,850));
	printf("Expected pulse:  %d \t Actual pulse:   %d\n",17, Pulse(30,450));

}

void WarningTest(){
	printf("warnings %d \n", warnings(5,3000));
	printf("warnings %d\n", warnings(4,1000));
	printf("warnings %d\n", warnings(3,2500));
	printf("warnings %d\n", warnings(6,1000));
}
