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
    }
};

class Stack {
    Node* head;
    int sz;
    public:
    Stack() {
        head = nullptr;
        sz = 0;
    }
    public:
    // Pushing at top
    void push(int val) {
        Node* new_node = new Node(val);
        if(head == NULL) {
            head = new_node;
            sz++;
            return;
        }
        new_node->next = head;
        head = new_node;
        sz++;
        return;
    }

    // Get top element
    int top() {
        return head->data;
    }

    // Remove top element
    void pop() {
        if(sz == 0) {
            throw std:: invalid_argument("No element in stack");
        }
        Node* temp = head;
        head = head->next;
        sz--;
        free(temp);
    }
    // Is it empty?
    bool empty() {
        return sz == 0;
    }
    // Get size
    int size() {
        return sz;
    }
};
int main() {
    Stack s;

    s.push(3);
    cout << s.top();
    s.push(14);
    s.push(8);
    cout << "\nSize:" << s.size();
    cout << '\n' << s.top();
    s.pop();
    cout << "\nSize: " << s.size();
    cout << '\n' << s.top();
    s.push(90);
    s.push(13);

    cout << '\n' << s.top();
    return 0;
}
