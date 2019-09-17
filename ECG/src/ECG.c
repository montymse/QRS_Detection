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
#include "qrs.h"

int main(void) {
	puts("Personal ECG scanner!");
	FILE * file = openfile("ECG.txt");
	getNextData(file);
	for (int i = 0 ; i < 10; i ++){
		printf("%d", lowPassFilter()); //hvilke argumenter??
	}
	return EXIT_SUCCESS;
}




