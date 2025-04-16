#include<iostream>
using namespace std;

void Innguoc(int n) {
    if (n == 0)
        return;
    else 
    {
        cout << n % 10; // Nếu n # 0 thì lấy n chia lấy phần nguyên và in ra luôn kết quả.
        Innguoc(n/10); // Hàm chạy tiếp với n = n/10
    }
}

int main() {
    int n ;
    cout << "Nhap n: "; // Nhập vào n
    cin >> n;
    cout << " Kq: ";  
    Innguoc(n);
    return 0;
}

