#include<iostream>
using namespace std;
int main(){
	int a=5,b=3,temp;
	cout<< "A and B before swapping : A = "<<a<<" B = "<<b;
	temp = a;
	a = b;
	b = temp;
	cout<< "\nA and B after swapping : A = "<<a<<" B = "<<b;
	return 0;
}
