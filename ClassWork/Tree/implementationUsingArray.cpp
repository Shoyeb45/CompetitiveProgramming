#include<bits/stdc++.h>
using namespace std;

class Tree {
    private: 
        struct Node {
            int info;
            vector<int> children;
        };
        vector<Node> tree;
    bool checkIndex(int ind) {
        return ind >= 0 && ind < tree.size();
    }

    public:
        GeneralTree() {}
    
    int insertNode(int value) {
        Node newNode;
        newNode.info = value;
        tree.push_back(newNode);
        return tree.size() - 1;
    }

    void insertChild(int parentIndex, int childIndex) {
        if(checkIndex(parentIndex) && checkIndex(childIndex)) {
            tree[parentIndex].children.push_back(childIndex);
        } else {
            throw range_error("Out of range\n");
        }
    }
    void display() {
        for (int i = 0; i < tree.size(); ++i) {
            cout << "Node " << i << ": " << tree[i].info << " -> ";
            for (int child : tree[i].children) {
                cout << tree[child].info << " ";
            }
            cout << "\n";
        }
    }
    void displayChildren(int index) {
        if(checkIndex(index)) {
            cout << "Children of Node: " << tree[index].info << "->" << '\n';
            for(auto child: tree[index].children) {
                cout << tree[child].info << ' ';
            }
            cout << '\n';
        } else {
            throw range_error("Out of range\n");
        }
    }
};

int main() {
    Tree tr;
    int rootNode = tr.insertNode(12);
    int child1 = tr.insertNode(9);
    int child2 = tr.insertNode(10);
    int child3 = tr.insertNode(3);
    int child4 = tr.insertNode(-9);
    tr.insertChild(rootNode, child1);
    tr.insertChild(rootNode, child2);
    tr.insertChild(rootNode, child3);
    tr.insertChild(child2, child4);
    tr.display();
    tr.displayChildren(rootNode);
    return 0;
}
