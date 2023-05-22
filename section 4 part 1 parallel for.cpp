//#include<stdio.h>
//#include<omp.h>
//int main(){
//	// to solve problem value public and use in multiple threads
//	int id , nth;
//	double st = omp_get_wtime();
//	#pragma omp parallel private(id) shared(nth)
//	{
//	 id = omp_get_thread_num();
//	 nth = omp_get_num_threads();
//	for (int i = id ; i< 20 ; i+=nth)
//	  printf("Hello World = %d , from thread = %d\n",i,id);
//	}
//	double sec = omp_get_wtime()-st;
//	printf("Time = %f",sec);
//}



// to do workshared

#include<stdio.h>
#include<omp.h>
int main(){
	int id , nth;
	double st = omp_get_wtime();
	
	#pragma omp parallel private(id) shared(nth) //	 to solve problem value public and use in multiple threads
	{
	 id = omp_get_thread_num();
	 nth = omp_get_num_threads();
//	 #pragma omp for schedule(static) // defult
//   #pragma omp for schedule(static , 3) // every thread excuit 2 operation
//     #pragma omp for schedule(dynamic) // excut thread the fast
//	 #pragma omp for schedule(dynamic , 2) //  excut thread the fast
//     #pragma omp for schedule(auto)//manul
 #pragma omp for schedule(guided) // speacial case from dynamic
	for (int i = 0 ; i< 20 ; i++)
	  printf("Hello World = %d , from thread = %d\n",i,id);
	}
	double sec = omp_get_wtime()-st;
	printf("Time = %f",sec);
}

