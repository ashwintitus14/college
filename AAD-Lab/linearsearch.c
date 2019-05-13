#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUMELE 100000

int linearSearch(int A[],int key){
	int i;
	for(i=0;i<NUMELE;i++){
		if(A[i]==key){
			return 0;
		}
	}
	return 1;
}	
	
void main(){
	int A[100000],n,i,j,t,key=25;
	clock_t start,end;
	double total;

	FILE *fp;
	for(i=0;i<NUMELE;i++){
		scanf("%d",&A[i]);
	}
	

	start=clock();	
	if(linearSearch(A,key)==0){
		printf("Found");
	}
	else{
		printf("Not found");
	}
	end=clock();
	
	total=((double)(end-start))/CLOCKS_PER_SEC;
	printf("%lf seconds",total);
}


