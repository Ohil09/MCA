#include<iostream>
using namespace std;
class Complex{
	private:
		float real,imag;
	public:
		void read_complex(){
			cin>>real;
			cin>>imag;
		}
		Complex operator +(Complex c){
			Complex temp;
			temp.real = real + c.real;
			temp.imag = imag + c.imag;
			return temp;
		}
		Complex operator -(Complex c){
			Complex temp;
			temp.real = real - c.real;
			temp.imag = imag - c.imag;
			return temp;
		}
		void display_complex(){
			if(imag>0)
				cout<<real<<" + "<<imag<<"i"<<endl;
			else
				cout<<real<<" - "<<-imag<<"i"<<endl;
		}
};
int main(){
	Complex c1,c2,diff,sum;
	cout<<"Enter the first Complex number : ";
	c1.read_complex();
	cout<<"Enter the second Complex number : ";
	c2.read_complex();
	sum = c1 + c2;
	diff = c1 - c2;
	cout<<"Two Complex numbers are : "<<endl;;
	c1.display_complex();
	c2.display_complex();
	cout<<"The sum of two Complex number are : ";
	sum.display_complex();
	cout<<"The diff of two Complex number are : ";
	diff.display_complex();
	return 0;
}
