#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data, height;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    Node *root;
    int sz;

public:
    // Get the size
    int size() {
        return sz;
    }

    // Method to insert in a AVL Tree
    int insert(int data) {
        root = add(root, data);
    }

    // Inorder traversal
    void inorder() {
        inord(root);
        cout << '\n';
    }
private:
    // Utility function to insert data
    Node* add(Node *curr, int data) {
        if(curr == nullptr) {
            sz++;
            return new Node(data);
        }
        
        if(curr -> data > data) {
            root -> left = add(root -> left, data);
        } else if(curr -> data < data) {
            root -> right = add(root -> right, data);
        } else {
            return curr;
        }

        curr -> height = 1 + max(height(curr -> left), height(curr -> right));

        int balancingFactor = balanceFactor(curr);

        // Left-Left Case: 
        /*
                curr
               /    \
              x 
             / \
            y 
           / \ 
        */
        if(balancingFactor > 1 && curr -> data > data) {
            return rightRotate(curr);
        }

        // Right-Right Case:
        /*
                    curr
                   /    \
                  T1     x
                        / \
                       T2  y
                          / \ 
                         T3 T4            
         */
        if(balancingFactor < -1 && curr -> data < data) {
            return leftRotate(curr);
        }
        // Right-Left Case:
        /*
              z
             / \
            T1  x
               / \
              y  T2   
             / \
            T3 T4 
        */
        if(balancingFactor < -1 && curr -> right -> data > data) {
            Node *x = curr -> right;
            x = rightRotate(x);
            return leftRotate(curr);
        }

        // Left-Right Case:
        /*
                z
               / \ 
              x   T1
             / \
            T2  y
               / \ 
              T3 T4  
        */
        if(balancingFactor > 1 && curr -> left -> data < data) {
            Node *x = curr -> left;
            x = leftRotate(x);
            return rightRotate(curr);
        }

        return curr;
    }

    // Method for finding height
    int height(Node *root) {
        if(root == nullptr) {
            return 0;
        }
        return root -> height;
    }

    // Method for finding balancing factor
    int balanceFactor(Node *curr) {
        if(curr == nullptr)
            return 0;
        return height(curr -> left) - height(curr -> right);
    }

    // Method for right rotation for (left-left node)
    Node* rightRotate(Node *curr) {
        // Child of current node
        Node *x = curr -> left;
        // Rightsub tree of child of unbalanced node
        Node *xSubTree = x -> right;

        curr -> left = nullptr;
        x -> right = curr;
        curr -> left = xSubTree;

        // Updating Heights 
        curr -> height = 1 + max(height(curr -> left), height(curr -> right));
        x -> height = 1 + max(height(x -> left), height(x -> right));

        return x; // x is new node in place of curr
    }

    // Method for left rotation for (right-right rotate)
    Node* leftRotate(Node *curr) {
        // Right child of curr
        Node *x = curr -> right;
        // Right sub tree of child of unbalanced node
        Node *xSubTree = x -> left;

        curr -> right = nullptr;
        x -> left = curr;
        curr -> right = xSubTree;

        // Updating Heights
        curr -> height = 1 + max(height(curr -> left), height(curr -> right));
        x -> height = 1 + max(height(x -> left), height(x -> right));

        return x;
    }

    // Helper Function for inorder traversal
    void inord(Node *root) {
        if(root == nullptr)
            return;
            
        inord(root -> left);
        cout << root -> data << ' ';
        inord(root -> right);
    }
};

int main() {
    AVLTree avl;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        avl.insert(x);
    }    
    avl.inorder();
    return 0;
}
