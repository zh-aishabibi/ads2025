#include <iostream>
#include <queue>
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

class BST{
    public:
    Node *root;

    BST() {
        root = new Node(1);
    }

    Node *search(Node *node, int data) {
        if(node == NULL)
            return NULL;
        if(node->data == data) 
            return node;
        
        Node *left_search = search(node->left, data);
        if(left_search != NULL) 
            return left_search;
        return search(node->right, data);
    }

    void insert(int parent, int child, int left_right) {
        Node *parent_node = search(root, parent);
        Node *child_node = new Node(child);
        if(left_right == 0) 
            parent_node->left = child_node;
        else
            parent_node->right = child_node;
    }
};

int main() {
    int n, parent, value, left_right;
    cin >> n;

    BST *bst = new BST();

    for(int i = 0; i < n - 1; i++) {
        cin >> parent >> value >> left_right;
        bst->insert(parent, value, left_right);
    }

    queue<Node*> children;
    children.push(bst->root);
    int max = 0;

    while(!children.empty()) {
            int sz = children.size();
            if(max < children.size()) max = children.size();

            for(int i = 0; i < sz; i++) {
                Node *curr = children.front();
                children.pop();

                if(curr->left != NULL)
                    children.push(curr->left);
                if(curr->right != NULL)
                    children.push(curr->right);
            }
        }
    cout << max << endl;
}