#include<stdio.h>
#include"omp.h"
int main(){
	omp_set_num_threads(10);
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		if(ID==0)printf("Hello(%d)\n",ID);
		else printf("Here(%d)\n",ID);
	}
}
