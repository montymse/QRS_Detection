#include "filters.h"

// Feel free to change return statement and arguments
int res;

int lowPassFilter(int y[], int x[], int n)
{
	res = 2*y[n-1] - y[n-2] + 1/32 *(x[n] - 2*x[n-6]+ x[n-12]);
	return res;
}
int highPassFilter(int y[], int x[], int n)
{
	 res = y[n-1] - x[n]/32 + x[n-16] - x[n-17]+ (x[n]-32)/32;
	 return res;

}


int derivativeFilter(int y[], int x[], int n)
{
	res = 1/8*(2*x[n]+ x[n-1]-x[n-3]-2*x[n-4]);
	return res;
}

int squaringFilter(int y[], int x[], int n)
{
	return res;
}

int mwiFilter(int y[], int x[], int n)
{
	int N =30;
	res=1/N * (x[n-(N-1)] + x[n-(N-2)+ x[n]]);
	return res;
}

