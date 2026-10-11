#include<iostream>
using namespace std;
int inv(int n){
	int rem,rev=0;
	while(n != 0){
		rem = n % 10;
		rev = rev * 10 + rem;
		n = n / 10;
	}
	return rev;
}
int double_inv(int x){
	return x*2;
}
int main(){
	int n;
	cout<<"Enter an integer to calculate it's inverse and double : ";
	cin>>n;
	int rev = inv(n);
	cout<<"Inverse is : "<<rev<<" And double of inverse is : "<<double_inv(rev);
	return 0;
}
