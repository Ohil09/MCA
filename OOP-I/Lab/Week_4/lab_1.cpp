#include<iostream>
using namespace std;
class flight{
	private:
		int flight_num;
		char destination[20];
		float distance;
		float fuel;
		
		void calculate_fuel(){
			if(distance <= 1000)
				fuel = 500;
			else if(distance <= 2000)
				fuel = 1100;
			else
				fuel = 2200;
		}
		
	public:
		flight(){
			distance = 500;
			fuel = 0;
		}
		
		void information_entry(){
			cout<<"Enter the flight number : ";
			cin >> flight_num;
			cout<<"Enter the flight Destination : ";
			cin >> destination;
			cout<<"Enter the flight distance : ";
			cin>>distance;
			
			
			calculate_fuel();
		}
		void display_info(){
			cout<<"\n--------Flight Details -----------";
			cout<<"\nFlight number : "<<flight_num;
			cout<<"\nFlight destination : "<<destination;
			cout<<"\nFlight distance : "<<distance;
			cout<<"\nFlight fuel : "<<fuel;
				
		}
};
int main(){
	flight f1;
	
	f1.information_entry();
	f1.display_info();
//	f2.display_info();
	return 0;
}
