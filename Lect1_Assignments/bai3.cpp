#include<iostream>
#include<numeric>
using namespace std;
int main(){
    int m,n;
    cout << "Nhập số nguyên thứ nhất (m): ";
    cin >> m;
    cout << "Nhập số nguyên thứ hai (n): ";
    cin >> n;
    int ucln = gcd(m, n);
    cout << " Ước chung lớn nhất của " << m << " và " << n << " là: " << ucln << endl;
    return 0;
}    
