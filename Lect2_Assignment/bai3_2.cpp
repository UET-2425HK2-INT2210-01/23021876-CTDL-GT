#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int pos, int val) {
        Node* newNode = new Node(val);
        if (pos == 0) { 
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (temp) { 
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void remove(int pos) {
        if (!head) return;

        if (pos == 0) { 
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next; i++) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
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

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        } else if (op == "delete") {
            int p;
            cin >> p;
            list.remove(p);
        }
    }

    list.print();
    return 0;
}
