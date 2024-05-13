#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Node {
    public:
        int data;
        Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    private:
        Node* head;
        Node* tail;
        int sz;
    
    public:
        Queue() {
            head = NULL;
            tail = nullptr;
            sz = 0;
        }
    
    // Insert at last
    void push(int val) {
        Node* new_node = new Node(val);
        if(head == NULL) {
            head = new_node;
            tail = new_node;
            sz++;
            return;
        }
        tail->next = new_node;
        tail = new_node;
        sz++;
        return;
    }

    // Accessing first element
    int front() {
        return head->data;
    }

    // Removing from the front
    void pop() {
        if(sz == 0) {
            throw std:: invalid_argument("Index is not valid");
        }
        Node* temp = head;
        head = head->next;
        free(temp);
        sz--;
        return;
    }

    // Returns size of queue
    int size() {
        return sz;
    }

    // Is it empty?
    bool empty() {
        return sz == 0;
    }
};
int main() {
    Queue q;
    q.push(12);
    q.push(10);
    q.push(90);
    cout << q.front() << '\n';
    cout << "Size: " << q.size() << '\n';
    q.pop();
    cout << q.front() << "\nSize: " << q.size() << '\n';
    q.pop();
    cout << q.front() << "\nSize: " << q.size() << '\n';
    cout <<( q.empty()? "Queue is empty": "Queue is not empty" )<< '\n';
    q.pop();
    cout <<( q.empty()? "Queue is empty": "Queue is not empty" )<< '\n';

    return 0;
}
