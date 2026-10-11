#include<iostream>
using namespace std;
int main(){
	int h,b,r,area_c, area_t;
	cout<<"Enter the radius of the circle : ";
	cin >>r;
	cout<<"Enter the base and height of triangle :";
	cin >> b >>h;
	area_t = 0.5 * b * h;
	area_c = 3.142 * r * r;
	cout <<"Area of circle is : "<<area_c;
	cout <<"\nArea of triangle is : "<<area_t;
	return 0;
}
