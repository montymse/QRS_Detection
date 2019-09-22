
#include <stdbool.h>
#include "output.h"
void warningTest();


void warningTest(){
	printf("warnings %d \n", warnings(5,3000));
	printf("warnings %d\n", warnings(4,1000));
	printf("warnings %d\n", warnings(3,2500));
	printf("warnings %d\n", warnings(6,1000));

}
