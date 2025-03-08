#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    int data;
    Node * next;
};

class queue {
    public:    
    Node * head;
    int size = 0;

        queue() : head(NULL) {}

        void push(int x)
        {
            Node * newNode = new Node;
            newNode->data = x;
            if(head == NULL)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                Node* loop = head;
                while(loop->next != NULL)
                {
                    loop = loop->next;
                }
                loop->next = newNode;
                newNode->next = NULL;
            }
            size++;
        }

        void pop()
        {
            if (head != NULL)
            {
                Node* trash = head;
                head = head->next;
                delete trash;
                size--;
            }
        }

        void print()
        {
            Node * loop = head;
            while(loop != NULL)
            {
                cout << loop->data << " ";
                loop = loop->next;
            }
        }
};

int main()
{
    queue q;
    int n; cin >> n;
    while(n--)
    {
        string s; cin >> s;
        if (s.compare("enqueue") == 0)
        {
            int x; cin >> x;
            q.push(x);
        }
        else if (s.compare("dequeue") == 0)
        {
            q.pop();
        }
    }
    q.print();
}