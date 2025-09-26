#include <iostream>
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

    void push_front(string data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            else
                front = NULL;
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

    void del_node(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == front)
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }

    void clear() {
        Node *curr = front;
        while (curr != NULL) {
            Node *next = curr->next;
            del_node(curr);
            curr = next;
        }
    }
    void print_front() {
        if (front == NULL)
            cout << "error" << endl;
        else
            cout << front->data << endl;
    }

    void print_back() {
        if (tail == NULL)
            cout << "error" << endl;
        else
            cout << tail->data << endl;
    }
};

int main() {
    LinkedList list;
    string command;

    while (cin >> command) {
        if (command == "add_front") {
            string book;
            cin >> book;
            cout << "ok" << endl;
            list.push_front(book);
        } else if (command == "add_back") {
            string book;
            cin >> book;
            cout << "ok" << endl;
            list.push_back(book);
        } else if (command == "erase_front") {
            list.print_front();
            list.pop_front();
        } else if (command == "erase_back") {
            list.print_back();
            list.pop_back();
        } else if (command == "front") {
            list.print_front();
        } else if (command == "back") {
            list.print_back();
        } else if (command == "clear") {
            list.clear();
            cout << "ok" << endl;
        } else {
            cout << "goodbye" << endl;
            break;
        }
    }

    return 0;
}