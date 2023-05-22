//#include<stdio.h>
//#include<omp.h>
//int main(){
//	int n,nthreads;
//	double s=0;
//	printf("Enter n:");
//	scanf("%d",&n);
//	double st =  omp_get_wtime();
//	#pragma omp parallel num_threads(3)
//	{
//		double sum;
//	  nthreads = omp_get_num_threads();
//	  int id = omp_get_thread_num();
//	  for (int i = id; i<n ; i+=nthreads)
//	  	sum+=i;
//	  #pragma omp critical  // atmoic or barrier
//	  {		 
//	   	s+=sum;
//	  }
//	  	
//	}
//	double time = omp_get_wtime()-st;  
//	printf("sum = %ld , time = %f s",s,time);
//}

#include<stdio.h>
#include<omp.h>
int main(){
	int steps=1000000000,nthread ;
	double s=1.0/steps,pi=0;
    double st = omp_get_wtime();
	
	#pragma omp parallel num_threads(4)
	{
		int id = omp_get_thread_num();
		nthread = omp_get_num_threads();
		double sum , x;
		for(int i = id ; i < steps ; i+=nthread){
			 x = (i+0.5)*s;
			sum+=4/(1+x*x);  
		}
		#pragma omp critical
		{
			pi+=sum*s;
		}
		
	}	
	double sec = omp_get_wtime()-st;
	printf("pi = %f , sec = %f",pi,sec);
}
