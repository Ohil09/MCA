#include<iostream>
using namespace std;
int main(){
	int n1,n2,i,j;
	cout<<"Enter the starting range : ";
	cin>>n1;
	cout<<"Enter the ending range : ";
	cin>>n2;
	cout<<"Prime numbers between the range are : ";
	for(i = n1; i <= n2; i++){
		int count = 0;
		for(j = 1; j <= i; j++){
			if(i % j == 0){
				count ++;
			}
		}
		if(count == 2){
			cout<<i<<" ";
		}
	}
	
	return 0;
}
