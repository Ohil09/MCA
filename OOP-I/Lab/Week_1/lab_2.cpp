#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cout<< "Enter A =  ";
	cin>>a;
	cout <<"Enter B = ";
	cin>>b;
	cout <<"Enter C = ";
	cin>>c;
	if(a <= b && a <= c)
		cout <<"A = "<<a <<" is the smallest !";
	else if(b <= c)
		cout <<"B = "<<b <<" is the smallest !";
	else
		cout <<"C = "<<c <<" is the smallest !";
	return 0;
}
