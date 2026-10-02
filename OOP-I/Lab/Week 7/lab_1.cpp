#include <iostream>
using namespace std;

class person
{
private:
	int id;
	char name[20];

public:
	void accept()
	{
		cout << "\nEnter ID : ";
		cin >> id;

		cout << "Enter Name : ";
		cin.ignore();
		cin.getline(name, 20);
	}

	void display()
	{
		cout << "\nID   : " << id << endl;
		cout << "Name : " << name << endl;
	}
};

class teaching : public person
{
private:
	char subject[20];

public:
	void accept()
	{
		person::accept();

		cout << "Enter Subject : ";
		cin.getline(subject, 20);
	}

	void display()
	{
		person::display();

		cout << "Subject : " << subject << endl;
	}
};

class nonTeaching : public person
{
private:
	char dept[20];

public:
	void accept()
	{
		person::accept();

		cout << "Enter Department : ";
		cin.getline(dept, 20);
	}

	void display()
	{
		person::display();

		cout << "Department : " << dept << endl;
	}
};

class instructor : public person
{
public:
	void accept()
	{
		person::accept();
	}

	void display()
	{
		person::display();
	}
};

int main()
{
	int n, ch;

	cout << "Enter the number of instructors: ";
	cin >> n;

	instructor *in = new instructor[n];

	do
	{
		cout << "\n---------------------------\n";
		cout << "1. Enter instructor\n";
		cout << "2. Display instructor\n";
		cout << "3. Exit\n";
		cout << "---------------------------\n";

		cout << "Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				cout << "\nEnter Instructor " << i + 1 << ":\n";
				in[i].accept();
			}
			break;

		case 2:
			for (int i = 0; i < n; i++)
			{
				cout << "\nInstructor " << i + 1 << ":\n";
				in[i].display();
			}
			break;

		case 3:
			cout << "\nExiting...";
			break;

		default:
			cout << "\nInvalid choice!";
		}

	} while (ch != 3);

	delete[] in;

	return 0;
}