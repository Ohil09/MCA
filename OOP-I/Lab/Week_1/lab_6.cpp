#include<iostream>
using namespace std;
int main(){
	float f,c;
	int ch;
	cout<<"1.Farenheit to celcius \n2.Celcius to Farenheit\nEnter your choice : ";
	cin>>ch;
	switch(ch){
		case 1:
			cout <<"Enter the temperature in Faranheit : ";
			cin >> f;
			c = (f - 32)* 5 / 9;
			cout <<"Temperature in Celcius is : "<<c;
			break;
		case 2:
			cout <<"Enter the temperature in Celcius : ";
			cin >> c;
			f = (c * 9 / 5) + 32;
			cout <<"Temperature in Farenheit is : "<<f;
			break;
		default: 
			cout<<"Enter a valid choice !";
	}
	return 0;
}
