#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUMELE 100000

int binarySearch(int A[],int key){
	int i,mid,low=0,high=NUMELE;
	mid=(high+low)/2;	
	while(high>=low){
		mid=(high+low)/2;
		if(key==A[mid]){
			return 0;
		}
		else if(key<A[mid]){
			high=mid-1;
		}
		else if(key>A[mid]){
			low=mid+1;
		}
		printf("%d %d %d\n",mid,high,low);
	}
	return 1;
}	
	
void main(){
	int A[100000],n,i,j,t,key=99;
	clock_t start,end;
	double total;

	FILE *fp;
	for(i=0;i<NUMELE;i++){
		scanf("%d",&A[i]);
	}
	

	start=clock();	
	if(binarySearch(A,key)==0){
		printf("Found");
	}
	else{
		printf("Not found");
	}
	end=clock();
	
	total=((double)(end-start))/CLOCKS_PER_SEC;
	printf("%lf seconds",total);
}


