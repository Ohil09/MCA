#include<iostream>
using namespace std;
int main(){
	int a = 12, b = 10, c = 13;
	if(a <= b && a <= c)
		cout <<"A = "<<a <<" is the smallest !";
	else if(b <= c)
		cout <<"B = "<<b <<" is the smallest !";
	else
		cout <<"C = "<<c <<" is the smallest !";
	return 0;
}
