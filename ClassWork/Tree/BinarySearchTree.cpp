#include<bits/stdc++.h>
using namespace std;


template<typename T>
class BinarySearchTree {
    class Node {
    public:
        T info;
        Node *lChild;
        Node *rChild;

        Node(int data) {
            info = data;
            lChild = rChild = nullptr;
        }
    };
private:
    Node *root;
    int sz;

    
public:
    BinarySearchTree() {
        root = nullptr;
        sz = 0;
    }

    // Method for inserting data in BST
    void insert(T data) {
        if(root == nullptr) {
            root = new Node(data);
            sz++;
        } else {
            this->ins(data, root, nullptr);
        }
    }   

    // Method for inorder traversal
    void inorder() {
        this->inorderTrav(root);
        cout << '\n';
    }

    // Method to get size of the binary search tree
    int size() {
        return sz;
    }

    // Searching the data in binary search tree
    // @param T data
    // @return false if value is not present else it will return true
    bool search(T data) {
        if(root == nullptr) {
            return 0;
        } else {
            return this->searchVal(data, this->root);
        }
    }

    // Deleting a particular node from BST
    void remove(T data) {
        root = this -> rem(root, data);  
    }   
private:
    // Helper method to insert values
    void ins(T data, Node* curr, Node *prev) {
        while(curr != nullptr) {
            if(curr->info >= data) {
                prev = curr;
                curr = curr->lChild;
            } else {
                prev = curr;
                curr = curr->rChild;
            }
        }

        if(prev->info >= data) {
            prev->lChild = new Node(data);
        } else {
            prev->rChild = new Node(data);
        }
        sz++;
        return;
    }

    // Helper method for inorder traversal
    void inorderTrav(Node *rootNode) {
        if(rootNode == nullptr) 
            return;
        
        inorderTrav(rootNode->lChild);
        cout << rootNode->info << ' ';
        inorderTrav(rootNode->rChild);
    }  

    // Helper method to seach in BST
    bool searchVal(T data, Node *curr) {
        while(curr) {
            if(curr->info == data) {
                return 1;
            } else if(curr->info > data){
                curr = curr->lChild;
            } else {
                curr = curr->rChild;
            }
        }
        return 0;
    }

    Node* rem(Node *&curr, T data) {
        if(curr == nullptr)
            return curr;
        
        if(curr -> info > data) {
            curr -> lChild = rem(curr -> lChild, data);
            return curr;
        } else if(curr -> info < data) {
            curr -> rChild = rem(curr -> rChild, data);
            return curr;
        } else {
            // Case - 1: leaf Node
            if(curr -> rChild == nullptr && curr -> lChild == nullptr) {
                delete curr;
                sz--;
                return nullptr;
            } 
            // Case - 2: One child Node (Only left child)
            else if(curr -> rChild == nullptr) {
                Node *temp = curr -> lChild;
                delete curr;
                sz--;
                return temp;
            }
            // Case - 3: One child Node (Only right child) 
            else if(curr -> lChild == nullptr) {
                Node *temp = curr -> rChild;
                delete curr;
                sz--;
                return temp;
            }
            // Case - 4: Two child node
            else {
                Node *temp = curr -> lChild;
                while(temp -> rChild) {
                    temp = temp -> rChild;
                }
                curr -> info = temp -> info;
                curr -> lChild = rem(temp, temp -> info);
                return curr;
            }
        }
    }
};

int main() {
    BinarySearchTree<int> bst;
    bst.insert(19);
    bst.insert(9);
    bst.insert(10);
    bst.insert(6);
    bst.insert(20);
    bst.insert(22);
    bst.insert(23);
    bst.insert(21);
    bst.insert(3);

    bst.inorder(); // 3 6 9 10 19 20 21 22 23
    cout << "Size: " << bst.size() << '\n'; // To get size : 9

    // Searching 
    cout << (bst.search(6)? "6 Found in binary search tree\n": "6 not found in binary search tree\n");
    cout << (bst.search(23)? "23 Found in binary search tree\n": "23 not found in binary search tree\n");
    cout << (bst.search(19)? "19 Found in binary search tree\n": "19 not found in binary search tree\n");

    bst.remove(10);
    cout << "Size : " << bst.size() << '\n';
    bst.inorder();

    cout << '\n';

    bst.remove(6);
    cout << "Size : " << bst.size() << '\n';
    bst.inorder();
    return 0;   
}
