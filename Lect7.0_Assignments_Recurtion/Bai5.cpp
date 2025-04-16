#include<iostream>
using namespace std;

int Demsonguyen(int n){ // Hàm đếm có bao nhiêu số nguyên trong 1 số
    if (n <= 0) return 0;
    else return 1 + Demsonguyen(n/10);// Nếu n>0 thì hàm cho kết quả là 1 + 1 + ....+0
}

int main(){
    int n;
    cout << "Nhap n:";// Nhập vào n
    cin >> n;
    cout << Demsonguyen(n);
    return 0;
}