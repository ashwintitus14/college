#include<iostream>

using namespace std;

void sum(int a, int b){
	cout<<"Sum: "<<a+b;
}

void dif(int a, int b){
	cout<<"Difference: "<<a-b;
}

void pro(int a, int b){
	cout<<"Product: "<<a*b;
}

void quo(int a, int b){
	cout<<"Quotient: "<<a/b;
}

int main(){
	int a,b,ch;
	char opt;
	do{
		cout<<"Enter a and b \n";
		cin>>a;
		cin>>b;
		cout<<"\nOperations:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nEnter choice: ";
		cin>>ch;
		switch(ch){
			case 1:	{
				sum(a,b);
				break;
			}
			case 2: {
				dif(a,b);
				break;
			}
			case 3: {
				pro(a,b);
				break;
			}
			case 4: {
				quo(a,b);
				break;
			}
		}
		cout<<"\nContinue? Y/N :";
		cin>>opt;
	}while(opt=='Y'||opt=='y');
}
