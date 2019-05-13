#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUMELE 100000

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
 

int partition (int arr[], int low, int high)
{
	int j;
	int pivot=arr[high];    
	int i=(low-1);  
 
	for (j = low; j <= high- 1; j++){
		if (arr[j] <= pivot){
			i++;    
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}
 

void quickSort(int arr[], int low, int high){
	if(low<high){
		int pi = partition(arr, low, high);
 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void main(){
	int A[100000],n,i,j,t;
	clock_t start,end;
	double total;

	FILE *fp;
	for(i=0;i<NUMELE;i++){
		scanf("%d",&A[i]);
	}
	

	start=clock();	
	quickSort(A,0,NUMELE-1);
	end=clock();
	
	total=((double)(end-start))/CLOCKS_PER_SEC;
	printf("%lf seconds",total);	
}


