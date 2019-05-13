#include<iostream>
#include<string.h>

using namespace std;

class Student{
	protected:
		int roll_no;
		string name;
		int semester;
	public:
		void read_student(){
			cout<<"\nEnter roll number: ";
			cin>>roll_no;
			cout<<"Enter name: ";
			getchar();
			getline(cin,name);
			cout<<"Enter semester: ";
			cin>>semester;
		}
		void display_student(){
			cout<<"\nRoll number: "<<roll_no;
			cout<<"\nName: "<<name;
			cout<<"\nSemester: "<<semester;
		}
};

class Sports{
	protected:
		int sports_mark;
	public:
		void read_sports(){
			cout<<"Enter sports marks: ";
			cin>>sports_mark;
		}
		void display_sports(){
			cout<<"\nSports marks: "<<sports_mark;
		}
};

class Statement: public Student, public Sports{
	protected:
		int mark1, mark2, mark3, total;
	public:
		void read_marks(){
			cout<<"Enter marks of 3 subjects";
			cin>>mark1>>mark2>>mark3;	
		}
		void display_statement(){
			total=mark1+mark2+mark3+sports_mark;
			cout<<"\nTotal: "<<total;
		}		
};

int main(){
	Statement s;
	s.read_student();
	s.read_sports();
	s.read_marks();
	s.display_student();
	s.display_sports();
	s.display_statement();
	return 0;
}
