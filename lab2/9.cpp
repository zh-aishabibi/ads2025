#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    char data;
    Node *next, *prev;

    Node(char data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
public:
    Node *tail, *front;
    unordered_map<char, int> freq;

    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(char data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        freq[data]++;
    }
    char firstNonRepeating() {
        Node* curr = front;
        while (curr != NULL) {
            if (freq[curr->data] == 1) {
                return curr->data;
            }
            curr = curr->next;
        }
        return '-1';
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
    int n; cin >> n;
    while (n--){
    char b; int a; cin >> a;
    LinkedList l;
    for (int i =0; i < a; i++){
        cin >> b;
        l.push_back(b);
        if (l.firstNonRepeating() != '1') cout << l.firstNonRepeating() << " ";
        else cout << "-1" << ' ';
    }
    cout << endl;
}
    return 0;
}