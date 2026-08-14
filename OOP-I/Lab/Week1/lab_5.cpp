#include<iostream>
using namespace std;
int main(){
	int dist,cm,inch,feet;
	cout <<"Enter the distance in mm : ";
	cin >> dist;
	cm = dist / 10;
	inch = cm / 2.5;
	feet = inch / 12;
	if(inch >= 12){
		inch = inch % 12;
	}
	cout <<"Distance in cm = "<<cm<<" in feet = "<<feet<<" in inches = "<<inch;
	return 0;
}
