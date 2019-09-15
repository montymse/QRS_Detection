#ifndef FILTERS_H
#define FILTERS_H

// Feel free to change return statement and arguments
int lowPassFilter();
int highPassFilter();
int derivativeFilter();
int squaringFilter();
int mwiFilter();

// Implement additional filters
int peak;
int Peaks[];
int RR_AVERAGE1 ;  	//AVREAGE of the 8 most recent RR intervals (during the search back)
RR_AVERAGE2;  	//AVREAGE of the 8 most recent RR intervals between RR high and low(not found in the search back)
int RR_LOW = INT_MIN;		  	//Define as 92% of RR_AVERAGE2
int RR_HIGH = INT_MAX;	  	//Define as 116% of RR_AVERAGE2
RR_MISS; 	 	//Define as 166% of RR_AVERAGE2 (used during the search back)

int searchPeak(int x[], int n){
	int nPKF = 0.125 * x[n] + 0.875 * nPKF ;
	int sPKF = 0.125 * x[n] + 0.875 * sPKF ;
	int threshold1 = nPKF  + 0.25*(sPKF- nPKF);
	int threshold2 = 0.5* threshold1;

	if (x[n-1] < x[n]) && (x[n] > x[n+1]){
		 peak = x[n];
		 if (peak < threshold1){
			 nPKF = 0.125 * peak + 0.875 * nPKF ;
			 threshold1 = nPKF  + 0.25*(sPKF- nPKF);
			 threshold2 = 0.5* threshold1;
		 }
		 else {
			 peak = Peaks[n];
			 int sum =0;
			 for (int i =0; i <=8 ; i++){
				 sum += Peaks[i];
			 }
			 RR_AVERAGE1= sum / 8 ; //ASKKKKK
			 int Rpeak;
			 int RR=4;
			 if(RR_LOW < RR < RR_HIGH){
				 peak = Rpeak;
				 sPKF = 0.125 * peak + 0.875*sPKF;


			 }
		 }
	}
}


#endif // FILTERS_H
