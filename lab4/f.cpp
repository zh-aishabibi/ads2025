#include <iostream>
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

    Node *insert(Node* node, int data) {
        if(node == NULL) {
            node = new Node(data);
            return node;
        }
        if(data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    int countTriangles (Node *node) {
        if(node == NULL) 
            return 0;
        int cnt = 0;
        if(node->left != NULL && node->right != NULL)
            cnt++;
        cnt += countTriangles(node->left);
        cnt += countTriangles(node->right);
        return cnt;
    }
};

int main() {
    BST *bst = new BST();
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int b; cin >> b; 
        bst->root = bst->insert(bst->root, b);
    }

    int a = bst->countTriangles(bst->root);
    cout << a << endl;
}