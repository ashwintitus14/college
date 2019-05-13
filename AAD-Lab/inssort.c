#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUMELE 10000

void main(){
	int A[10000],n,i,j,t,pos;
	clock_t start,end;
	double total;

	FILE *fp;
	for(i=0;i<NUMELE;i++){
		scanf("%d",&A[i]);
	}
	

	start=clock();	
	for (i=1;i<=NUMELE-1;i++){
    		j = i;
    		while (j>0 && A[j-1]>A[j]){
      			t=A[j];
      			A[j]=A[j-1];
      			A[j-1]=t;
 			j--;
    }
  }
	end=clock();
	
	total=((double)(end-start))/CLOCKS_PER_SEC;
	printf("%lf seconds",total);	
}


