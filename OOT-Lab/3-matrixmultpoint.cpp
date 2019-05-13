#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int a,b,c,d,i,j,k;
	cout<<"No. of rows in matrix 1: ";
	cin>>a;
	cout<<"No. of columns in matrix 1: ";
	cin>>b;
	cout<<"No. of rows in matix 2: ";
	cin>>c;
	cout<<"No. of columns in matrix 2: ";
	cin>>d;
	
	int A[a][b];
	int B[c][d];
	int SUM[a][d];
	if(b!=c){
		cout<<"b!=c";
		exit(0);
		
	}
	
	cout<<"Enter elements into matrix 1: ";
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			cin>>A[i][j];
		}
	}
	cout<<"Enter elements into matrix 2: ";
	for(i=0;i<c;i++){
		for(j=0;j<d;j++){
			cin>>B[i][j];
		}
	}
	
	for(i=0;i<a;i++){
		for(j=0;j<d;j++){
			*(*(SUM+i)+j)=0;
			for(k=0;k<b;k++){
				*(*(SUM+i)+j)+=*(*(A+i)+k) * *(*(B+k)+j);
			}
			
		}
	}
	
	for(i=0;i<c;i++){
		for(j=0;j<d;j++){
			cout<<SUM[i][j]<<"\t";
		}
		cout<<"\n";
	}
	getch();
	return 0;
	
}
