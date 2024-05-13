#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int x) {
            data = x;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLinkedList {
    public:
        Node* head;
        Node* tail;
        int sz;
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    // Method for appending in tail
    void append(int val) {
        Node* new_head = new Node(val);

        if(head == NULL) {
            head = new_head;
            tail = new_head;
            new_head->next = NULL;
            new_head->prev = NULL;
            sz++;
            return;
        }

        tail->next = new_head;
        new_head->prev = tail;
        tail = new_head;
        sz++;
        return; 
    }

    // Inserting in head
    void insert(int val) {
        Node * newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
            sz++;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        sz++;
        return;
    }

    // Inserting at any index
    void insertAtIndex(int val, int index) {
        if(index >= sz || index < 0) {
            throw std:: invalid_argument("Index is not valid");
        } else if(index == 0) {
            this->insert(val);
            sz++;
            return;
        } else if(index == sz - 1) {
            this->append(val);
            sz++;
            return;
        }

        Node* newNode = new Node(val);
        Node* it = head;
        int idx = 0;
        while(idx != index - 1) {
            idx++;
            it = it->next;
        }
        newNode->next = it->next;
        newNode->prev = it;
        it->next = newNode;
        newNode->next->prev = newNode;
        sz++;
    }

    // Remove head
    void removeHead() {
        Node* temp = head;
        head = temp->next;
        head->prev = NULL;
        free(temp);
        sz--;
    }

    // Remove tail 
    void removeTail() {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        sz--;
    }

    // Removing at random index
    void removeAtIndex(int index) {
        if(index >= sz || index < 0) {
            throw std:: invalid_argument("Index is not valid");
        } else if(index == 0) {
            this->removeHead();
            sz--;
            return;
        } else if(index == sz - 1) {
            this->removeTail();
            sz--;
            return;
        }
        Node* it = head;
        int idx = 0;
        while(idx != index - 1) {
            idx++;
            it = it->next;
        }
        Node* temp = it->next;
        it->next = temp->next;
        temp->next->prev = it;
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
        sz--;
        return;
    }
    // Checking doubly linked list is empty or not
    bool empty() {
        return sz == 0;
    }

    // Checking size of doubly linked list
    int size() {
        return sz;
    }

    // For printing
    friend ostream& operator<<(ostream& os, DoublyLinkedList dll) {
        Node* curr = dll.head;
        while(curr) {
            os << curr->data << " <-> " ;
            curr = curr->next;
        }
        os << "NULL\n" ;
        return os;
    }

    // For iterable doubly linked list
};

// class Iterator {
//     private:
//         Node* current;
    
//     public:
//         Iterator(Node* start) {
//             current = start;
//         }

//     Iterator operator++(int) {
//         Iterator prev = *this;
//         current = current->next;
//         return prev;
//     }
//     bool operator!=(const Iterator& other) const {
//         return current != other.current;
//     }

//     operator*() const {
//         return current->data;
//     }

//     Iterator begin() const {
//         return Iterator(NULL);
//     }

//     Iterator end() const {
//         return Iterator(NULL);
//     }
//     DoublyLinkedList :: Iterator begin(DoublyLinkedList & dll) {
//         return dll.begin();
//     }
//     DoublyLinkedList :: Iterator end(DoublyLinkedList & dll) {
//         return dll.end();
//     }
// };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Node* new_node = new Node(12);
    DoublyLinkedList dll;
   

    // cout << dll.head->data << '\n';
    cout << "Checking size and empty function.\n";
    cout << dll.size() << '\n';
    cout << dll.empty() << '\n';

    // inserting at the end:
    cout << "Inserting in tail\n: ";
    dll.append(20);
    cout << dll.size() << " Empty : " << dll.empty() << '\n';
    dll.append(92);
    cout << dll ;

    // Inserting at head
    cout << "Inserting in head\n: ";
    dll.insert(32);
    cout << dll ;
    dll.insert(10);
    cout << dll.size() << '\n';
    cout << dll;

    // Inserting at any random index
    cout << "Inserting 23 at 2nd index:\n";
    dll.insertAtIndex(23 , 2);
    cout << dll ;
    cout << "Inserting 43 at 3rd index.\n";
    dll.insertAtIndex(43, 3);
    cout << dll ;

    // Removing
    cout << "Removing head.\n";
    dll.removeHead();
    cout << dll << "size: " << dll.size() << '\n';
    cout << "Removing tail.\n";
    dll.removeTail();
    cout << dll << "size: " << dll.size() << '\n';

    // Removing at arbitary position
    dll.removeAtIndex(2);
    cout << "Removed the node at position 2.\n";
    cout << "size: " << dll.size() << '\n' << dll;
    dll.removeTail();
    cout << dll;
    dll.removeHead();
    cout << dll;
    // dll.removeAtIndex(0);
    // cout << dll;
    cout << dll.size() << '\n';
    if(dll.empty())
        cout << "Doubly linked list is empty\n";
    else
        cout << "Doubly linked list is not empty\n";
    
    dll.append(13);
    dll.append(132);
    dll.append(1314);

    cout << "Size: " << dll.size() << '\n';

    cout << dll;
    return 0;
}
