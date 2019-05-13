#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUMELE 100000

void main(){
	int A[100000],n,i,j,t;
	clock_t start,end;
	double total;

	FILE *fp;
	for(i=0;i<NUMELE;i++){
		scanf("%d",&A[i]);
	}
	

	start=clock();	
	for(i=0;i<NUMELE-1;i++){
		for(j=0;j<NUMELE-1-i;j++){
			if(A[j]>A[j+1]){
				t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}
	end=clock();
	
	total=((double)(end-start))/CLOCKS_PER_SEC;
	printf("%lf seconds",total);	
}


