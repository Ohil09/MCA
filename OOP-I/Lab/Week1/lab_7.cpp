#include<iostream>
#include<cmath>
using namespace std;
int main(){
	//temp for power
	double a,b,x,res;
	
	double A,ci,p,t,r,n;
	cout<<"Enter the principal amount : ";
	cin>>p;
	cout<<"Enter the time : ";
	cin>>t;
	cout<<"Enter the rate : ";
	cin>>r;
	cout<<"Enter n : ";
	cin>>n;
	
	//Compound interest
	x = (1 + r /100);
	res = std::pow(x,t);
	ci = p * res;
	
	//Calculation for : A = P (1 + r/n )nt  
	a = (1 + r / n);
	b = n * t;
	res = std::pow(a,b);
	A = p * res;
	
	cout<<"Compound interest : "<<ci;
	cout<<"\nA : "<<A;
	return 0;
}
