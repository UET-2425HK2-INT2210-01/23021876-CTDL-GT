#include <iostream>  
#include <string>    

using namespace std;


struct Node {
    int value;      
    int priority;  
    Node* next;     
    Node* prev;     
    Node(int v, int p) : value(v), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;  
    Node* tail;  
public:
    PriorityQueue() : head(nullptr), tail(nullptr) {}

    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);

        if (!head) {
            head = tail = newNode;
            return;
        }

        if (priority > head->priority) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->priority >= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;

        if (!newNode->next) {
            tail = newNode;
        } else {
            newNode->next->prev = newNode;
        }
    }

    void dequeue() {
        if (!head) {
            return;
        }

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;  
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->value << "," << temp->priority << ")";
            if (temp->next) {
                cout << " ";
            }
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    PriorityQueue pq; 

    while (n--) {
        string cmd;
        cin >> cmd;

        if (cmd == "enqueue") {
            int v, p;
            cin >> v >> p;
            pq.enqueue(v, p);
            pq.display();  
        } else if (cmd == "dequeue") {
            pq.dequeue();
            pq.display();  
        } else {
        }
    }

    return 0;
}
