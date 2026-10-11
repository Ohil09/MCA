#include<iostream>
using namespace std;
bool is_palindrome(char x[],int n){
	int start = 0;
	int end = n - 1;
	while(start < end){
		if(x[start] != x[end]){
			return false;
		}
		start++;
		end--;
	}
	return true;
}
int main(){
	int n;
	bool test;
	cout<<"Enter the size of the string : ";
	cin>>n;
	char s[n];
	cout<<"Enter the string characters : ";
	for(int i = 0; i < n; i++){
		cin>>s[i];
	}
	test = is_palindrome(s,n);
	if(test){
		cout<<"The string is a palindrome !";
	}else{
		cout<<"The string is not a palindrome !";
	}
	return 0;
}
