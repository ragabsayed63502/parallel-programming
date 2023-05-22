#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
int main(){
	int n,nthreads;
	printf("Enter n:");
	scanf("%d",&n);
	
	int x[n],y[n],z[n],s[4]={0,0,0,0};
	
	for(int i =0; i < n ;i++){
		x[i]=rand();
        y[i]=rand();
	}
	
	double st =  omp_get_wtime();
	#pragma omp parallel num_threads(4)
	{
		int id = omp_get_thread_num();
		int nth = omp_get_num_threads();
	   nthreads=nth; 
		for(int i = id ; i <n ; i+=nth)
		  z[i]=x[i]+y[i];
	}
	
	double time = omp_get_wtime()-st;  
	printf("time = %f s",time);
}
