#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *right, *left;

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
        if(node == NULL || data == node->data) 
            return node;
        if(data < node->data)
            return search(node->left, data);
        else 
            return search(node->right, data);
    }

    void preOrder(Node *node) {
        if(node == NULL) 
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
};

int main() {
    int n; cin >> n;
    BST *bst = new BST();

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        bst->root = bst->insert(bst->root, a);
    }

    int target;
    cin >> target;
    Node *result = bst->search(bst->root, target);

    bst->preOrder(result);
}