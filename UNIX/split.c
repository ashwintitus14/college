#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	char filename[100],generated_filename[10];
	char line[200];
	int size = 5,i = 0;		/*size: number of lines in each new file*/
	generated_filename[0] = 'a';		
	
	switch(argc){
		case 1:{
				printf("No command line arguments detected\n");
				exit(0);
		}
		case 2:{
				strcpy(filename, argv[1]);
				FILE *fp, *fw;
				fp = fopen(filename, "r");
				while(fgets(line,200,fp) != NULL){
					if(i == 0){	
						generated_filename[0]++;
						fw = fopen(generated_filename,"w+");
					}
					if(i<size){
						fputs(line,fw);
						i++;
						if(i == size){
							fclose(fw);
							i = 0;
						}
					}
				printf("%d\n",i);	
				}
				fclose(fp);
				break;
		}
	}
	return 0;
}
