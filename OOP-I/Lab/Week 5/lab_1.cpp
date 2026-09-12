#include<iostream>
using namespace std;
class matrix{
	private:
		int a[10][10];
		int r,c;
	public:
		void read(){
			cout<<"Enter the row size : ";
			cin>>r;
			cout<<"Enter the column size : ";
			cin>>c;
			cout<<"Enter the matrix elements : \n";
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){
					cin>>a[i][j];
				}		
			}
		}
		void display() {
	        for (int i = 0; i < r; i++) {
	            for (int j = 0; j < c; j++) {
	                cout << a[i][j] << "\t";
	            }
	            cout << endl;
	        }
	    }
		friend int operator==(matrix m1, matrix m2);
	    friend matrix operator+(matrix m1, matrix m2);
	    friend matrix operator-(matrix m1, matrix m2);
};
int operator==(matrix m1, matrix m2){
	if(m1.r == m2.r && m1.c == m2.c){
		return 1;
	}
	else{
		return 0;
	}
}
matrix operator-(matrix m1, matrix m2){
	matrix m3;

    m3.r = m1.r;
    m3.c = m1.c;
    
	for(int i=0; i<m1.r; i++){
		for(int j=0; j<m1.c; j++){
				m3.a[i][j]=m1.a[i][j]-m2.a[i][j];	
		}		
	}
	return m3;
}
matrix operator+(matrix m1, matrix m2){
	matrix m3;

    m3.r = m1.r;
    m3.c = m1.c;
    
	for(int i=0; i<m1.r; i++){
		for(int j=0; j<m1.c; j++){
				m3.a[i][j]=m1.a[i][j]+m2.a[i][j];	
		}		
	}
	return m3;
}
int main(){
	matrix m1,m2,m3,m4;
	
	cout<<"Enter the first matrix : \n";
	m1.read();
	
	cout<<"Enter the second matrix : \n";
	m2.read();
	if(m1==m2){
		m3 = m1 + m2;
		m4 = m1 - m2;
		cout << "\nAddition of matrices:\n";
	    m3.display();
	
	    cout << "\nSubtraction of matrices:\n";
	    m4.display();
	}
	else {
	    cout << "\nError: Matrices are not compatible for addition and subtraction.\n";
	}
	return 0;
}
