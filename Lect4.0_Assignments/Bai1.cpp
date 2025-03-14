#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;       
    Node* next;    
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* head; 

public:
    LinkedList() : head(nullptr) {}

    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void search(int x) {
        Node* temp = head;
        int pos = 1; 
        while (temp) {
            if (temp->data == x) {
                cout << pos << "\n";
                return; 
            }
            temp = temp->next;
            pos++;
        }
        cout << "NO\n";
    }

    void reverseList() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nxt = curr->next; 
            curr->next = prev;      
            prev = curr;            
            curr = nxt;           
        }
        head = prev; 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList myList;
    int n;
    cin >> n; 

    while (n--) {
        string cmd;
        cin >> cmd;  
        if (cmd == "append") {
            int x;
            cin >> x;
            myList.append(x);
        } else if (cmd == "search") {
            int x;
            cin >> x;
            myList.search(x);
        } else if (cmd == "reverse") {
            myList.reverseList();
        }
    }

    return 0;
}