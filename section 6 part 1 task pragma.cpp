#include<stdio.h>
#include<omp.h>
//int main(){
//	int x = 2, y=3;
//	int z,f;
//#pragma omp parallel
//{  
//	#pragma omp single
//	#pragma omp task
//	{
//		z = x+y;
//		printf("the result = %d from thread = %d\n",z,omp_get_thread_num());
//	}
//    #pragma omp single
//	#pragma omp task
//	{
//		f = x-y;
//		printf("the result = %d from thread = %d\n",f,omp_get_thread_num());
//	}
//}
//		
//}









int main(){
	int n= 400 , s=100;
	int x[n] , final = 0;
	for(int i = 0; i< n; i++)x[i]=2;
	#pragma omp parallel
	{
	#pragma omp for
	  for (int i =0 ; i< n ;i+=s){
	        int start = i, end = i  + s - 1;
		    printf("thread num  parallel for = %d, start = %d, end = %d\n", omp_get_thread_num(),start,end)	;
		    #pragma omp task
		    {    
		        int sum=0;
		        printf("thread num  parallel from task = %d, start = %d , end = %d\n", omp_get_thread_num(),start,end)	;
		        for (int j = start ; j<=end  ; j++)
				    sum+=x[j];	
			    
				#pragma omp critical 	
        		final+=sum;
			
			}
			
	   }
	 #pragma omp single
	 printf("the final = %d",final);	
	}
	
	
}





