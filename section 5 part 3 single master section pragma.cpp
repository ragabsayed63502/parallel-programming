#include<stdio.h>
#include<omp.h>
//int main(){
//	int x[4] = {5,4,3,5};
//	int y[4] = {5,4,3,8};
//	int z[4], f[4];
//	
// double st = omp_get_wtime();
// #pragma omp parallel
// {
// 	#pragma omp for nowait
// 	for (int i =0 ; i < 4; i++)
// 		z[i]=x[i]+y[i];
// 	  // barrier
//	 #pragma omp for nowait	
//	for (int i =0 ; i < 4; i++)
// 		f[i]=x[i]*y[i]; 
// }
// double sec = omp_get_wtime()-st;
// printf("Time = %f",sec);
//}

//------------------------------------------

//int main(){
//	int x=3, y=4,z,m,sum=0;
//	
// double st = omp_get_wtime();
// #pragma omp parallel
// {
// 	#pragma omp for nowait
// 	for (int i =0 ; i < 10; i++){
//	 
// 	sum=0;	
// 	printf("sum array thread num = %d\n",omp_get_thread_num());
//    }
//
//    #pragma omp master
//	{
//	z=x+y;	
//	printf("sum x and y  thread num = %d\n",omp_get_thread_num());
//    }	
//	
//	#pragma omp single
//	{
//		m=x*y;
//		printf("thread num = %d\n",omp_get_thread_num());
//	}
// }
// double sec = omp_get_wtime()-st;
// printf("Time = %f",sec);
//}




//-------------------------------------

int main(){
	int x[4] = {5,4,3,5};
	int y[4] = {5,4,3,8};
	int z[4], f[4];
	
 double st = omp_get_wtime();
 #pragma omp parallel
 {
 	#pragma omp sections
 	{
		#pragma omp section
		for (int i =0 ; i < 10; i++){
			z[i]=x[i]+y[i];
			printf("thread num of += %d , int i = %d\n",omp_get_thread_num(),i);
		}
			
		  
		#pragma omp section
		for (int i =0 ; i < 10; i++)
			{
				f[i]=x[i]*y[i]; 
			printf("thread num of *= %d , int i = %d\n",omp_get_thread_num(),i);
			}	
	}
 	
 }
 
 double sec = omp_get_wtime()-st;
 printf("Time = %f",sec);
}
