#include<iostream>
using namespace std;

class employee
{
    int emp_Code;
    char emp_Name[20];

public:
    void read()
    {
        cout << "Enter Employee code : ";
        cin >> emp_Code;

        cin.ignore();

        cout << "Enter Employee name : ";
        cin.getline(emp_Name, 20);
    }

    void display()
    {
        cout << "Employee Code : " << emp_Code << endl;
        cout << "Employee Name : " << emp_Name << endl;
    }
};

class faculty : public employee
{
    char qualification[20];
    int years_Of_Experience;

public:
    void read()
    {
        employee::read();

        cout << "Enter Qualification : ";
        cin.getline(qualification, 20);

        cout << "Enter Years of Experience : ";
        cin >> years_Of_Experience;
    }

    void display()
    {
        employee::display();

        cout << "Qualification : " << qualification << endl;
        cout << "Years Of Experience : "
             << years_Of_Experience << endl;
    }
};

class non_teaching : public employee
{
    char grade;

public:
    void read()
    {
        employee::read();

        cout << "Enter Grade : ";
        cin >> grade;
    }

    void display()
    {
        employee::display();

        cout << "Grade : " << grade << endl;
    }
};

class permanent : public faculty
{
    float basic_Pay;
    float academic_Allowance;

public:
    void read()
    {
        faculty::read();

        cout << "Enter Basic Pay : ";
        cin >> basic_Pay;

        cout << "Enter Academic Allowance : ";
        cin >> academic_Allowance;
    }

    void display()
    {
        faculty::display();

        cout << "Basic Pay : " << basic_Pay << endl;
        cout << "Academic Allowance : "
             << academic_Allowance << endl;
    }
};

class contract : public faculty
{
    int probation_Years;

public:
    void read()
    {
        faculty::read();

        cout << "Enter Probation Years : ";
        cin >> probation_Years;
    }

    void display()
    {
        faculty::display();

        cout << "Probation Years : "
             << probation_Years << endl;
    }
};

int main()
{
    int np, nc, nnt;
    int ch;

    cout << "Enter number of Permanent employees: ";
    cin >> np;

    cout << "Enter number of Contract employees: ";
    cin >> nc;

    cout << "Enter number of Non-teaching employees: ";
    cin >> nnt;

    permanent *p = new permanent[np];
    contract *c = new contract[nc];
    non_teaching *nt = new non_teaching[nnt];

    do
    {
        cout << "\n------------------------------------------------------------\n";
        cout << "-------------------- EMPLOYEE DATABASE --------------------\n";
        cout << "1. Enter Permanent Employee\n";
        cout << "2. Enter Contract Employee\n";
        cout << "3. Enter Non-teaching Employee\n";
        cout << "4. Display Permanent Employees\n";
        cout << "5. Display Contract Employees\n";
        cout << "6. Display Non-teaching Employees\n";
        cout << "7. Exit\n";
        cout << "------------------------------------------------------------\n";

        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                for(int i = 0; i < np; i++)
                {
                    cout << "\nEnter Permanent Employee "
                         << i + 1 << ":\n";
                    p[i].read();
                }
                break;

            case 2:
                for(int i = 0; i < nc; i++)
                {
                    cout << "\nEnter Contract Employee "
                         << i + 1 << ":\n";
                    c[i].read();
                }
                break;

            case 3:
                for(int i = 0; i < nnt; i++)
                {
                    cout << "\nEnter Non-teaching Employee "
                         << i + 1 << ":\n";
                    nt[i].read();
                }
                break;

            case 4:
                cout << "\n---------- Permanent Employees ----------\n";

                for(int i = 0; i < np; i++)
                {
                    cout << "\nEmployee " << i + 1 << ":\n";
                    p[i].display();
                }
                break;

            case 5:
                cout << "\n---------- Contract Employees ----------\n";

                for(int i = 0; i < nc; i++)
                {
                    cout << "\nEmployee " << i + 1 << ":\n";
                    c[i].display();
                }
                break;

            case 6:
                cout << "\n---------- Non-teaching Employees ----------\n";

                for(int i = 0; i < nnt; i++)
                {
                    cout << "\nEmployee " << i + 1 << ":\n";
                    nt[i].display();
                }
                break;

            case 7:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while(ch != 7);

    delete[] p;
    delete[] c;
    delete[] nt;

    return 0;
}