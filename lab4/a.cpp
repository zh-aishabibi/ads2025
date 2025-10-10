#include <iostream>
#include <vector>
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
        this->root = NULL;
    }

    Node *insert(Node *node, int data) {
        if(node == NULL) return new Node(data);
        if(data <= node->data) node->left = insert(node->left, data);
        else node->right = insert(node->right, data);
        return node;
    }

    Node *search(Node *node, int data) {
        if(node == NULL || node->data == data) return node;
        if(data < node->data) return search(node->left, data);
        else return search(node->right, data);
    }

    bool path_exists(Node *node, string p) {
        Node *curr = node;
        for(int i = 0; i < p.size(); i++) {
            if(curr == NULL) {
                return false;
            } 
            if(p[i] == 'R') {
                curr = curr->right;
            }
            if (p[i] == 'L') {
                curr = curr->left;
            }
        }
        return curr != NULL;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> path;


    BST *bst = new BST();

    for(int i = 0; i < n; i ++) {
        int a; cin >> a;
        bst->root = bst->insert(bst->root, a);
    }

    for(int i = 0; i < m; i++) {
        string g; cin >> g;
        path.push_back(g);
    }

    for(int i = 0; i < m; i++) {
        bool a = bst->path_exists(bst->root, path[i]);
        if(a) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}