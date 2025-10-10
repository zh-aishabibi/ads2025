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

        void insert(int data) {
        if (root == NULL) {
            root = new Node(data);
            return;
        }

        Node *curr = root;
        while (true) {
            if (data < curr->data) {
                if (curr->left == NULL) {
                    curr->left = new Node(data);
                    break;
                }
                curr = curr->left;
            } else if (data > curr->data) {
                if (curr->right == NULL) {
                    curr->right = new Node(data);
                    break;
                }
                curr = curr->right;
            } else break;
        }
    }


    int diameter(Node* node, int &max_diameter) {
        if (node == NULL)
            return 0;

        int left_height = diameter(node->left, max_diameter);
        int right_height = diameter(node->right, max_diameter);

        max_diameter = max(max_diameter, left_height + right_height);

        return max(left_height, right_height) + 1;
    }

    int findDiameter(Node* node) {
        int max_diameter = 0;
        diameter(node, max_diameter);
        return max_diameter;
    }
};

int main() {

    int n;
    cin >> n;

    BST *bst = new BST();

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bst->insert(a);
    }

    cout << bst->findDiameter(bst->root) + 1 << endl;

    return 0;
}