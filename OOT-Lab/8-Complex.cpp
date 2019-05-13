#include<iostream>

using namespace::std;

class Complex{
	private:
		float im,re;
	public:
		void display();
		void input();	
		Complex operator +(Complex &X);
};

void Complex::display(){
	cout<<re<<"+ "<<im<<"i\n";
}

void Complex::input(){
	cout<<"\nEnter real part: ";
	cin>>re;
	cout<<"\nEnter imaginary part: ";
	cin>>im;
}

Complex Complex::operator +(Complex &X){
	Complex temp;
	temp.im=im+X.im;
	temp.re=re+X.re;
	return temp;
}

int main(){
	Complex A,B,C;
	A.input();
	B.input();
	C=A+B;
	C.display();
	return 0;
}
