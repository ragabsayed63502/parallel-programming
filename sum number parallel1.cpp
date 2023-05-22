#include<stdio.h>
#include<omp.h>
int main(){
	int num,n;
	printf("Enter n:");
	scanf("%d",&n);
	
    printf("Enter number of threads:");
    scanf("%d",&num);
    
    int sum[num],s=0;
    for (int i = 0; i<num ;i++)sum[i]=0;
    
    double st =  omp_get_wtime();
	#pragma omp  parallel num_threads(num)
	{	
	  int id = omp_get_thread_num();
	  for (int i=id ; i<=n ; i+=omp_get_num_threads())
	  	sum[id]=sum[id]+i;
	}
	
	for (int i=0; i< num ; i++)
	  s+=sum[i];
	double time = omp_get_wtime()-st;  
	printf("sum = %d , time = %f s",s,time);
}
