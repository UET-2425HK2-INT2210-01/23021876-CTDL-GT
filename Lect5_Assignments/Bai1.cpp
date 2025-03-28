
#include <iostream>  
using namespace std; 

struct Node { // Định nghĩa một node trong cây
    int data;          // Giá trị của node
    Node* firstChild;  // Con đầu tiên
    Node* nextSibling; // Anh em kế tiếp

    Node(int val) {   // Constructor khởi tạo node mới
        data = val;   // Gán giá trị
        firstChild = nullptr; // Chưa có con
        nextSibling = nullptr; // Chưa có anh em
    }
};

class Tree { // Định nghĩa lớp cây
private:
    int N;               // Số lượng node
    Node* root;          // Con trỏ đến node gốc
    Node** nodeList;     // Mảng con trỏ lưu node
    bool* isChild;       // Mảng đánh dấu node nào là con

public:
    Tree(int n) { // Constructor khởi tạo cây
        N = n; // Gán số node
        nodeList = new Node*[N + 1](); // Cấp phát động mảng nodeList
        isChild = new bool[N + 1](); // Cấp phát động mảng isChild
        root = nullptr; // Ban đầu chưa có gốc
    }

    void AddChild(int u, int v) { // Hàm thêm cạnh (u là cha của v)
        if (nodeList[u] == nullptr) // Nếu node u chưa có trong danh sách
            nodeList[u] = new Node(u); // Tạo node mới

        if (nodeList[v] == nullptr) // Nếu node v chưa có
            nodeList[v] = new Node(v); // Tạo node mới

        Node* parent = nodeList[u]; // Lấy con trỏ đến node cha
        Node* child = nodeList[v];  // Lấy con trỏ đến node con

        if (parent->firstChild == nullptr) { // Nếu cha chưa có con
            parent->firstChild = child; // Gán con đầu tiên
        } else {  
            Node* temp = parent->firstChild; // Biến duyệt danh sách anh em
            while (temp->nextSibling != nullptr) {  // Tìm node anh em cuối cùng
                temp = temp->nextSibling; // Chuyển sang anh em tiếp theo
            }
            temp->nextSibling = child; // Gán node con vào danh sách anh em
        }

        isChild[v] = true;  // Đánh dấu node v là con
    }

    void updateRoot() { // Hàm tìm gốc của cây
        for (int i = 1; i <= N; i++) {  // Duyệt từ 1 đến N
            if (nodeList[i] != nullptr && !isChild[i]) { // Nếu node không là con của ai
                root = nodeList[i];  // Gán root
                break; // Thoát vòng lặp
            }
        }
    }

    int getHeight(Node* node) { // Hàm tính chiều cao của cây
        if (node == nullptr) // Nếu cây rỗng
            return -1; // Trả về -1

        int maxChildHeight = -1;  // Biến lưu chiều cao lớn nhất của các con
        Node* temp = node->firstChild; // Lấy con đầu tiên
        while (temp != nullptr) {  // Duyệt tất cả các con
            maxChildHeight = max(maxChildHeight, getHeight(temp)); // Tìm max chiều cao con
            temp = temp->nextSibling;  // Chuyển sang anh em tiếp theo
        }

        return maxChildHeight + 1;  // Chiều cao = max chiều cao con + 1
    }

    void preorder(Node* node) { // Duyệt Preorder (NLR)
        if (node == nullptr) // Nếu node rỗng
            return;
        cout << node->data << " ";  // In node hiện tại
        Node* temp = node->firstChild; // Lấy con đầu tiên
        while (temp != nullptr) { // Duyệt tất cả các con
            preorder(temp); // Gọi đệ quy
            temp = temp->nextSibling; // Chuyển sang anh em tiếp theo
        }
    }

    void postorder(Node* node) { // Duyệt Postorder (LRN)
        if (node == nullptr) // Nếu node rỗng
            return;
        Node* temp = node->firstChild; // Lấy con đầu tiên
        while (temp != nullptr) { // Duyệt tất cả các con
            postorder(temp); // Gọi đệ quy
            temp = temp->nextSibling; // Chuyển sang anh em tiếp theo
        }
        cout << node->data << " ";  // In node hiện tại
    }

    void inorder(Node* node) { // Duyệt Inorder (LNR) chỉ áp dụng cho cây nhị phân
        if (node == nullptr) // Nếu node rỗng
            return;

        Node* leftChild = node->firstChild;  
        Node* rightChild = (leftChild != nullptr) ? leftChild->nextSibling : nullptr;

        inorder(leftChild);  // Duyệt con trái
        cout << node->data << " ";  // In node cha
        inorder(rightChild);  // Duyệt con phải
    }

    void solve() { // Hàm giải bài toán
        updateRoot();  // Tìm root của cây
        cout << getHeight(root) << endl;  // In chiều cao của cây

        preorder(root); // Gọi hàm duyệt Preorder
        cout << endl; // Xuống dòng

        postorder(root); // Gọi hàm duyệt Postorder
        cout << endl; // Xuống dòng

        inorder(root); // Gọi hàm duyệt Inorder
        cout << endl; // Xuống dòng
    }
};

int main() { // Hàm chính
    int N, M; // Khai báo số node và số cạnh
    cin >> N >> M;  // Nhập số node và số cạnh

    Tree tree(N);  // Tạo cây với N node

    for (int i = 0; i < M; i++) {  // Vòng lặp nhập M cạnh
        int u, v; // Biến lưu cạnh (u, v)
        cin >> u >> v; // Nhập cạnh
        tree.AddChild(u, v);  // Thêm cạnh vào cây
    }

    tree.solve();  // Gọi hàm xử lý bài toán

    return 0; 
}
