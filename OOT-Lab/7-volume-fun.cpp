#include<iostream>

using namespace::std;

class Volume{
	public:
		void volume(float r);
		void volume(float l,float b);
		void volume(double a);
};

void Volume::volume(float r){
	float vol=(4.0/3.0)*3.14*r*r*r;
	cout<<vol;
}

void Volume::volume(float l,float b){
	float vol=l*b;
	cout<<vol;
}

void Volume::volume(double a){
	double vol=a*a*a;
	cout<<vol;
}

int main(){
	float l,r,w;
	int ch;
	char opt;
	double a;
	Volume v;
	do{
		cout<<"VOLUME:\n1.Sphere\n2.Cube\n3.Rectangular Box";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"\nEnter radius: ";
				cin>>r;
				v.volume(r);
				break;
			}
			case 2:{
				cout<<"\nEnter side length: ";
				cin>>a;
				v.volume(a);
				break;
			}
			case 3:{
				cout<<"\nEnter length: ";
				cin>>l;
				cout<<"\nEnter width: ";
				cin>>w;
				v.volume(l,w);
				break;
			}
		}
		cout<<"\nContinue? Y/N";
		cin>>opt;
	}while(opt=='Y' || opt=='y');
}



