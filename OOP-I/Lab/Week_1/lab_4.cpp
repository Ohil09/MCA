#include<iostream>
using namespace std;
int main(){
	int s,m,min,h,sec;
	cout<<"Enter the time in seconds : ";
	cin >> s;
	m = s / 60;
	h = s / 3600;
	min = m % 60;
	sec = s % 60;
	cout << "Time is "<<h<<" hour "<<min<<" minutes and "<<sec<<" seconds";
	return 0;
}
