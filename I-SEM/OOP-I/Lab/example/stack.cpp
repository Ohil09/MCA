#include<iostream>
using namespace std;
const int MAX = 3;
class Stack{
    protected:
        int st[MAX];
        int top;
    public:
        Stack(){
            top = -1;
        }
        void push(int val){
            st[++top] = val;
        }
        int pop(){
            return st[top--];
        }
};
class Stack2: public Stack{
    public:
        void push(int val){
            if(top >= MAX-1){
                cout<<"\nError:Stack is full!";
                exit(1);
            }
            Stack::push(val);
        }
        int pop(){
            if(top < 0){
                cout<<"\nError:Stack is empty!";
                exit(1);
            }
            return Stack::pop();
        }
};
int main(){
    Stack2 s;
    int v;
    cout<<"Insert an value into stack : ";
    cin>>v;
    s.push(v);
    cout<<"Insert an value into stack : ";
    cin>>v;
    s.push(v);
    cout<<"Insert an value into stack : ";
    cin>>v;
    cout<<"Insert an value into stack : ";
    cin>>v;
    s.push(v);
    cout<<"Popped value from stack : "<<s.pop();
    cout<<"\nPopped value from stack : "<<s.pop();
    cout<<"\nPopped value from stack : "<<s.pop();
    cout<<"\nPopped value from stack : "<<s.pop();
    cout<<"\nPopped value from stack : "<<s.pop();
    return 0;
}