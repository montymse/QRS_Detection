/*
 ============================================================================
 Name        : ECG.c
 Author      : Tala
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"
#include "filters.h"

int main(void) {
	puts("!!!Hello Clair!!!");
	FILE * file = openfile("ECG.txt");
	getNextData(file);
	for (int i = 0 ; i < 10; i ++){
		printf("%d", lowPassFilter(x,y,i));
	}
	return EXIT_SUCCESS;
}




