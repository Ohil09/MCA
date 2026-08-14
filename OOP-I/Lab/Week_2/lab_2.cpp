#include<iostream>
using namespace std;
int main(){
	int n;
	bool is_cube = false;
	cout<<"Enter a number to check if its perfect cube : ";
	cin>>n;
	for(int i = 1; i <= n; i++){
		if(i * i * i == n){
			is_cube =  true;
		}
	}
	if(is_cube){
		cout<<n<<" is a perfect cube!";
	}else{
		cout<<n<<" is not a perfect cube!";
	}
	return 0;
}
