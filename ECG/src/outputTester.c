#include "output.h"
#include "outputTester.h"

#include <stdio.h>
#include <stdlib.h>


void PulseTest() {

	printf("Expected pulse:  %d \t Actual pulse:   %d\n",81, Pulse(3,550));
	printf("Expected pulse:  %d \t Actual pulse:   %d\n",0, Pulse(0,350));
	printf("Expected pulse:  %d \t Actual pulse:   %d\n",70, Pulse(4,850));
	printf("Expected pulse:  %d \t Actual pulse:   %d\n",51, Pulse(5,1450));

}

void WarningTest(){
	printf("Expected Warning:  %d \t Actual warning %d\n",1, warnings(5,3000));
	printf("Expected Warning:  %d \t Actual warning %d\n",1, warnings(4,1000));
	printf("Expected Warning:  %d \t Actual warning %d\n",0, warnings(3,2500));
	printf("Expected Warning:  %d \t Actual warning %d\n",1, warnings(6,1000));
}

void TestOutput() {
	WarningTest();
	printf("\n \n");
	PulseTest();
}
