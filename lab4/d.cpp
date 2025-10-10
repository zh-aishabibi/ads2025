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

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if(node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    int getHeight(Node *node) {
        if(node == NULL) 
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};

int main() {
    int n;
    cin >> n;
    BST *bst = new BST();
    Node *root = NULL;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        bst->root = bst->insert(bst->root, a);
    }

    queue<Node*> q;
    q.push(bst->root);

    vector<int> sums;

    while(!q.empty()) {
        int sz = q.size();
        int level_sum = 0;

        for(int i = 0; i < sz; i++) {
            Node *curr = q.front();
            q.pop();

            level_sum += curr->data;
            
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL) 
                q.push(curr->right);
        }

        sums.push_back(level_sum);
    }

    cout << bst->getHeight(bst->root) << endl;
    for(int i = 0; i < sums.size(); i++) 
        cout << sums[i] << " ";

    return 0;
}