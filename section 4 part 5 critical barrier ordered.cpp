#include<stdio.h>
#include<omp.h>


//int main(){
//	int x=0,y=0;
//	#pragma omp parallel num_threads(3)
//	{
//		#pragma omp single
//		x+=1;
//	}
//	printf("x = %d",x);
//}



/*
- critical and "barrier" have different meanings in parallel programming. 
"Critical" refers to a segment of code that can only be executed by one thread at a time,
- barrier refers to a synchronization point that ensures 
all threads have reached a specific point in the program before continuing

- atomic like critical but statment is simple
- ORDERED like serial

*/




int main(){
	int x=0,y=0;
	#pragma omp parallel num_threads(3)
	{
	#pragma omp ORDERED//critical // atomic
	{
		x+=1;
		printf("Thread num = %d\n",omp_get_thread_num());
		y+=x+1;
		printf("x = %d, y = %d\n",x,y);
	}
		
	}
}

// barrier

//
//int main(){
//	int x[2]={2,3};
//	int y[2]={5,6};
//	int z[2];
//	int f[2];
//	#pragma omp parallel num_threads(3)
//	{
////		#pragma omp barrier
////		for (int i =0; i<2 ; i++)z[i]=x[i]+y[i]; 
////		
////		for (int i =0; i<2 ; i++)z[i]=x[i]+y[i];
//		
////           or
//
//        #pragma omp for
//		for (int i =0; i<2 ; i++)z[i]=x[i]+y[i]; 
//		
//		#pragma omp for
//		for (int i =0; i<2 ; i++)z[i]=x[i]+y[i];
//		
//	}
//	printf("x = %d",x);
//}
