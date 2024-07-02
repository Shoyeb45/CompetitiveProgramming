#include<bits/stdc++.h>
using namespace std;

template<typename T>
class ThreadedTree {
    // Node for Threaded binary tree
    class Node {
    public:
        T info;
        Node *lChild;
        Node *rChild;
        bool lChildThread;
        bool rChildThread;

        Node(T data) {
            info = data;
            lChild = rChild = nullptr;
            lChildThread = rChildThread = 0;
        }
    };

private:
    Node *head;

public:
    ThreadedTree() {
        head = new Node(T());
        head->lChild = head->rChild = head;
        head->lChildThread = head->rChildThread = true;
    }

    // Inserting a new node in threaded tree
    void insert(T data) {
        if(head->lChild == head) {
            Node *newNode = new Node(data);
            head->lChild = newNode;
            head->lChildThread = 0;

            newNode->lChild = head;
            newNode->lChildThread = true;
            newNode->rChild = head;
            newNode->rChildThread = true;
        } else {
            this->ins(data, head->lChild, head);
        }
    }

    // Function for inorder traversal
    void inorder() {
        Node *curr = this->leftMostNode(head->lChild);

        while(curr != head) {
            cout << curr->info << ' ';
            if(curr->rChildThread) {
                curr = curr->rChild;
            } else {
                curr = leftMostNode(curr->rChild);
            }
        }
        cout << '\n';
    }

private:
    void ins(T data, Node *curr, Node *parent) {
        Node *newNode = new Node(data);
        while(curr) {
            if(data < curr->info) {
                if(!curr->lChildThread) {
                    parent = curr;
                    curr = curr->lChild;
                } else {
                    newNode->lChild = curr->lChild;
                    newNode->rChild = curr;
                    newNode->lChildThread = 1;
                    newNode->rChildThread = 1;

                    curr->lChild = newNode;
                    curr->lChildThread = 0;
                    return;
                }
            } else {
                if(!curr->rChildThread) {
                    parent = curr;
                    curr = curr->rChild;
                } else {
                    newNode->rChild = curr->rChild;
                    newNode->lChild = curr;
                    newNode->lChildThread = 1;
                    newNode->rChildThread = 1;

                    curr->rChild = newNode;
                    curr->lChildThread = 0;
                    return;
                }
            }
        }
    }

    // Helper function for finding leftmost node of tree
    Node* leftMostNode(Node *curr) {
        if(curr == nullptr)
            return nullptr;
        
        while(!curr->lChildThread) {
            curr = curr->lChild;
        }
        return curr;
    }
};

int main() {
    ThreadedTree<int> tbt;
    tbt.insert(10);  
    tbt.insert(9);
    tbt.insert(20);
    tbt.insert(1);
    tbt.insert(12);

    tbt.inorder();
    return 0;
}
