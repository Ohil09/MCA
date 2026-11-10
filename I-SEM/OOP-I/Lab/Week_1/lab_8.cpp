#include<iostream>
using namespace std;
int main(){
	string reg_no,name,yoj,grade;
	int sem,m1,m2,m3,m4,m5,avg,tot;
	cout<<"Enter student name : ";
	cin>>name;
	cout<<"Enter student reg no : ";
	cin>>reg_no;
	cout<<"Enter student year of joining : ";
	cin>>yoj;
	cout<<"Enter student semister no : ";
	cin >> sem;
	cout<<"Enter student marks in 5 sub : ";
	cin>>m1>>m2>>m3>>m4>>m5;
	tot = m1 + m2 + m3 + m4 + m5;
	avg = (tot) /5;
	if(avg >= 90)
		grade = "A";
	else if(avg >= 80)
		grade = "B";
	else if(avg >=60)
		grade = "C";
	else if(avg >= 50)
		grade = "D";
	else if(avg >= 40)
		grade = "E";
	else
		grade = "F";
	cout<<"\n\n\t\tScore card for Student : "<<name;
	cout<<"\nRegister no  : "<<reg_no; 
	cout<<"\t\tSemister : "<<sem; 
	cout<<"\tYear : "<<yoj; 
	cout<<"\nGrade Assigned : ";
	cout<<"\nMarks 1  : "<<m1;
	cout<<"\nMarks 2  : "<<m2;
	cout<<"\nMarks 3  : "<<m3;
	cout<<"\nMarks 4  : "<<m4;
	cout<<"\nMarks 5  : "<<m5;
	cout<<"\n\tTotal : "<<tot;
	cout<<"\n\tAverage : "<<avg;
	cout<<"\n\tGrade : "<<grade; 
	return 0;
}
	
