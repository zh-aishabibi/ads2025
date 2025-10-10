#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if(node == NULL) {
            return new Node(data);
        }
        if(data < node->data)
            node->left = insert(node->left, data);
        else 
            node->right = insert(node->right, data);
        return node;
    }

    void inOrder(Node *node, vector<int> &vect) {
        if(node == NULL){
            return;
        }
        inOrder(node->left, vect);
        vect.push_back(node->data);
        inOrder(node->right, vect);
    }
};

int main() {
    int n;
    cin >> n;
    BST *bst = new BST();

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        bst->root = bst->insert(bst->root, a);
    }

    bst->inOrder(bst->root, v);

    reverse(v.begin(), v.end());

    for(int i = 1; i < v.size(); i++) {
        v[i] = v[i] + v[i - 1];
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}