#include <time.h>
#include <stdlib.h>
#include<stdio.h>
#define MAXELE 100000

void main(){
	int i;	
	FILE *fp;
	fp = fopen("rand.txt","w");
	srand(time(NULL));   
	for(i=0;i<MAXELE;i++)
	{	
		fprintf(fp,"%d\n",rand()%100);
	}
	fclose(fp);
}
