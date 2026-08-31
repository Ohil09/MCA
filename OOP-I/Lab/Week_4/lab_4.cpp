#include<iostream>
using namespace std;
class Complex{
	private:
		double real;
		double imag;
		
	public:
		Complex(){
			real = 0.0;
			imag = 0.0;
		}
		Complex(double r, double i){
			real = r;
			imag = i;
		}
		Complex add(int s1, const Complex& s2){
			Complex result;
			result.real = s1 + s2.real;
			result.imag = s2.imag;
			return result;
		}
		Complex add(const Complex& s1, const Complex& s2){
			Complex result;
			result.real = s1.real + s2.real;
			result.imag = s1.imag + s2.imag;
			return result;
		}
		void display()const {
			if(imag >= 0){
				cout<<real<<" + "<<imag<<" i"<<endl;
			}else{
				cout<<real<<" - "<<-imag<<" i"<<endl;
			}
		}
};
int main(){
	Complex manager;
	Complex comp1(3.5, 4.5);
	Complex comp2(1.5, 2.5);
	int integer_val = 5;
	
	cout<<"Original Complex 1 : ";
	comp1.display();
	cout<<"Original Complex 2 : ";
	comp2.display();
	cout<<"Integer value to add : "<<integer_val <<"\n\n";
	
	Complex res1 = manager.add(integer_val,comp1);
	cout<<"Result of add(integer,complex 1) : ";
	res1.display();
	
	
	Complex res2 = manager.add(comp1,comp2);
	cout<<"Result of add(complex 1,complex 2) : ";
	res2.display();
	
	return 0;
}
