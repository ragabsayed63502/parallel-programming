#include<stdio.h>
#include<omp.h>
int fibser(int n){
	
	if(n<=1) return 1 ;
	return fibser( n-1)+fibser(n-2);
}
//
//int main(){
//double st = omp_get_wtime();
//int x = fibser(45);	
//double sec = omp_get_wtime()-st;
//printf("fib serial %d , time = %f",x,sec);
//}





int fib(int n){
	int x , y;
	
	if(n<=1) return 1 ;
	if(n<=30) return fibser(n);
	#pragma omp task shared(x) //if(n>30)
	x = fib( n-1);
	#pragma omp task shared(y) //if(n>30)
	y = fib(n-2);
	#pragma omp taskwait
	return x+y;
}


int main(){

int x;
double st = omp_get_wtime();
#pragma omp parallel
{
	#pragma omp single
	 x = fib(40);	
}
double sec = omp_get_wtime()-st;
printf("fib  %d , time = %f",x,sec);
}





// 1 1 2 3 5 8
