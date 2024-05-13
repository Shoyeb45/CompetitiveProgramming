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

class Dequeue {
    Node* head;
    Node* tail;
    int sz;

    Dequeue() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    // Pushing at the end
    void push_back(int val) {
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

    // Pushing at the front
    void push_front(int val) {
        Node* new_node = new Node(val);
        if(head == NULL) {
            head = new_node;
            tail = new_node;
            sz++;
            return;
        }
        new_node->next = head;
        head = new_node;
        sz++;
        return;
    }

    // removing from front
    void pop_front() {
        if(sz == 0) {
            throw std:: invalid_argument("Already empty dequeue");
        }
        Node* temp = head;
        head = head->next;
        sz--;
        free(temp);
    }
    // removing from back
    void pop_back() {
        if(sz == 0) {
            throw std:: invalid_argument("Already empty dequeue");
        }
        Node* temp = tail;
        head = head->next;
        free(temp);
    }
};
int main() {
    
    return 0;
}
