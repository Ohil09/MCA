#include<iostream>
using namespace std;
int main(){
	int ch,t;
	cout<<"1.Binary to decimal \n2.Decimal to Binary \nEnter your choice : ";
	cin>>ch;
	switch(ch){
		case 1:{
			int n,decVal = 0, base = 1;
			cout<<"Enter a number to convert into Decimal  : ";
			cin>>n;
			t = n;
			while(n > 0){
				long lastDigit = n % 10;
				n = n / 10;
				decVal += lastDigit * base;
				base = base * 2;
			}
			cout<<t<<" in Decimal is : "<<decVal;
			break;
		}
		case 2:{
			int n,arr[64];
			int i = 0,r;
			cout<<"Enter a number to convert into Binary  : ";
			cin>>n;
			t = n;
			while(n != 0){
				r = n % 2;
				arr[i++] = r;
				n /= 2;
			}
			cout<<t<<" in Binary is : ";
			for(int j = i - 1; j >= 0; j--){
				cout<<arr[j];
			}
	}
			break;
		default:
			cout<<"Enter a valid choice please !";
	}
	return 0;
}
