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
void peakDetection();
int searchPeak(int x[], int n);
int getPeak(void);
void storePeak(int peak);
int calculateRR();
int RR_AVERAGE1();
int RR_AVERAGE2();
void storeRpeak(int peak);



#endif // QSR_H
