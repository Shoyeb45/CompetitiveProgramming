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

// Inserting values in linked list - at start
void insert(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
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
    return 0;
}
