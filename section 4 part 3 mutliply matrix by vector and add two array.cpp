#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

//int main(){
//	int n=1000,m=450;
//	int x[n][m],y[m],z[n];
//	for(int i=0 ; i < n ; i++ )
//	 for(int j = 0; j< m ; j++)
//	    x[i][j]=rand();
//	for(int i=0 ; i < n ; i++ )
//     	y[i]=rand();
//     
//    for(int i=0 ; i < n ; i++ )
//      z[i]=0;
//    double st = omp_get_wtime();
//     for(int i=0 ; i < n ; i++ )
//	 for(int j = 0; j< m ; j++)
//	   z[i]=z[i]+x[i][j] * y[j];
//	
//	  
//   	double sec = omp_get_wtime()-st;
//	printf("\nTime = %f\n",sec);    
//      
///*   	   
//	printf("x = \n");
//	for(int i=0 ; i < n ; i++ ){
//		 for(int j = 0; j< m ; j++)
//	       printf("%d ",x[i][j]);
//       printf("\n");
//	}
//
//	printf("y = \n");
//	for(int i=0 ; i < n ; i++ )
//     	printf("%d ",y[i]);
//   printf("\nz = \n");  
//    for(int i=0 ; i < n ; i++ )
//      	printf("%d ",z[i]);
//      
//*/
//}



int main(){
	int n=1000,m=450;
	int x[n][m],y[m],z[n] ,f;
	for(int i=0 ; i < n ; i++ )
	 for(int j = 0; j< m ; j++)
	    x[i][j]=rand();
	for(int i=0 ; i < n ; i++ )
     	y[i]=rand();
     
    for(int i=0 ; i < n ; i++ )
      z[i]=0;
    double st = omp_get_wtime();
    #pragma omp parallel num_threads(2)
    {
    #pragma omp for	 reduction(+:f) collapse(2)
    for(int i=0 ; i < n ; i++ )
	   for(int j = 0; j< m ; j++)
	    {
		   f=f+x[i][j] * y[j];
	       z[i]=f;
		}
	}
	  
   	double sec = omp_get_wtime()-st;
	printf("\nTime = %f\n",sec);    
}
