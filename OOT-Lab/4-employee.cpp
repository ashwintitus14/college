#include<iostream>

using namespace std;

class employee{
	private:
		char name[30];
		char designation[30];
		int age;
		int salary;
	public:
		void read();
		void display();
};

void employee::read(){
	cout<<"\nName: ";
	cin>>name;
	cout<<"\nDesignation: ";
	cin>>designation;
	cout<<"\nAge: ";
	cin>>age;
	cout<<"\nSalary: ";
	cin>>salary;
}

void employee::display(){
	cout<<"\nName: "<<name;
	cout<<"\nDesignation: "<<designation;
	cout<<"\nAge: "<<age;
	cout<<"\nSalary: "<<salary<<"\n";
}

int main(){
	int n,i;
	cout<<"\nEnter number of employees: ";
	cin>>n;
	employee e[n];
	for(i=0;i<n;i++){
		e[i].read();
	}	
	for(i=0;i<n;i++){
		e[i].display();
	}
	return 0;
}
