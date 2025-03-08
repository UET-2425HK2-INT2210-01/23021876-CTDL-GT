#include <iostream>
using namespace std;

#define MAX_SIZE 100 // Kích thước tối đa của ngăn xếp

class Stack {
private:
    int arr[MAX_SIZE]; // Mảng lưu trữ phần tử ngăn xếp
    int topIdx; // Chỉ số của phần tử trên cùng

public:
    Stack() {
        topIdx = -1;// Khởi tạo ngăn xếp rỗng
    }
    // Hmà kiểm tra ngăn xếp rỗng
    bool isEmpty() {
        return (topIdx == -1);
    }
    Hàm kiểm tra ngăn xếp đầy
    bool isFull() {
        return (topIdx == MAX_SIZE - 1);
    }
    //Hàm push đẩy phần tử x lên ngăn xếp
    void push(int x) {
        if (isFull()) {
            cout << "Ngăn xếp đầy!\n";
            return;
        }
        arr[++topIdx] = x;//Tăng chỉ số của topIdx sau đó gắn giá trị mới vào vị trí mới
    }
    // Loại bỏ phần tử đỉnh khỏi ngăn xếp
    void pop() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng!\n";
            return;
        }
        topIdx--;//giảm topIdx để loại bỏ phần tửu hiện tại 
    }

    int top() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng!\n";
            return -1;// giá trị lỗi vì ngăn xếp rỗng
        }
        return arr[topIdx];
    }
};

int main() {
    Stack s;
    int n, value;
    cout << "Nhập số lượng phần tử cần đẩy vào ngăn xếp: ";
    cin >> n;
    
    cout << "Nhập các phần tử: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        s.push(value);
    }
        //Hiển thị phần tử trên cùng của ngăn xếp
    cout << "Phần tử trên cùng: " << s.top() << endl;
    s.pop();// Loại bỏ phần tử trên cùng và hiển thị lại phần tử mới ở đỉnh ngăn xếp
    cout << "Phần tử trên cùng sau khi pop: " << s.top() << endl;

    return 0;
}
