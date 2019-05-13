#include<iostream>

using namespace::std;

class Volume{
	public:
		Volume(float r);
		Volume(float l,float b);
		Volume(double a);
};

Volume::Volume(float r){
	float vol=(4.0/3.0)*3.14*r*r*r;
	cout<<vol;
}

Volume::Volume(float l,float b){
	float vol=l*b;
	cout<<vol;
}

Volume::Volume(double a){
	double vol=a*a*a;
	cout<<vol;
}

int main(){
	float l,r,w;
	int ch;
	char opt;
	double a;
	do{
		cout<<"VOLUME:\n1.Sphere\n2.Cube\n3.Rectangular Box";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"\nEnter radius: ";
				cin>>r;
				Volume v(r);
				break;
			}
			case 2:{
				cout<<"\nEnter side length: ";
				cin>>a;
				Volume v(a);
				break;
			}
			case 3:{
				cout<<"\nEnter length: ";
				cin>>l;
				cout<<"\nEnter width: ";
				cin>>w;
				Volume v(l,w);
				break;
			}
		}
		cout<<"\nContinue? Y/N";
		cin>>opt;
	}while(opt=='Y' || opt=='y');
}



