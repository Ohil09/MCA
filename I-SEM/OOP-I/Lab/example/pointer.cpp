#include<iostream>
using namespace std;

int sum(){
    int sum = 0;
    int A[5] = {10,20,30,40,50};
    int *p = A;
    for(int i = 0; i < 5; i++ ){
        sum += *p++;
    }
    return sum;
}
void c_arr(char a[]){
    char *ptr;
    ptr = a;
    for(int i = 0; *ptr != '\0'; i++){
        // *ptr = '#';
        cout<<*ptr++;
    }
}
void calc_length(char a[]){
    char *ptr = a;
    while(*ptr != '\0'){
        ptr++;
    }
    cout<<"Length = "<<ptr - a;
}
int my_strcmp(char* s1, char* s2){
    while((*s1 == *s2) && (*s1 != '\0' || *s2 != '\0')){
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
void my_strcpy(char* d, char*s){
    while(*s != '\0'){
        *d++ = *s++;
    }
    *d = '\0';
}
int main(){
    int A[5] = {10,20,30,40,50};
    char s[10] = "Hello";
    char a[10] = "Hello";
    char t[10];
    int *ptr;
    ptr = A;
    // *(A + 3) = 22;
   for(int i = 0; i < 5; i++){
    //     if(i % 2 == 0){
            // cout<<"Array value at position "<<i+1<<" is : "<<*ptr<<endl;
            //OR
            cout<<"Array values at position "<<i+1<<" is : "<<*(A + i)<<endl;
                                                            //*(ptr++)
        // }
        ptr++;
    }
    // cout<<"Array value at position "<< A + (3 * 4)<<endl;
    cout<<"Sum of array element is : "<<sum();
    cout<<"\nCharacters of array are : ";
    c_arr(s);
    cout<<"\n Length calculation : ";
    calc_length(s);

    cout<<"\nCheck if 2 strings are equal : ";
    if(my_strcmp(s,a) == 0){
        cout<<"\nStrings are equal !";
    }else{
        cout<<"\nStrings are not equal !";
    }


    cout<<"\nString copy : ";
    my_strcpy(t,s);
    char *t_ptr;
    t_ptr = t;
    while(*t_ptr != '\0'){
        cout<<*t_ptr++;
    }

    return 0;

    
}