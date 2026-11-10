#include<iostream>
using namespace std;
inline int cube(int x){
	return x*x*x;
}
int main(){
	int a,res;
	cout<<"Enter a number to calculate the cube : ";
	cin>>a;
	res = cube(a);
	cout<<"Cube of "<<a<<" is : "<<res;
	return 0;
}
