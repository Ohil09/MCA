#include<iostream>
using namespace std;
int main(){
	int i,n,f1 = 0, f2 = 1, nxt = 0;
	cout<<"Enter the number of terms for Fibonnacci number : ";
	cin>>n;
	for(i = 1; i <= n; i++)
	{
		if(i == 1){
			cout<<f1<<" ";
			continue;
		}
		if(i == 2){
			cout<<f2<<" ";
			continue;
		}
		nxt = f1 + f2;
		f1 = f2;
		f2 = nxt;
		cout<<nxt<<" ";
	}
	return 0;
}
