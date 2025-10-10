#include <iostream>
using namespace std;

class Node {
    public:
    Node *right, *left;
    int data;

    Node(int data) {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if(node == NULL) 
            return new Node(data);
        if(data < node->data) 
            node->left = insert(node->left, data);
        else 
            node->right = insert(node->right, data);
        return node;
    }

    Node *search(Node *node, int data) {
        if (node == NULL || data == node->data) 
            return node;
        if (data <= node->data) 
            return search(node->left, data);
        else 
            return search(node->right, data);
    }

    int countNodes(Node *node) {
        if(node == NULL) 
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int get_size(Node *node, int data) {
        Node *a = search(node, data);
        return countNodes(a);
    }
};

int main() {
    BST *bst = new BST();
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        bst->root = bst->insert(bst->root, a);
    }

    int target;
    cin >> target;

    int a = bst->get_size(bst->root, target);
    cout << a << endl;
}