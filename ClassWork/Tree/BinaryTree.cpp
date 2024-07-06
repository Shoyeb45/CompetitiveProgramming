#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

class Node {
public:
    int info;
    Node *lchild;
    Node *rchild;

    Node(int val) {
        info = val;
        lchild = rchild = nullptr;
    } 
};

class BinaryTree {
private:
    Node *rootNode;

    // Helper function for inorder traversal
    void inorderTrav(Node *root) {
        if(root == nullptr)
            return;
        inorderTrav(root->lchild);
        cout << root->info << ' ';
        inorderTrav(root->rchild);
    }

    // Helper function for preorder traversal
    void preorderTrav(Node *root) {
        if(!root)
            return;

        cout << root->info << " ";
        preorderTrav(root->lchild);
        preorderTrav(root->rchild);
    }

    // Helper function for postorder traversal
    void postorderTrav(Node *root) {
        if(!root) {
            return;
        }
        postorderTrav(root->lchild);
        postorderTrav(root->rchild);
        cout << root->info << ' ';
    }
public:
    BinaryTree() {
        rootNode = nullptr;
    }

    // Set root node of binary tree
    Node* setRoot(int val) {
        if(rootNode == nullptr) {
            rootNode = new Node(val);
            return rootNode;
        } else {
            cout << "Root node is already present.\n";
            return rootNode;
        }
    }

    // Set left child of parentNode
    Node* setLeftChild(Node *parentNode, int val) {
        if(parentNode->lchild != nullptr) {
            cout << "Left child is already present\n";
            return parentNode->lchild;
        } else {
            Node* leftChild = new Node(val);
            parentNode->lchild = leftChild;
            return leftChild;
        }
    }

    // Set right child of parentNode
    Node* setRightChild(Node *parentNode, int val) {
        if(parentNode->rchild != nullptr) {
            cout << "Left child is already present\n";
            return parentNode->rchild;
        } else {
            Node* rightChild = new Node(val);
            parentNode->rchild = rightChild;
            return rightChild;
        }
    }

    // function for inorder traversal
    void inorder() {
        this->inorderTrav(rootNode);
        cout << "\n";
    }

    // function for preorder traversal
    void preorder() {
        this->preorderTrav(rootNode);
        cout << "\n";
    }

    // function for postorder traversal
    void postorder() {
        this->postorderTrav(rootNode);
        cout << '\n';
    }

    // Funtion for searching in binary tree
    bool search(int val) {
        if(rootNode == null)
            return false;
        
        queue<Node*> q;
        q.push(rootNode);
        
        while(!q.empty()) {
            Node *
        }
    }
};
int main() {
    BinaryTree bt;
    Node *root = bt.setRoot(12);
    
    Node *rootChildLeft = bt.setLeftChild(root, 3);
    Node *rootChildRight = bt.setRightChild(root, 4);
    Node *child1_1 = bt.setLeftChild(rootChildLeft, 31);
    Node *child1_2 = bt.setRightChild(rootChildLeft, 32);
    Node *child2_1 = bt.setLeftChild(rootChildRight, 41);
    Node *child1_2_1 = bt.setLeftChild(child1_2, 321);
    Node *child1_2_2 = bt.setRightChild(child1_2, 322);
    Node *child2_2 = bt.setRightChild(rootChildRight, 42);
    Node *child2_1_1 = bt.setLeftChild(child2_1, 411);
    Node *child2_1_2 = bt.setRightChild(child2_1, 412);


    cout << "Inorder Traversal of binary tree: \n";
    bt.inorder();
    cout << '\n';

    cout << "Preorder Traversal of binary tree: \n";
    bt.preorder();
    cout << '\n';

    cout << "Postorder Traversal of binary tree: \n";
    bt.postorder();
    cout << '\n';

    return 0;
}
