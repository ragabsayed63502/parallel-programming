#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
int main(){
	int n,nthreads;
	printf("Enter n:");
	scanf("%d",&n);
	
	int x[n],s[4]={0,0,0,0};
	
	//printf("Enter array:");
	//for(int i =0; i < n ;i++)scanf("%d",x+i);
	for(int i =0; i < n ;i++)x[i]=rand();
	double st =  omp_get_wtime();
	#pragma omp parallel num_threads(4)
	{
		int id = omp_get_thread_num();
		int nth = omp_get_num_threads();
	   nthreads=nth; 
		for(int i = id ; i <n ; i+=nth)
		  s[id]=x[i]+s[id];
	}
	
	long long sum=0;
	for(int i=0; i < nthreads ; i++) sum+=s[i];
	double time = omp_get_wtime()-st;  
	printf("sum = %ld , time = %f s",sum,time);
	
}
