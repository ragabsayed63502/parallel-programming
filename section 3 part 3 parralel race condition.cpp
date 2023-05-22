#include<stdio.h>
#include<omp.h>
//int main(){
//	int x,y,z;
//	x=5;
//	y=4;
//	#pragma omp parallel num_threads(2)
//	{
//	int id = omp_get_thread_num();
//	if(id == 0) z=x-y;
//	else z=x+y;
//	printf("number of threads = %d\t",omp_get_num_threads());
//	printf("the result = %d, from thread %d\n",z,id);
//	}
//	printf("The Result %d",z);
//
//}


//First solution race codation

int main(){
	int x,y;
	x=5;
	y=4;
	#pragma omp parallel num_threads(2)
	{
	int z;
	int id = omp_get_thread_num();
	if(id == 0) z=x-y;
	else z=x+y;
	printf("number of threads = %d\t",omp_get_num_threads());
	printf("the result = %d, from thread %d\n",z,id);
	}

}
