#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	float mean, sum = 0, variance = 0, std_dev;
	cout<<"Enter the number of data points : ";
	cin>>n;
	
	float x[n];
	
	cout << "Enter the data points: ";
	for(int i =0; i<n; i++){
		cin>>x[i];
		sum += x[i];
	}
	
	mean = sum / n;
	
	for(int i =0; i<n; i++){
		variance += (x[i] - mean)* (x[i] - mean);
	}
	variance = variance / n;
	
	std_dev = sqrt(variance);
	
	cout<<"\nMean : "<<mean;
	cout<<"\nVariance : "<<variance;
	cout<<"\nStardard deviation : "<<std_dev;
	return 0;
}
