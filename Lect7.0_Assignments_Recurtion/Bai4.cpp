#include<iostream>
using namespace std;
int Tinhluythua(int x, int n){ // Hàm tính lũy thừa 
    if(x == 0) return 0;
    else if(n == 0) return 1;
    else return x* Tinhluythua( x, n - 1); // Nếu n,x # 0 thì hàm cho kết quả là x*x*x*...*1
    }
int main(){
    int x,n;
    cout << "Nhap x:";// Nhập vào x
    cin >> x;
    cout << "Nhap n:";// Nhập vào n
    cin >> n;
    int Kq = Tinhluythua(x,n);
    cout << "Ket qua la: " << Kq << endl;
    return 0;
}