#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
    string data;
    Node *next, *prev;

    Node(string data) {
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

    void push_back(string data) {
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
       int n, k; cin >> n >> k; string str;
       LinkedList l;
       for (int i =0 ; i < n; i++){
           cin >> str;
           l.push_back(str);
       }
    Node* curr = l.front;
    while (k !=0){
        l.push_back(curr->data);
        curr = curr->next;
        l.pop_front();
        k--;
    }
    
    l.print();
    }