#include <iostream>
#include <vector>
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
    void pop_front() {
        if (front != NULL) {
            front = front->next;
            if (front != NULL)
                front->prev = NULL;
            else
                tail = NULL;
        }
    }
    
    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};
    int main() {
       int n,b, k=0; cin >> n;
       LinkedList l;
       for (int i =0 ; i < n; i++){
           cin >> b;
           l.push_back(b);
       }
       
    vector <int> v;
    Node* curr = l.front;
    while (n!=0){
        if (k%2==0){
            v.push_back(curr->data);
        }
        k++; n--;
        curr = curr->next;
    }
    for (int i=0; i <v.size(); i++){
        cout << v[i] << ' ';
    }
    }