#include<iostream>
using namespace std;
int main(){
	int dist,cm,inch,feet;
	cout <<"Enter the distance in mm : ";
	cin >> dist;
	cm = dist / 10;
	inch = cm / 2.5;
	feet = inch / 12;

	cout <<"Distance in cm = "<<cm<<"\n"<<feet<<" feet and "<<(int)inch % 12<<" inches";
	return 0;
}
