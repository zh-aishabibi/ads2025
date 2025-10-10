#include<iostream>
using namespace std;


struct Node {
    public:
	int data;
	Node* left;
	Node* right;
    int cnt;

	Node(int data) {
        this->cnt = 1;
		this->data = data;
		left = NULL;
		right = NULL;
	} 
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

    Node* add(Node* root, int data) {
        if (root == NULL) {
            root = new Node(data);
            return root;
        } 
        if (root->data > data) {
                root->left = add(root->left, data);
        } else if (root->data < data) {
                root->right = add(root->right, data);
        } else {
                root->cnt ++;
            }
        return root;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == NULL) {
            return NULL;
        } else if (root->data > data) {
            root->left = deleteNode(root->left, data);
            return root;
        } else if (root->data < data) {
            root->right = deleteNode(root->right, data);
            return root;
        } else {

            if(root->cnt > 1) {
                root->cnt--;
                return root;
            }


            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else {
                Node* temp = getMin(root->right);
                root->data = temp->data;
                root->cnt = temp->cnt;
                temp->cnt = 1;
                root->right = deleteNode(root->right, temp->data);
                return root;
            }
        }
    }

    Node* find(Node* root, int x) {
        if (root == NULL) {
            return NULL;
        } else if (root->data == x) {
            return root;
        } else if (root->data < x) {
            return find(root->right, x);
        } else {
            return find(root->left, x);
        }
    }

    int count(Node *root, int x) {
        Node* node = find(root, x);
        if(node != NULL) {
            return node->cnt;
        } else {
            return 0;
        }
    }
};

int main() {
    int num;
    cin >> num;
    BST *bst = new BST();
    for(int i = 0; i < num; i++) {
        string commands;
        cin >> commands;
        int a; cin >> a;
        if(commands == "insert") {
            bst->root = bst->add(bst->root, a);
        } else if(commands == "delete") 
            bst->root = bst->deleteNode(bst->root, a);
        else if (commands == "cnt") 
            cout << bst->count(bst->root, a) << endl;
    }
    return 0;
}