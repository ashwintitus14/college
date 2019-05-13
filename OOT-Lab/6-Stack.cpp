#include<iostream>


using namespace std;

class Stack{
	private:
		int top,A[5];
	public:
		Stack();
		void push();
		void pop();
		void display();
		
}s;

Stack::Stack(){
	top=-1;
}

void Stack::push(){
	if(top<3){
		cout<<"\nEnter element: ";
		cin>>A[++top];
	}
	else{
		cout<<"\nStack is full";
	}
}

void Stack::pop(){
	if(top!=-1){
		cout<<A[top];
		top-=1;
	}
	else{
		cout<<"\nStack is empty";
	}
}

void Stack::display(){
	if(top==-1){
		cout<<"Stack is empty";
	}
	else{
		for(int i=top;i>-1;i--){
			cout<<A[i]<<'\n';
		}
	}
}

int main(){
	cout<<"****STACK****";
	int ch;
	char opt;
	Stack s;
	do{
		cout<<"\n1.Push\n2.Pop\n3.Display\nEnter choice:";
		cin>>ch;
		switch(ch){
			case 1:{
				s.push();
				break;
			}
			case 2:{
				s.pop();
				break;
			}
			case 3:{
				s.display();
				break;
			}
		}
		cout<<"\nContinue? Y/N: ";
		cin>>opt;
	}while(opt=='Y'||opt=='y');
	return 0;
}
