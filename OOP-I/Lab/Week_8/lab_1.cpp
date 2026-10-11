#include <iostream>
using namespace std;

class Student
{
protected:
    int rollNo;
    char name[30];

public:
    void getStudentData()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;
    }

    void displayStudentData()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

class Exam : virtual public Student
{
protected:
    float examMarks;

public:
    void getExamMarks()
    {
        cout << "Enter Exam Marks: ";
        cin >> examMarks;
    }

    void displayExamMarks()
    {
        cout << "Exam Marks: " << examMarks << endl;
    }
};

class Sports : virtual public Student
{
protected:
    float sportsMarks;

public:
    void getSportsMarks()
    {
        cout << "Enter Sports Marks: ";
        cin >> sportsMarks;
    }

    void displaySportsMarks()
    {
        cout << "Sports Marks: " << sportsMarks << endl;
    }
};

class Result : public Exam, public Sports
{
public:
    void displayResult()
    {
        float total;

        total = examMarks + sportsMarks;

        displayStudentData();
        displayExamMarks();
        displaySportsMarks();

        cout << "Total Marks: " << total << endl;
    }
};

int main()
{
    Result r;

    r.getStudentData();
    r.getExamMarks();
    r.getSportsMarks();

    cout << "\n----- STUDENT RESULT -----" << endl;

    r.displayResult();

    return 0;
}