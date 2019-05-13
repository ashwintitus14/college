#include<iostream>
#include<string.h>

using namespace std;

class Person{
	protected:
		string name;
		int age;
	public:
		void read_person(){
			cout<<"Enter name: ";
			getline(cin,name);
			cout<<"\nEnter age: ";
			cin>>age;
		}
		void display_person(){
			cout<<"Name:"<<name;
			cout<<"\nAge: "<<age;
		}
};

class Employee : public Person{
	private:
		string company;
		double salary;
	public:
		void read_employee(){
			read_person();
			cout<<"\nEnter company: ";
			getline(cin,company);
			cout<<"\nEnter salary: ";
			cin>>salary; 
		}
		void display_employee(){
			cout<<"Name:"<<name;
			cout<<"\nAge: "<<age;
			cout<<"\nCompany: "<<company;
			cout<<"\nSalary: "<<salary;
		}
};

class Student : public Person{
	private:
		string school_name;
		int grade;
		char section;
	public:
		void read_student(){
			read_person();
			cout<<"\nEnter school name: ";
			getline(cin,school_name);
			cout<<"\nEnter grade: ";
			cin>>grade;
			cout<<"\nEnter section: ";
			cin>>section;
		}
		void display_student(){
			cout<<"Name:"<<name;
			cout<<"\nAge: "<<age;
			cout<<"\nSchool name: "<<school_name;
			cout<<"\nGrade: "<<grade;
			cout<<"\nSection: "<<section;
		}
};

int main(){
	Employee e;
	Student s;
	e.read_employee();
	s.read_student();
	e.display_employee();
	s.display_student();
	return 0;
}