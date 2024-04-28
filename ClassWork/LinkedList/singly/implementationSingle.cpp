#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Node {
public:
    int x;
    Node* next;

    Node(int val) {
        x = val;
        next = NULL;
    }

    
};
// Inserting value at end -  at tail
void insertEnd(Node* &head, int val) {
    Node* newHead = new Node(val);
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = newHead;
    newHead->next = NULL;
}

// Inserting values in linked list - at head
void insert(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Inserting at the arbitary position - kth
void add(Node* &head, int k, int val) {
    if(k == 0) {
        insert(head, val);
        return;
    }

    Node* newNode = new Node(val);
    int p = 0;
    Node* temp = head;
    while(p != k -1) {
        temp = temp->next;
        p++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function for traversing through linked list 
void printLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->x << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* a = NULL;
    // Node* b = new Node(7);
    // Node* c = new Node(12);

    // cout << a->x << " " << a->next << endl;
    // cout << b->x << " " << b->next << endl;

    // Inserting values
    insert(a, 12);
    printLL(a);
    insert(a, 13);
    printLL(a);
    insert(a, 32);
    printLL(a);
    insertEnd(a, 21);
    printLL(a);
    add(a, 1, 10);
    printLL(a);
    return 0;
}
