#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>

int getNextData(FILE *file)
{
	int line;

	if (file != NULL ){
		fscanf(file,"%d",&line);
		printf("Data: %d", line);
	}
	else{
		fclose(file);
	}
	return 0;
}

FILE* openfile(const char* filename)
{
   FILE *file = fopen(filename, "r"); // Replace NULL with the actual file object

   return file;
}



