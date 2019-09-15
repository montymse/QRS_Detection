#include "filters.h"

// Feel free to change return statement and arguments
int res;
int max_low = 5;
int max_x= 20;
int max_high =30;
int max_der =2;


int lowPassFilter(int* y[], int x[], int n)
{

	res = 2*y[((n-1) % max_low)] - y[((n-2) % max_low)] + 1/32 *(x[n % max_x] - 2*x[(n-6) % max_x]+ x[(n-12 )%max_x]);
	return res;
}
int highPassFilter(int y[], int x[], int n)
{
	 res = y[(n-1) % max_high ] - x[n % max_low]/32 + x[(n-16) %max_low] - x[(n-17)%max_low]+ (x[n % max_low]-32)/32;
	 return res;

}


int derivativeFilter(int x[], int n)
{
	res = 1/8*(2*x[n % max_high]+ x[(n-1) % max_high]-x[(n-3) % max_high]-2*x[(n-4)%max_high]);
	return res;
}

int squaringFilter( int x[], int n)
{
	res = x[n % max_der ]*x[n % max_der ];
	return res;
}

int mwiFilter( int x[], int n)
{
	int N =30;
	res=1/N * (x[n-(N-1)] + x[n-(N-2)+ x[n]]);
	return res;
}



/*
 * int xSize, ySize;
 * int lowPassFilter(int* y[], int x[], int n)
{

	res = 2*y[((n-1) % ySize)] - y[((n-2) % ySize)] + 1/32 *(x[n % xSize] - 2*x[(n-6) % xSize]+ x[(n-12 )%xSize]);
	return res;
}
int highPassFilter(int y[], int x[], int n)
{
	 res = y[(n-1) % ySize ] - x[n % xSize]/32 + x[(n-16) %xSize] - x[(n-17)%xSize]+ (x[n % xSize]-32)/32;
	 return res;

}


int derivativeFilter(int x[], int n)
{
	res = 1/8*(2*x[n % xSize]+ x[(n-1) % xSize]-x[(n-3) % xSize]-2*x[(n-4)%xSize]);
	return res;
}

int squaringFilter( int x[], int n)
{
	res = x[n % xSize ]*x[n % xSize ];
	return res;
}

int mwiFilter( int x[], int n)
{
	int N =30;
	res=1/N * (x[n-(N-1)] + x[n-(N-2)+ x[n]]);
	return res;
}
 */
