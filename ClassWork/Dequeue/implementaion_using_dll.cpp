#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Dequeue {
    Node* head;
    Node* tail;
    int sz;

public:
    Dequeue() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    // Pushing at the end
    void push_back(int val) {
        Node* new_node = new Node(val);
        if(head == nullptr) {
            head = new_node;
            tail = new_node;
            sz++;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = tail->next;
        sz++;
        return;
    }

    // Pushing at the front
    void push_front(int val) {
        Node* new_node = new Node(val);
        if(head == nullptr) {
            this->push_back(val);
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        sz++;
        return;
    }

    // removing from front
    int pop_front() {
        if(!head) {
            throw std:: invalid_argument("Stack is empty.");
        }
        Node* temp = head;
        int val = temp->data;

        if(head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
       
        delete temp;
        sz--;
        return val;
    }

    // removing from back
    int pop_back() {
        if(!head)
            pop_front();
        Node* temp = tail;
        int val = temp->data;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        sz--;
        return val;
    }

    // Get first element
    int front() {
        if(sz == 0) {
            return 0;
        }
        return head->data;
    }

    // Get last element
    int back() {
        if(sz == 0) {
            return 0;
        }
        return tail->data;
    }

    // Get size
    int size() {
        return sz;
    }

    // Returns true if it is empty else false
    bool empty() {
        return sz == 0;
    }

};
int main() {
    Dequeue dq;
    dq.push_back(12);
    dq.push_back(-9);
    cout << dq.size() << '\n';
    cout << dq.back() << '\n';
    cout << dq.front() << '\n';

    dq.push_front(10);
    cout << dq.front() << '\n';
    cout << (dq.empty()? "Yeah empty\n": "Not empty\n");
    
    dq.push_front(89);
    cout << dq.front() << '\n';
    return 0;
}
