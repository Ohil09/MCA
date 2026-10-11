#include<iostream>
using namespace std;
class date{
	private:
		int day,month,year;
	public:
		void read(){
			cout<<"Enter the day : ";
			cin>>day;
			cout<<"Enter the month : ";
			cin>>month;
			cout<<"Enter the year : ";
			cin>>year;
		}
		void display(){
			cout<<"Date : "<<day<<"-"<<month<<"-"<<year;
		}
		friend void operator++(date &d);
};
	
void operator++(date &d) {
    if (d.month == 2) {
        if (d.day == 28) {
            d.day = 1;
            d.month++;
        }
        else {
            d.day++;
        }
    }
    else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
        if (d.day == 30) {
            d.day = 1;
            d.month++;
        }
        else {
            d.day++;
        }
    }
    else {
        if (d.day == 31) {
            d.day = 1;

            if (d.month == 12) {
                d.month = 1;
                d.year++;
            }
            else {
                d.month++;
            }
        }
        else {
            d.day++;
        }
    }
}
int main(){
	date d;
	cout<<"-------- Enter the date --------"<<endl;
	d.read();
	cout<<"\nDate before incrementing : ";
	d.display();
	++d;
	cout<<"\n\nDate after incrementing : ";
	d.display();
	return 0;
}
