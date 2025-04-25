#include <iostream>
using namespace std;

bool subsetSum(int a[], int n, int x, int index = 0, int currentSum = 0) {
    // Nếu tổng hiện tại bằng x => đã tìm được tập con
    if (currentSum == x) return true;

    // Nếu vượt quá x hoặc hết phần tử thì không hợp lệ
    if (index == n || currentSum > x) return false;

    // Gọi đệ quy 2 nhánh:
    // - Chọn phần tử a[index]
    // - Không chọn a[index]
    return subsetSum(a, n, x, index + 1, currentSum + a[index]) ||
           subsetSum(a, n, x, index + 1, currentSum);
}

int main() {
    int n, x;
    cin >> n >> x; // Nhập số lượng phần tử và giá trị tổng cần tìm

    int a[100]; // Mảng lưu độ tuổi
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Nhập các phần tử
    }

    // Gọi hàm kiểm tra
    if (subsetSum(a, n, x)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
