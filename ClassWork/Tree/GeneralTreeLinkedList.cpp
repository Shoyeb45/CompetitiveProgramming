#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int info;
    Node *sibling;
    Node *firstChild;

    Node(int val) {
        info = val;
        sibling = firstChild = nullptr;
    }
};

class Tree {
private:
    Node *rootNode;

public:
    Tree() {
        rootNode = nullptr;
    }

    // Insert a root Node
    Node* setRoot(int val) {
        if(!rootNode) {
            rootNode = new Node(val);
            return rootNode;
        } else {
            cerr << "Root alreadu exists\n";
        }
    }

    
    // Add child of particular parent node
    Node* addChild(Node *parentNode, int val) {
        if(parentNode == nullptr)
            std:: __throw_bad_alloc();
        Node *child = new Node(val);
        if(parentNode->firstChild == nullptr) {
            parentNode->firstChild = child;
        } else {
            Node *temp = parentNode->firstChild;
            while(temp->sibling) {
                temp = temp->sibling;
            }
            temp->sibling = child;
        }
        return child;
    }
    // Function to call for preorder traversal
    void preorder() {
        preOrderTrav(rootNode);
        cout << '\n';
    }

    // Find particular node by a value
    // @return node if present else nullptr
    Node* find(int val) {
        Node *root = rootNode;
        if(rootNode == nullptr)
            return nullptr;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node *currNode = q.front();
            q.pop();
            
            if(currNode->info == val) {
                return currNode;
            }
            if(currNode->firstChild != nullptr) {
                q.push(currNode->firstChild);
                Node *siblings = currNode->firstChild->sibling;
                while(siblings) {
                    q.push(siblings);
                    siblings = siblings->sibling;
                }
            }
        }
        return nullptr;
    }

    // Function for pre-order traversal
private:
    void preOrderTrav(Node *root) {
        if(!root)
            return;
        cout << root->info << " ";
        preOrderTrav(root->firstChild);
        preOrderTrav(root->sibling);
    }
};
int main() {
    Tree tr;
    Node *root = tr.setRoot(12);
    Node *child1 = tr.addChild(root, 3);
    Node *child2 = tr.addChild(root, 9);
    Node *child3 = tr.addChild(root, 19);
    Node *child4 = tr.addChild(child2, -3);
    Node *child5 = tr.addChild(child2, 12);
    Node *child6 = tr.addChild(child3, 2);
    Node *child7 = tr.addChild(child6, 21);
    Node *child8 = tr.addChild(child6, 22);
    Node *child9 = tr.addChild(child6, 23);
    Node *child10 = tr.addChild(tr.find(3), 31);
    tr.preorder();
    return 0;
}
