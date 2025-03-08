#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() : head(nullptr) {}
    
    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        
        Node* temp = head;
        for (int i = 0; i < p - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }
        
        if (temp == nullptr) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void remove(int p) {
        if (head == nullptr) return;
        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node* temp = head;
        for (int i = 0; i < p - 1 && temp->next != nullptr; ++i) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) return;
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
    
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    
    for (int i = 0; i < n; ++i) {
        string command;
        int p, x;
        cin >> command >> p;
        if (command == "insert") {
            cin >> x;
            list.insert(p, x);
        } else if (command == "delete") {
            list.remove(p);
        }
    }
    
    list.print();
    return 0;
}

