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
			getchar();
			getline(cin,name,'\n');
			cout<<"Enter age: ";
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
			cout<<"Enter company: ";
			getchar();
			getline(cin,company);
			cout<<"Enter salary: ";
			cin>>salary; 
		}
		void display_employee(){
			cout<<"\nName:"<<name;
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
			cout<<"Enter school name: ";
			getchar();
			getline(cin,school_name);
			cout<<"Enter grade: ";
			cin>>grade;
			cout<<"Enter section: ";
			cin>>section;
		}
		void display_student(){
			cout<<"\nName:"<<name;
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
