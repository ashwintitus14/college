#include<iostream>

using namespace std;

void swap1(){
	int a,b,t;
	cout<<"Enter a and b:\n ";
	cin>>a>>b;
	t=a;
	a=b;
	b=t;
	cout<<"After swapping\n a: "<<a<<" b: "<<b;
}

void swap2(int a, int b){
	int t;
	t=a;
	a=b;
	b=t;
	cout<<"After swapping\n a: "<<a<<" b: "<<b;
}

void swap3(int *a, int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
	cout<<"After swapping\n a: "<<*a<<" b: "<<*b;	
}

void swap4(int &a, int &b){
	int t;
	t=a;
	a=b;
	b=t;
	cout<<"After swapping\n a: "<<a<<" b: "<<b;	
}

void swap5(int a=5,int b=8){
	int t; 
	t=a;
	a=b;
	b=t;
	cout<<"After swapping\n a: "<<a<<" b: "<<b;
}

int main(){
	int a,b,ch;
	char opt;
	
	do{	
		cout<<"Swap \n1.Without parameters \n2.Call by value \n3.Call by address \n4.Call by reference \n5.Default values\n";
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch){
			case 1: {
				swap1();
				break;
			}
			case 2:	{
				cout<<"Enter a and b:\n ";
				cin>>a>>b;
				swap2(a,b);
				break;
			}
			case 3: {
				cout<<"Enter a and b:\n ";
				cin>>a>>b;
				swap3(&a,&b);
				break;
			}
			case 4:	{
				cout<<"Enter a and b:\n ";
				cin>>a>>b;
				swap4(a,b);
				break;
			}
			case 5:	{
				swap5();
				break;
			}
		}
		cout<<"\nContinue? Y/N ";
		cin>>opt;	
	}while(opt=='Y'||opt=='y');
	return 0;
}


