#include<iostream>
using namespace std;

int Tongsonguyen(int n){ // Hàm tính tổng các số nguyên trong 1 số
    if (n <= 0) return 0;
    else return n%10 + Tongsonguyen(n/10); // Nếu n > 0 thì thực hiện phép chia lấy phần nguyên và 
                                        //lấy phần nguyên cộng với hàm Tongsonguyen của phép chia lấy phần dư 
}

int main(){
    int n;
    cout << "Nhap n:";// Nhập vào n
    cin >> n;
    cout << Tongsonguyen(n);
    return 0;
}