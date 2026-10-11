#include<iostream>
#include<cmath>
using namespace std;
int main(){

	
	double A,ci,p,t,r,n;
	cout<<"Enter the principal amount : ";
	cin>>p;
	cout<<"Enter the time : ";
	cin>>t;
	cout<<"Enter the rate : ";
	cin>>r;
	cout<<"Enter n : ";
	cin>>n;
	
	A = p * pow(1 + r /(100 * n), n * t);
	ci = A - p;
	
	cout<<"Compound interest : "<<ci;
	cout<<"\nA : "<<A;
	return 0;
}
