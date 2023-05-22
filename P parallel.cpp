#include<stdio.h>
#include<omp.h>
int main(){
	int steps=1000000000,nthread ;
	double s=1.0/steps,pi=0;
    double sum[4]={0,0,0,0};
    double st = omp_get_wtime();
	
	#pragma omp parallel num_threads(4)
	{
		int id = omp_get_thread_num();
		nthread = omp_get_num_threads();
		for(int i = id ; i < steps ; i+=nthread){
			double x = (i+0.5)*s;
			sum[id]+=4/(1+x*x);  
		}
	}
	
	for(int i =0; i<nthread ; i++)pi+=sum[i];
	pi/=steps;
	double sec = omp_get_wtime()-st;
	printf("pi = %f , sec = %f",pi,sec);
}
