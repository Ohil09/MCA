#include<iostream>
using namespace std;
void swap_val(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

void swap_val(float &x,float &y){
	float temp = x;
	x = y;
	y = temp;
}

void swap_val(char &m,char &n){
	char temp = m;
	m = n;
	n = temp;
}

int main(){
	int a,b;
	float x,y;
	char m,n;
	cout<<"Enter the 2 numbers to swap : ";
	cin>>a>>b;
	swap_val(a,b);
	cout<<"The 2 number after swapping, a = "<<a<<" b = "<<b;
	
	cout<<"\nEnter the 2 floating point numbers to swap : ";
	cin>>x>>y;
	swap_val(x,y);
	cout<<"The 2 floating point number after swapping, x = "<<x<<" y = "<<y;
	
	cout<<"\nEnter the 2 characters to swap : ";
	cin>>m>>n;
	swap_val(m,n);
	
	cout<<"The 2 characters after swapping, m = "<<m<<" n = "<<n;
	return 0;
}
