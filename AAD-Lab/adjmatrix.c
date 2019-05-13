#include<stdio.h>

void main(){
	int n,e,i,l;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	int A[n][n];
	for(i=0;i<n;i++){
		for(l=0;l<n;l++){
			A[i][l]=0;
		}
	}
	printf("\nEnter number of edges: ");
	scanf("%d",&e);
	for(i=1;i<=e;i++){
		int j,k;		
		printf("Enter vertices of edge %d: ",i);
		scanf("%d %d",&j,&k);
		A[j][k]=1;
		A[k][j]=1;
	}
	for(i=0;i<n;i++){
		for(l=0;l<n;l++){
			printf("%d ",A[i][l]);
		}
		printf("\n");
	}
}	
	

