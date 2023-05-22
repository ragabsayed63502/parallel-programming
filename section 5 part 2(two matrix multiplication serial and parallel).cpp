#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main(){
	int n = 400, m = 400, k=400;
	int x[n][m] , y[m][k] , z[n][k];
	
	double st = omp_get_wtime();
	#pragma omp parallel
	{
	
	#pragma omp for collapse(2)
	for(int i =0 ; i < n; i++)
	for(int j =0 ; j < m; j++)
	  x[i][j]=rand()%10;

	#pragma omp for collapse(2)	  
    for(int i =0 ; i < m; i++)
	for(int j =0 ; j < k; j++)
	  y[i][j]=rand()%10;
	 
	 
	#pragma omp for collap	se(2)
	for(int i =0 ; i < n; i++)
	for(int j =0 ; j < k; j++)
	{
		z[i][j]=0;
        for (int f =0 ; f < m; f++)	
          z[i][j]+=x[i][f]*y[f][j];
	}
	
	
	
}
	double sec = omp_get_wtime()-st;
//	printf("X = \n");
//	for(int i =0 ; i < n; i++){
//	for(int j =0 ; j < m; j++)
//	  printf("%d ",x[i][j]);
//	  printf("\n");
//   }
//    
//	printf("Y = \n");
//	for(int i =0 ; i < m; i++){
//	for(int j =0 ; j < k; j++)
//	  printf("%d ",y[i][j]);
//	  printf("\n");
//   }
   
//   printf("z = \n");
//	for(int i =0 ; i < n; i++){
//	for(int j =0 ; j < k; j++)
//	  printf("%d ",z[i][j]);
//	  printf("\n");
//   }
printf("Time = %f",sec);
}
