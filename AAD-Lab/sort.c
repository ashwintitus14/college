#include<stdio.h>
#include<stdlib.h>
#define NUMELE 100000

void main(){
	int A[100000],n,i,j,t,pos;
	
	FILE *fp;
	for(i=0;i<NUMELE;i++){
		scanf("%d",&A[i]);
	}
	

	
	/*for(i=0;i<NUMELE-1;i++){
		for(j=0;j<(NUMELE-1-i);j++){
			if(A[j]>A[j+1]){
				t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}*/
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
	FILE *fp1;
	fp1 = fopen("desc.txt", "w");
	for(i=0;i<NUMELE;i++){
		fprintf(fp1,"%d\n",A[i]);
	}
	fclose(fp1);
	
}




