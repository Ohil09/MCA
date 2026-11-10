#include<iostream>
using namespace std;
int main(){
	int n;
	int x = 1;
	cout<<"Enter the number of lines : ";
	cin >>n;
	for(int i = n; i >= 1; i --){
		for(int j = 1; j <= i; j++){
			cout<<" * ";
		}
		cout << endl;
	}
	cout<<endl;
	for(int i = n; i >= 1; i --){
		int t = 65;
		for(int j = 1; j <= i; j++){
			cout<<" "<<(char)t;
			t++;
		}
		cout << endl;
	}
	cout<<"Enter the number of lines for floyds triangle : ";
	cin >>n;
	for(int i = 0; i <= n; i ++){
		for(int j = 1; j <= i; j++){
			cout<<" "<<x;
			x++;
		}
		cout << endl;
	}
	return 0;
}
