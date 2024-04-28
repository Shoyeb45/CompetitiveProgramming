// Ques - Given the head of the linked list, delete every alternate element starting from second element.

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


// Necessary functions

// Method to print whole linked list
void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << '\n';
}    

// Inserting at head
void insertHead(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Inserting at tail
void insertTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    Node* last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode = NULL;
}

// Insert at kth position
void insert(Node* &head, int k, int val) {
    if(k == 0) {
        insertHead(head, val);
    }

    Node* newNode = new Node(val);
    Node* prevNode = head;
    int currentPos = 0;
    while(currentPos != k - 1) {
        prevNode = prevNode->next;
        currentPos++;
    }

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete node given t's address
void delAlternateNode(Node* &head) {
    Node* currentNode = head;

    while(currentNode != NULL && currentNode->next != NULL) {
        Node* temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        free(temp);
        currentNode = currentNode->next;
    }
}


int main() {

    Node* a = NULL;

    insertHead(a, 12);
    insertHead(a, 10);
    insertTail(a, 7);
    insertTail(a, 102);
    insert(a, 1, 13);

    insert(a, 4, 37);
    print(a);

    delAlternateNode(a);
    print(a);

  

    return 0;
}
