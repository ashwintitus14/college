#include<iostream>

using namespace std;

class account{
	private:
		char name[30];
		int acno=0;
		float balance;
	public:
		void create(int);
		void deposit();
		void display();                                  
};

void account::create(int no){
	acno=no;
	cout<<"\nAccount no: "<<acno;
	cout<<"\nEnter name: ";
	cin>>name;
	balance=0;
}

void account::deposit(){
	int amt;
	cout<<"\nEnter amount:";
	cin>>amt;
	balance=balance+amt;
}

void account::display(){
	cout<<"\nName: "<<name;
	cout<<"\nAccount number: "<<acno;
	cout<<"\nBalance: "<<balance<<"\n";
}

int main(){
	account ac[100];
	int ch,no=0,n;
	char opt;
	do{
		cout<<"\n1.Create an account\n2.Deposit money\n3.View balance\nEnter choice: ";
		cin>>ch;
		switch(ch){
			case 1:{
				no++;
				ac[no].create(no);
				break;
			}
			case 2:{
				cout<<"\nEnter account no: ";
				cin>>n;
				ac[n].deposit();
				break;
			}
			case 3:{
				cout<<"\nEnter account no: ";
				cin>>n;
				ac[n].display();
				break;
			}
		}
		cout<<"\nContinue? Y/N: ";
		cin>>opt;
	}while(opt=='Y' || opt=='y');
	return 0;
}
