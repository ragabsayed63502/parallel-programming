//#include<stdio.h>
//#include<omp.h>
//int main(){
//	int n=1000000000,nth,id;
//	double sum;
//	double st = omp_get_wtime();
//	#pragma omp parallel num_threads(2) private(id)
//	{
//		id = omp_get_thread_num();
//		#pragma omp for reduction(+:sum) // to sum two local 
//		for(int i = 0 ;i < n ; i++){
////			printf("Iteration num = %d , From Thread = %d\n",i,id);
//			sum+=i;
//		} 
//		
//	}
//	double sec = omp_get_wtime()-st;
//	printf("sum = %f , Time = %f",sum,sec);
//
//}



//// Pi

//#include<stdio.h>
//#include<omp.h>
//int main(){
//	int steps= 100000000;
//	double s = 1.0/steps;
//	double sum,x,pi;
//	double st = omp_get_wtime();
//	#pragma omp parallel num_threads(2) private(x)
//	{
//		#pragma omp for reduction(+: sum)// to divid code on threads
//	   for(int i = 0 ; i< steps ; i++){
//	   	x = (i + 0.5) * s;
//		sum+=  4 / (1+x*x); 
//	   }
//	}
//	pi=sum*s;
//	double sec = omp_get_wtime()-st;
//	printf("Pi = %f , Time = %f",pi,sec);
//}



// sum two array

//#include<stdio.h>
//#include<omp.h>
//#include<stdlib.h>
//int main(){
//	int n=10;
//	int a[n],b[n],c[n];
//	for (int i =0 ; i< n ; i++){a[i]=rand();b[i]=rand();	}
//	double st = omp_get_wtime();
//	for (int i =0 ; i< n ; i++)c[i]=a[i]+b[i];	
//	double sec = omp_get_wtime()-st;
//	printf("Time = %f",sec);
//}
//
//
//

// To convert parallel


#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main(){
	int n=10;
	int a[n],b[n],c[n];
	for (int i =0 ; i< n ; i++){a[i]=rand();b[i]=rand();	}
	double st = omp_get_wtime();
	#pragma omp parallel 
	{
	   #pragma omp for 
		for (int i =0 ; i< n ; i++)c[i]=a[i]+b[i];
	}
	double sec = omp_get_wtime()-st;
	printf("Time = %f",sec);
}





