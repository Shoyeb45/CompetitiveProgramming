#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Node {
    public:
        int val;
        Node* next;
    
    Node(int x) {
        val = x;
        next = NULL;
    }
};

class LinkedList {
    public:
        Node* head;
        int sz;
    
    LinkedList() {
        head = NULL;
        sz = 0;
    }

    // Method to insert at last position
    void append(int val) {
        
        Node* newHead = new Node(val);
        if(head == NULL) {
            head = newHead;
            sz++;
            return; 
        }

        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newHead;
        sz++;
    }

    // Method to insert at head
    void preppend(int val) {
        Node* newHead = new Node(val);

        if(head == NULL) {
            head = newHead;
            sz++;
            return;
        }
        Node* temp = head;
        newHead->next = head;
        head = newHead;
        sz++;
    }

    int size() {
        return sz;
    }

    // For printing linked list
    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    LinkedList a;
    while(n--) {
        int x; cin >> x;
        a.preppend(x);
    }
    
  
    a.display();
    cout << a.size() << endl;
    return 0;
}

