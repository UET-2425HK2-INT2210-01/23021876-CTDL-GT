#include <iostream>
#include <queue>  // Thư viện chứa cấu trúc queue của STL
using namespace std;

int main() {
    // Khai báo một hàng đợi kiểu int
    queue<int> q;
    int n, value;

    // Yêu cầu người dùng nhập số lượng phần tử muốn thêm vào hàng đợi
    cout << "Nhap so luong phan tu can push vao queue: ";
    cin >> n;

    // Sử dụng vòng lặp để nhập và đẩy (push) từng phần tử vào hàng đợi
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu thu " << i+1 << ": ";
        cin >> value;
        q.push(value); // Sử dụng push để đẩy giá trị vào hàng đợi
        cout << "Da push " << value << " vao queue." << endl;
    }

    // Hiển thị các phần tử trong hàng đợi theo thứ tự FIFO
    cout << "\nCac phan tu trong queue (theo thu tu FIFO): ";
    while (!q.empty()) {
        // front() trả về phần tử đầu tiên của hàng đợi
        cout << q.front() << " ";
        // pop() loại bỏ phần tử đầu tiên khỏi hàng đợi
        q.pop();
    }
    cout << endl;

    return 0;
}
