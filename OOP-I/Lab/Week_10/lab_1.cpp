#include<iostream>
#include<fstream>
#include <cstring>
#include <cctype>
using namespace std;
int main(){
	int ch,i = 0, count = 0;
	char filename[] = "file1.txt";
	char str[100],temp[100];
	fstream fout;
	fout.open(filename, ios::out);
    if (!fout) {
        cout << "Error creating file";
        return 1;
    }
    cout << "Enter a single line of text: ";
    cin.getline(str, 100);
    fout << str;
    fout.close();
    
	fstream file;
	file.open(filename, ios::in);
	if (!file) {
		cout << "Error opening file";
		return 1;
	}
	file.getline(str,100);
	while(1){
		cout<<"\n------------------ Menu ------------------"<<endl;
		cout<<"1.Convert lower case to Upper case "<<endl;
		cout<<"2.Display the content "<<endl;
		cout<<"3.How many times 'a' is present in the file"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Enter  your choice : ";
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"Content of the file After toggle : ";
			    for(int i = 0; str[i] != '\0'; i++){
			    	if (islower((unsigned char)str[i])) {
			            temp[i] = toupper((unsigned char)str[i]);
			        }
			        else if (isupper((unsigned char)str[i])) {
			            temp[i] = tolower((unsigned char)str[i]);
			        }
			        else {
			            temp[i] = str[i];
			        }
			    	cout<<temp[i];
				}
				temp[strlen(str)] = '\0';
				cout<<endl;
				break;
			}
			case 2:
				cout<<"Display the content : ";
			    for(int i = 0; str[i] != '\0'; i++){
			    	cout<<str[i];
				}
				cout<<endl;
				break;
				
			case 3:
				count = 0;
				for(int i = 0; str[i] != '\0'; i++){
					if(str[i] == 'a' || str[i] == 'A'){
						count++;
					}
				}
				cout<<"'a' is present "<<count<<" times in the file"<<endl;
				break;
			case 4:
				cout<<"Exiting ...";
				return 0;
			default:
				cout<<"Enter a valid choice !";
		}
	}
	return 0;
}
