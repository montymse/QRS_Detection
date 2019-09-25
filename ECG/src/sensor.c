#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int getNextData(FILE *file)
{
	int value;

	if (feof(file)){
		return INT_MAX;
	}
	else{
		fscanf(file,"%d",&value);
	}

	return value;
}

FILE* openfile(const char* filename)
{
   FILE *file = fopen(filename, "r");

   return file;
}



