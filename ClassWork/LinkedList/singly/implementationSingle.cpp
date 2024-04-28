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

// Updating the value of node at kth position
void change(Node* head, int k, int val) {
    Node* temp = head;
    int pos = 0;
    while(pos != k) {
        temp = temp->next;
        pos++;
    }
    temp->x = val;
}

// Deleting the first node - at head
void delHead(Node* &head) {
    Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete at the end of the linked list - at tail
void delTail(Node* &head) {
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
}

// Deleting at kth position
void del(Node* &head, int k) {
    if(k == 0) {
        delHead(head);
        return;
    }
    Node* temp = head;
    int pos = 0;
    while(pos != k - 1) {
        temp = temp->next;
        pos++;    
    }
    
    Node* temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
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

    // Inserting values at head
    insert(a, 12);
    printLL(a);
    insert(a, 13);
    printLL(a);
    insert(a, 32);
    printLL(a);

    // Inserting at end position 
    insertEnd(a, 21);
    printLL(a);

    // Inserting at arbitary position 
    add(a, 1, 10);
    printLL(a);
    change(a, 3, 99);
    printLL(a);

    // deleting at head
    delHead(a);
    printLL(a);
    delHead(a);
    printLL(a);

    // delete at end
    delTail(a);
    printf("Deleting at tail:\n");
    printLL(a);

    // Inserting some values
    insert(a, 9);
    insertEnd(a, 11);
    printLL(a);

    // Deleting at arbitary position
    del(a, 2);
    cout << "\nDeleting at position 2\n";
    printLL(a);
    return 0;
}
