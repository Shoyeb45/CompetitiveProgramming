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

class Linked_list {
    public:
        Node* head;
        int sz;
    
    Linked_list() {
        head = nullptr;
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
    
    // Insert at any value
    void insert(int val, int index) {
        if(index < 0 || index > sz) {
            throw out_of_range("Index out of bound");
        }
        if(index == 0) {
            this->preppend(val);
            return;
        } else if(index == sz) {
            this->append(val);
            return;
        }
        Node* new_node = new Node(val);
        Node* it = head;
        for(int i = 0; i < index - 1; i++) {
            it = it->next;
        }
        new_node->next = it->next;
        it->next = new_node;
        sz++;
        return;
    }

    // For removing at any postion
    void remove(int index) {
        if(index < 0 || index >= sz) {
            throw out_of_range("Index out of bound.");
        }
        if(index == 0) {
            Node* temp = head;
            head = head->next;
            free(temp);
            sz--;
            return;
        }   
        Node* it = head;
        loop(i, index - 1) {
            it = it->next;
        }
        Node* temp = it->next;
        it->next = it->next->next;
        free(temp);
        sz--;
        return;
    }

    // Method to rotate the linked list by k elements is right
    void rotate(int k) {
        if(head == nullptr || k == 0 || sz == 0)
            return;

        k = k % sz;
        if(k == 0)
            return;
        Node* fast = head;
        Node* slow = head;

        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
    }

    // Reverse a linked list
    void Reverse() {
        if(!head || !head->next) {
            return;
        }

        Node* prev = head;
        Node* curr = head->next;
        prev->next = nullptr;

        while(curr) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }

    // Merging two linked list
    void merge(Node* a) {
        if(a == nullptr) { 
            return;
        }
        if(head == nullptr) {
            head = a;
            return;
        }

        Node* it = nullptr;
        Node* ans = NULL;
        Node* ll1 = head;
        Node* ll2 = a;
        if(ll1->data <= ll2->data) {
            it = ll1;
            ans = it;
            ll1 = ll1->next;
        } else {
            it = ll2;
            ans = it;
            ll2 = ll2->next;
        }

        while(ll1 && ll2) {
            if(ll1->data <= ll2->data) {
                it->next = ll1;
                ll1 = ll1->next;
                it = it->next;
            } else {
                it->next = ll2;
                ll2 = ll2->next;
                it = it->next;
            }
        }
        if(!ll1) {
            it->next = ll2;
        } else {
            it->next = ll1;
        }
        head = ans;
    }

    // Middle element
    Node* middle() {
        if(!head || !head->next)
            return head;
         
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // First occurence of given element - if not then null pointer
    Node* first_occurence(int target) {
        if(!head)
            return head;
        Node* it = head;
        while(it) {
            if(it->data == target) 
                return it;
            it = it->next;
        }
        return nullptr;
    }

    // Interleaving two linked list
    void interleave(Node* b) {
        if(!this->head) {
            head = b;
            return;
        }
        if(!b) {
            return;
        }

        Node* it1 = head;
        Node* it2 = b;
        while(it1 && it2) {
            Node* temp1 = it1->next;
            Node* temp2 = it2->next;
            if(!it1->next) {
                it1->next = it2;
                break;
            }
            it1->next = it2;
            it2->next = temp1;

            it1 = temp1;
            it2 = temp2;
        }
        if(it2) {
            it1->next = it2;
        }
        head = it1;
    }

    // Spliting the Linked list in two linked list at specified index
    void split(int k) {
        if(k < 0 || k >= this->sz) {
            throw out_of_range("Index out of bound");
        }

        loop(i, this->sz) {
            if(i < k) {
                cout << this->head->data << ' ';
            } else {
                if(i == k)
                    cout << '\n';
                cout << this->head->data << ' ';
            }
        }
    }
    // Return size
    int size() {
        return sz;
    }

    // Check if linked list is empty or not
    bool empty() {
        return this->sz == 0;
    }

    // For printing linked list
    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    
    Linked_list a;
    // a.append(3);
    // a.append(4);
    // a.preppend(9);
    // a.insert(5, 2);
    // a.insert(7, 3);
    // a.display();
    // cout << a.size() << '\n';
    // a.remove(a.size() - 1);
    // a.display();
    // a.Reverse();
    // a.display();
    Linked_list b;
    a.append(132);
    a.preppend(45);
    a.preppend(15);
    a.preppend(10);
    a.preppend(5);
    b.append(49);
    b.preppend(4);
    cout << "a\n" ;
    a.display();
    cout << "b\n" ;
    b.display();
    cout << "Merged list\n";
    a.merge(b.head);
    a.display();
    // a.append(34);
    // a.display();
    Linked_list c;
    // c.head = a.middle();
    // c.display();
    c.head = a.first_occurence(9);
    c.display();

    // a.interleave(c.head);
    // a.display();
    return 0;
}
