#ifndef QSR_H
#define QSR_H


// Header file for QRS functionality
// it is recommended to use the structure "QRS_parameters"
// to organize all variables and parameters

typedef struct QRS_params
{ // Structure for QRS parameters
   int SPKF, NPKF,THRESHOLD1,THRESHOLD2;
   int RR, RR_LOW,RR_HIGH, RR_MISS, RR_AVERAGE1, RR_AVERAGE2;

   // Add parameters that are missing
   // or of use to you

} QRS_params;


// Feel free to change and add methods
void peakDetection(int x[], int n, int next);
int searchPeak(int x[], int n, int next);
int calculateRR(int n,int x[]);
void storeArray(int el, int arr[], int position);
int findAvg(int arr[]);
void searchBackwards(int i);


#endif // QSR_H
