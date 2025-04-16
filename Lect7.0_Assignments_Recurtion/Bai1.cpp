#include<iostream>
using namespace std;
int Tong(int n){ // Hàm tính Tổng từ 1 đến n
    if(n==1) 
    return 1;
    else return  n + Tong(n - 1);// Nếu n khác 1 thì tính theo hàm bằng n + (n-1) + (n-2)+...+0
   }
int main(){
    int n;
    cout << "Nhập n: ";// Nhập vào số nguyên n
    cin >> n;
    int ketqua = Tong(n);
    cout <<  ketqua ;

   return 0;
} 