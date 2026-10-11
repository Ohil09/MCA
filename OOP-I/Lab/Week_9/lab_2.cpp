#include<iostream>
using namespace std;

class shape
{
protected:
    double l, b;

public:
    void getData()
    {
        cout << "Enter the Length : ";
        cin >> l;
        cout << "Enter the Breadth : ";
        cin >> b;
    }

    virtual void displayArea()
    {
    }
};

class triangle : public shape
{
public:
    void getData()
    {
        cout << "Enter the Height : ";
        cin >> l;
        cout << "Enter the Base : ";
        cin >> b;
    }

    void displayArea()
    {
        cout << "\nArea of Triangle : " << 0.5 * b * l;
    }
};

class rectangle : public shape
{
public:
    void displayArea()
    {
        cout << "\nArea of Rectangle : " << l * b;
    }
};

int main()
{
    triangle t;
    rectangle r;

    cout << "\n-------- Triangle Area ------------" << endl;
    t.getData();
    t.displayArea();

    cout << "\n-------- Rectangle Area ------------" << endl;
    r.getData();
    r.displayArea();

    return 0;
}
