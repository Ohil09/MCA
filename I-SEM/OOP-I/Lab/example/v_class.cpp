#include<iostream>
using namespace std;
class Base{
    public:
        virtual void show(){ //If virtual keyword is used it calls the derived class Mb_fnc , if not base class mb_fnc is called
            cout<<"Base class!";
        }
};
class derived : public Base{
    public:
        virtual void show(){
            cout<<"Derived class!";
        }
};
int main(){
    Base* b_ptr;
    derived d;
    b_ptr = &d;
    b_ptr -> show();
    return 0;
}