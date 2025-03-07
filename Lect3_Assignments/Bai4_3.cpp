#include <iostream>
using namespace std;

// Định nghĩa một nút của danh sách liên kết
struct Node {
    int data;      // Dữ liệu của nút
    Node* next;    // Con trỏ đến nút tiếp theo
};

// Hàm tạo một nút mới với giá trị x
Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

// Lớp Queue sử dụng danh sách liên kết
class Queue {
private:
    Node* front;  // Con trỏ đầu hàng đợi
    Node* rear;   // Con trỏ cuối hàng đợi
public:
    // Constructor: khởi tạo hàng đợi rỗng
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor: giải phóng bộ nhớ của các nút
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    
    // Kiểm tra hàng đợi có rỗng không
    bool isEmpty() {
        return (front == nullptr);
    }
    
    // Enqueue: thêm phần tử vào cuối hàng đợi
    void enqueue(int x) {
        Node* newNode = createNode(x);
        if (isEmpty()) {   // Nếu hàng đợi rỗng, newNode là cả front và rear
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;  // Nối nút mới vào cuối danh sách
            rear = newNode;        // Cập nhật lại rear
        }
        cout << "Đã enqueue giá trị: " << x << endl;
    }
    
    // Dequeue: loại bỏ phần tử đầu hàng đợi và trả về giá trị
    int dequeue() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng, không thể dequeue." << endl;
            return -1;
        }
        int removed = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {  // Nếu sau dequeue hàng đợi rỗng
            rear = nullptr;
        }
        delete temp;
        cout << "Đã dequeue giá trị: " << removed << endl;
        return removed;
    }
    
    // Peek: xem phần tử đầu hàng đợi mà không loại bỏ
    int peek() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng." << endl;
            return -1;
        }
        return front->data;
    }
    
    // Hiển thị toàn bộ các phần tử trong hàng đợi
    void display() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng." << endl;
            return;
        }
        cout << "Các phần tử trong hàng đợi: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;
    
    // Menu cho phép người dùng thao tác với hàng đợi
    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Enqueue (Thêm phần tử)" << endl;
        cout << "2. Dequeue (Loại bỏ phần tử)" << endl;
        cout << "3. Peek (Xem phần tử đầu)" << endl;
        cout << "4. Hiển thị hàng đợi" << endl;
        cout << "5. Thoát" << endl;
        cout << "Chọn thao tác: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Nhập giá trị cần thêm: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Phần tử đầu hàng đợi: " << q.peek() << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Thoát chương trình." << endl;
                return 0;
            default:
                cout << "Lựa chọn không hợp lệ." << endl;
                break;
        }
    }
    
    return 0;
}
