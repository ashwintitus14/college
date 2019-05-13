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
	for(i=0;i<NUMELE-1;i++){
		pos=i;
		for(j=i+1;j<NUMELE;j++){
			if(A[pos]<A[j]){
				pos=j;
			}
		}
		if(pos!=i){	
			t=A[i];
			A[i]=A[pos];
			A[pos]=t;
		}
	}
	end=clock();
	
	total=((double)(end-start))/CLOCKS_PER_SEC;
	printf("%lf seconds",total);	
}


