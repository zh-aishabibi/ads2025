#include <iostream>
#include <climits>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LinkedList {
    public:
    Node *tail, *front;
    
    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
};
    int main() {
        int n,b,x,m,pos, st =0; cin >> n;
        LinkedList l;
        for (int i=0; i <n; i++){
            cin >> b;
            l.push_back(b);
        }
        cin >> x; m = INT_MAX;
        Node* current = l.front;
        
        while( current != NULL){
            if (abs(current-> data - x )< m){
                m = abs(current-> data - x );
                pos = st;
            }
            st++;
            current = current->next;
        }
        cout << pos;
        
    }