#include<iostream>
#include<string>
using namespace std;
int main(){
    string s("HELLO");
    string s1("hello");
    // if(s1.compare(s) > 0){
    //     cout<<"Greater";
    // }
    // else{
    //     cout<<"lesser";
    // }
    cout<<s<<endl;
    s.erase(0);
    s.replace(0,5,s1);
    cout<<s<<endl;
    s.insert(5,"How are you!");
    cout<<s;
    return 0;
}