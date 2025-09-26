#include <iostream>
#include <vector>
#include <algorithm>
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
    void insert_node(Node *node1, int data) {
        Node *node = new Node(data);
        if (node1 == tail) 
            push_back(data);
        else {
            Node *node2 = node1->next;
            node1->next = node;
            node->prev = node1;
            node->next = node2;
            node2->prev = node;
        }
    }
    
    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " " ;
            node = node->next;
        }
        cout << endl;
    }
};

    
    int main() {
       int n,b; cin >>n;
       LinkedList l; 
       for (int i =0 ; i < n; i++){
           cin >> b;
           l.push_back(b);
       }
       
    int dat, pos; cin >> dat >> pos;
    if (pos == 0) cout << dat << ' ';
    
    Node *curr = l.front;
    for (int i =0; i < pos; i++){
        if (i != pos-1)
            curr = curr->next;
        else 
        l.insert_node(curr,dat);
    }
    
    l.print();
    
    }