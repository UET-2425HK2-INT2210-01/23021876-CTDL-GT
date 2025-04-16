#include<iostream>
using namespace std;
int Tinhgiaithua(int n){// Hàm tính giai thừa 
    if(n==1)
        return 1;
    else return n * Tinhgiaithua(n - 1); // Nếu n # 1 thì hàm sẽ cho kết quả là n*(n-1)*...*1
    }
int main(){
    int n;
    cout << "Nhap n";//Nhập n
    cin >> n;
    int Ketqua = Tinhgiaithua (n);
    cout << Ketqua;
    return 0;
}