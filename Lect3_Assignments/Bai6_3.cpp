#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
struct Node {
    int data;
    Node* next;
};
// Lớp stack cài đặt ngăn xếp sử dụng danh sách liên kết
class Stack {
private:
    Node* topNode; // Con trỏ trỏ đến phần tử trên cùng của ngăn xếp

public:
    Stack() {
        topNode = nullptr;
    }
    Hàm kiểm tra ngăn xếp rỗng không
    bool isEmpty() {
        return (topNode == nullptr);
    }
    // Hàm push đẩy giá trị x vò ngăn xếp
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;// gắn giá trị x vào trường dât newNode
        newNode->next = topNode;// Node mới sẽ trỏ đến nút hiện đang là đỉnh của stack
        topNode = newNode;
    }
    // Loại bỏ phần tử ở đỉnh ngăn xếp
    void pop() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng!\n";
            return;
        }
        Node* temp = topNode;//Lưu nút hiện tại ở đỉnh vào biến tạm temp
        topNode = topNode->next;
        delete temp;
    }
    //Hàm trả về giá trị của phần tửu trên cùng của ngăn xếp mà không loại bỏ nó
    int top() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng!\n";
            return -1;
        }
        return topNode->data;// Trả về giá trị của nút ở đỉnh
    }
    //giải phóng toàn bộ bộ nhớ trong ngăn xếp khi các phần tử bị xóa
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s;
    int n, value;
    cout << "Nhập số lượng phần tử cần đẩy vào ngăn xếp: ";
    cin >> n;
    
    cout << "Nhập các phần tử: ";// Nhập các giá trị và đẩy vào ngăn xếp 
    for (int i = 0; i < n; i++) {
        cin >> value;
        s.push(value);
    }
    //Hiển thị phần tử ở đỉnh của ngăn xếp
    cout << "Phần tử trên cùng: " << s.top() << endl;
    s.pop();// Loại bỏ phần tủ trên cùng khỏi ngăn xếp
    cout << "Phần tử trên cùng sau khi pop: " << s.top() << endl;

    return 0;
}
