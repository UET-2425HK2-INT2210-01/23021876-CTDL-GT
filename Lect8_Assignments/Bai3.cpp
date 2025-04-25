#include <iostream>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // Đọc số lượng vật (n) và trọng lượng tối đa cho phép (X)

    int w[100], v[100]; // Mảng lưu trọng lượng (w) và giá trị (v) của từng vật

    // Nhập trọng lượng và giá trị của từng vật
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    // Mảng dp lưu giá trị lớn nhất có thể đạt được tại mỗi mức trọng lượng từ 0 đến X
    int dp[101] = {0}; // Khởi tạo tất cả giá trị ban đầu là 0

    // Duyệt qua từng vật phẩm
    for (int i = 0; i < n; i++) {
        // Duyệt ngược từ X về w[i] để không dùng lại vật phẩm i
        for (int j = X; j >= w[i]; j--) {
            // Cập nhật giá trị lớn nhất nếu chọn vật phẩm i
            if (dp[j] < dp[j - w[i]] + v[i]) {
                dp[j] = dp[j - w[i]] + v[i];
            }
        }
    }

    // Tìm giá trị lớn nhất trong mảng dp (tức là kết quả cuối cùng)
    int result = 0;
    for (int i = 0; i <= X; i++) {
        if (dp[i] > result) {
            result = dp[i];
        }
    }

    // In ra kết quả
    cout << result << endl;

    return 0;
}
