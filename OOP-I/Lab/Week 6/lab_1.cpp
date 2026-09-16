#include<iostream>
using namespace std;
class my_string{
	private:
		char str[20];
	public:
		void read(){
			cin.get(str,20);
		}
		bool operator <=(my_string s){
			int i = 0;
			while(str[i] != '\0' && s.str[i] != '\0'){
				if(str[i] < s.str[i]){
					return true;
				}
				if(str[i] > s.str[i]){
					return false;
				}
				i++;
			}
			if(str[i] == '\0' && s.str[i] == '\0')
                return true;
                
            if(str[i] == '\0')
            	return true;
            	
            return false;
		}
};
int main(){
	my_string s1,s2;
	cout<<"Enter the first string : ";
	s1.read();
	cin.ignore();
	cout<<"Enter the second string : ";
	s2.read();
	if(s1 <= s2){
		cout<<"The first string is less than or equal to second !";
	}else{
		cout<<"The second string is less than first";
	}
	return 0;
}
