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
    int pop() {
        if(sz == 0) {
            throw std:: invalid_argument("Index is not valid");
        }
        Node* temp = head;
        int data = temp->data;
        head = head->next;
        delete temp;
        sz--;
        return data;
    }

    // Returns size of queue
    int size() {
        return sz;
    }

    // Checking the element is present or not
    bool contains(int val) {
        if(head == nullptr) {
            throw invalid_argument("Queue is empty");
        }
        Node *it = head;
        while(it) {
            if(it->data == val) {
                return true;
            }
            it = it->next;
        }
        return false;
    }

    // Is it empty?
    bool empty() {
        return sz == 0;
    }
};
int main() {
    Queue q;
    q.push(12); // {12}
    q.push(10); // {12, 10}
    q.push(90); // {12, 10, 90}
    cout << q.front() << '\n'; // 12

    cout << "Does it containes 10: " << (q.contains(10)? "Yes": "No") << '\n';
    cout << "Does it containes 45: " << (q.contains(45)? "Yes": "No") << '\n';

    cout << "Size: " << q.size() << '\n';
    cout << "Removed element: " << q.pop() << '\n';
    cout << q.front() << "\nSize: " << q.size() << '\n';
    cout << "Removed element: " << q.pop() << '\n';
    cout << q.front() << "\nSize: " << q.size() << '\n';
    cout <<( q.empty()? "Queue is empty": "Queue is not empty" )<< '\n';
    cout << "Removed elemet: " << q.pop() << '\n'; 
    cout <<( q.empty()? "Queue is empty": "Queue is not empty" )<< '\n';

    return 0;
}
