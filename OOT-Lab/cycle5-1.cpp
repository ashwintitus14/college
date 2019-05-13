#include<iostream>
#include<string.h>

using namespace std;

class Employee{
	protected:
		string name;
		int eno,age;
	public:
		void read_employee(){
			cout<<"Enter name: ";
			getchar();
			getline(cin,name);
			cout<<"Enter eno: ";
			cin>>eno;
			cout<<"Enter age: ";
			cin>>age;
		}
		void display_employee(){
			cout<<"\nName: "<<name;
			cout<<"\nEmployee number: "<<eno;
			cout<<"\nAge: "<<age;
		}
};

class Salary: public Employee{
	private:
		int sal,netsal;
	public:
		void read_salary(){
			cout<<"\nEnter salary: ";
			cin>>sal;
		}	
		void display_salary(){
			netsal=sal*12;
			cout<<"\nAnnual salary: "<<netsal;
		}
};

int main(){
	Salary s;
	s.read_employee();
	s.read_salary();
	s.display_employee();
	s.display_salary();
	return 0;
}
