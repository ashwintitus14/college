#include<iostream>
#include<string>

using namespace std;

class Student{
	protected:
		int roll_no;
		string name;
		int semester;
	public:
		void read_student(){
			cout<<"Enter roll number :";
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

class Test: public Student{
	protected:
		int mark[6];
	public:
		void read_test(){
			for(int i=1;i<6;i++){
				cout<<"Enter mark "<<i<<": ";
				cin>>mark[i];
			}
		}
		void display_test(){
			for(int i=1;i<6;i++){
				cout<<"\nMark "<<i<<": "<<mark[i];	
			}
		}
};

class Result: public Test{
	private:
		int total=0;
	public:
		void calc(){
			for(int i=1;i<6;i++){
				total+=mark[i];
			}
			cout<<"\nTotal: "<<total;
		}
};

int main(){
	Result r;
	r.read_student();
	r.read_test();
	r.display_student();
	r.display_test();
	r.calc();
	return 0;
}
