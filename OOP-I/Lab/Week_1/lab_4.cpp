#include<iostream>
using namespace std;
int main(){
	int s,min,h,sec;
	cout<<"Enter the time in seconds : ";
	cin >> s;
	h = s / 3600;
	min = (s % 3600) / 60;
	sec = s % 60;
	cout << "Time is "<<h<<" hour "<<min<<" minutes and "<<sec<<" seconds";
	return 0;
}
