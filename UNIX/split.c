#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define line_max 200
#define filename_max 100

int split(char filename[], int size){
	char line[line_max], generated_filename[10];
	generated_filename[0] = 'x';       //prefix
	generated_filename[1] = 'a';
	generated_filename[2] = '`';
	int i = 0;
		
	FILE *fp, *fw;
	fp = fopen(filename, "r");
	while(fgets(line,200,fp) != NULL){
		if(i == 0){	
			if(generated_filename[2] < 'z'){
				generated_filename[2]++;
			}
			else{
				generated_filename[1]++;
				generated_filename[2] = 'a';
			}
			if(generated_filename[1] > 'z'){
				printf("File limit: 676 reached\n");
				exit(0);
			}
			
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
	}
	fclose(fp);
	return 0;
}
int main(int argc, char* argv[]){
	
	char filename[filename_max];
	int size = 5;		/*size: number of lines in each new file*/
	
	switch(argc){
		case 1:{
				printf("No command line arguments detected\n");
				exit(0);
		}
		case 2:{
				strcpy(filename, argv[1]);
				split(filename, size);
				break;
		}
		case 3:{
			       printf("invalid number of lines: %s\n",argv[2]);
			       break;
		}
		case 4:{
			       if(strcmp(argv[1],"-l") == 0){
				       size = atoi(argv[2]);
				      strcpy( filename,argv[3]);
				}
			       split(filename, size);
			       break;
		}
		default:{
				printf("Too many arguments!\n");
		}	
	}
	return 0;
}
