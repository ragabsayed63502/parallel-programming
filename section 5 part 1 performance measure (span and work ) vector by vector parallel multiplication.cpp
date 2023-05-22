#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

//int main(){
//	int n= 200000;
//	int x[n],y[n],sum=0;
//	double st = omp_get_wtime();
//	for(int i =0 ; i< n ; i++){
//		x[i]=rand()%10;
//		y[i]=rand()%10;
//	}
//	
//	for(int i =0 ; i< n ; i++) sum+=x[i]*y[i];
//	double sec = omp_get_wtime()-st;
////	for(int i =0 ; i< n ; i++){
////	printf("x = %d, y = %d\n",x[i],y[i]);
////	}
//	printf("sum = %d , Time = %d",sum,sec);
//}





int main(){
	int n = 200000;
	int x[n],y[n] , sum;
	double st = omp_get_wtime();
	#pragma omp parallel num_threads(3)
	{
		#pragma omp parallel for // log(n)
		for(int i = 0 ; i < n;i++){
			x[i] = rand()%10;
			y[i] = rand()%10;
		}
		#pragma omp for reduction(+:sum)
		for(int i = 0 ; i < n;i++) 
		 sum+=x[i]*y[i];
				
	}
	double sec = omp_get_wtime()-st;
	
//	for(int i =0 ; i< n ; i++){
//	printf("x = %d, y = %d\n",x[i],y[i]);
//	}
	
	printf("sum = %d , Time = %f",sum,sec);
	
}
