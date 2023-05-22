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
	//serial
		double st =  omp_get_wtime();
	for (int i = 0 ; i< n ; i++)z[i]=x[i]+y[i];
	//for (int i = 0 ; i< n ; i++)printf("%d ",z[i]);
    double time = omp_get_wtime()-st;  
	printf("time = %f s",time); 

	
	
}
