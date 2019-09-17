#ifndef FILTERS_H
#define FILTERS_H

#define LOW_PASS_INPUT_SIZE 13
#define LOW_PASS_OUTPUT_SIZE 33
#define HIGH_PASS_INPUT_SIZE 33
#define HIGH_PASS_OUTPUT_SIZE 5
#define DERIVATIVE_INPUT_SIZE 5
#define DERIVATIVE_OUTPUT_SIZE 1
#define SQUARING_INPUT_SIZE 1
#define SQUARING_OUTPUT_SIZE 30
#define MOVING_WINDOW_INPUT_SIZE 30

// Feel free to change return statement and arguments
int lowPassFilter(int y[], int x[], int n);
int highPassFilter(int y[], int x[], int n);
int derivativeFilter(int x[], int n);
int squaringFilter( int x[], int n);
int mwiFilter(int x[], int n);


// Implement additional filters

#endif // FILTERS_H
