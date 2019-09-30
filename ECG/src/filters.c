#include "filters.h"

// Feel free to change return statement and arguments
int lowPassFilter(int y[], int x[], int n)
{
	int res = 2*y[((LOW_PASS_OUTPUT_SIZE + n-1) % LOW_PASS_OUTPUT_SIZE)]
		- y[((LOW_PASS_OUTPUT_SIZE + n-2) % LOW_PASS_OUTPUT_SIZE)]
		+ (x[n % LOW_PASS_INPUT_SIZE]
			- 2*x[(LOW_PASS_INPUT_SIZE + n-6) % LOW_PASS_INPUT_SIZE]
			+ x[(LOW_PASS_INPUT_SIZE + n-12 )%LOW_PASS_INPUT_SIZE]) / 32; // division done at the end, otherwise (1/8) at the start becomes 0 due to integer truncation
	return res;
}

int highPassFilter(int y[], int x[], int n)
{
	 int res = y[(HIGH_PASS_OUTPUT_SIZE + n-1) % HIGH_PASS_OUTPUT_SIZE ]
		 - x[n % HIGH_PASS_INPUT_SIZE]/32
		 + x[(HIGH_PASS_INPUT_SIZE + n-16) %HIGH_PASS_INPUT_SIZE]
		 - x[(HIGH_PASS_INPUT_SIZE + n-17)%HIGH_PASS_INPUT_SIZE]
		 + (x[(HIGH_PASS_INPUT_SIZE + n-32) % HIGH_PASS_INPUT_SIZE])/32; // division done at the end, otherwise (1/8) at the start becomes 0 due to integer truncation
	 return res;
}

int derivativeFilter(int x[], int n)
{
	int res = (2*x[n % DERIVATIVE_INPUT_SIZE]
		+ x[(DERIVATIVE_INPUT_SIZE + n-1) % DERIVATIVE_INPUT_SIZE]
		-x[(DERIVATIVE_INPUT_SIZE + n-3) % DERIVATIVE_INPUT_SIZE]
		-2*x[(DERIVATIVE_INPUT_SIZE + n-4)% DERIVATIVE_INPUT_SIZE]) / 8; // division done at the end, otherwise (1/8) at the start becomes 0 due to integer truncation
	return res;
}

int squaringFilter(int x[], int n)
{
	int res = x[n % SQUARING_INPUT_SIZE]*x[n % SQUARING_INPUT_SIZE];
	return res;
}

int mwiFilter(int x[], int n)
{
	int res;
	int N = MOVING_WINDOW_INPUT_SIZE;
	int sum = 0;

	for (int i = 1; i <= N; i++)
	{
		sum += x[ (N + ( n - (N - i))) % N];
	}

	res = sum / N;
	return res;
}



