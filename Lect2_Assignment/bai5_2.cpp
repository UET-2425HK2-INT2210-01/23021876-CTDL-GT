#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    int data;
    Node * next;
};

class stack {
    public:    
    Node * head;
    int size = 0;
        stack() : head(NULL) {}

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
            if (size != 0)
            {
                Node* loop = head;
                while(loop->next->next != NULL) loop = loop->next;

                Node* trash = loop->next;
                delete trash;
                loop->next = NULL;
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
    stack st;
    int n; cin >> n;
    while(n--)
    {
        string s; cin >> s;
        if (s.compare("push") == 0)
        {
            int x; cin >> x;
            st.push(x);
        }
        else if (s.compare("pop") == 0)
        {
            st.pop();
        }
    }
    st.print();
}