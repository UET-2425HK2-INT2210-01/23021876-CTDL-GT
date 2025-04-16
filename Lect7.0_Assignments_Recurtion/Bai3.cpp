#include<iostream>
using namespace std;
int Fibonacci( int n){ // Hàm tính fibonacci
    if(n==0) return 0; 
    else if(n==1) return 1;
    else return Fibonacci(n - 1) + Fibonacci(n - 2); // Nếu n#0,1 thì hàm sẽ cho kết quả là (n-1)+(n-2) 
}
int main(){
    int n;
    cout << "Nhap n";// Nhập vào n
    cin >> n;
    int Ketqua = Fibonacci(n);
    cout << Ketqua;
    return 0;
}