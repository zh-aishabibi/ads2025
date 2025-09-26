#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
    string val;
    Node *next;
    Node *prev;
    Node(string s): val(s), next(NULL), prev(NULL){};
};

int main() {
    int n, count = 1; cin >> n;
    string s;
    
    Node *head = NULL, *tail = NULL;
    
    for (int i =1 ; i <=n; i++){
        cin >> s;
        Node *node = new Node(s);
        if (head == NULL) head = tail = node;
        else {
            if (s != tail->val) count++;
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    cout << "All in all: " << count << endl << "Students: " << endl;
    Node * curr = tail;
    while (curr != NULL){
        cout << curr->val << endl;
        while (curr->prev != NULL && curr->val == curr->prev->val){
            curr = curr->prev;
        }
        curr = curr->prev;
    }
    return 0;
}