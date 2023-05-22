#include<stdio.h>
#include<omp.h>

int main(){
	int n;long sum=0;
	printf("Enter num: "); 
	scanf("%d",&n);
	double s = omp_get_wtime(); 
	for (int i=1 ; i<= n ;i++ ){
		sum+=i;
	}
	double sec = omp_get_wtime()-s;
	printf("sum = %d, sec: %f",sum,sec);
}
