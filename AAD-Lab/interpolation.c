#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUMELE 100000

int interpolation(int A[], int key, int n){
	int high=n-1,pos,low=0;
	while(low<=high && key<=A[high] && key>=A[low]){
		pos=low+(((double)(high-low)/(A[high]-A[low]))*(key-A[low]));
		if(key==A[pos]){
			return pos;
		}
		else if(key<A[pos]){
			high=pos-1;
		}
		else if(key>A[pos]){
			low=pos+1;
		}
	}
	return -1;
}

void main(){
	int A[100000],n,i,j,t,key=5;
	clock_t start,end;
	double total;

	FILE *fp;
	for(i=0;i<NUMELE;i++){
		scanf("%d",&A[i]);
	}
	

	start=clock();	
	if(interpolation(A,key,NUMELE)!=-1){
		printf("Found");
	}
	else{
		printf("Not found");
	}
	end=clock();
	
	total=((double)(end-start))/CLOCKS_PER_SEC;
	printf("%lf seconds",total);
}


 	
