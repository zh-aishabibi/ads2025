#include <iostream> 
  
using namespace std; 
  
struct Node{ 
    int val; 
    Node* next; 
    Node(): val(0), next(nullptr) {} 
    Node(int x): val(x), next(nullptr) {} 
    Node(Node* next): val(0), next(next) {} 
    Node(int x, Node* next): val(x), next(next) {} 
}; 
  
Node* insert(Node* head, Node* node, int p){ 
    if (p == 0) { 
        node->next = head; 
        return node; 
    } 
    Node* cur = head; 
    for (int i = 0; cur && i < p - 1; i++) { 
        cur = cur->next; 
    } 
    if (!cur) { 
        return head; 
    } 
    node->next = cur->next; 
    cur->next = node; 
    return head; 
 
} 
  
Node* remove(Node* head, int p){ 
    if (head == NULL) { 
        return NULL; 
    } 
    if (p == 0) { 
        Node* tmp = head->next; 
        delete head; 
        return tmp; 
    } 
    Node* cur = head; 
    for (int i = 0; cur->next && i < p - 1; i++) { 
        cur = cur->next; 
    } 
    if (!cur->next) { 
        return head; 
    } 
    Node* del = cur->next; 
    cur->next = del->next; 
    delete del; 
    return head; 
 
} 
  
Node* replace(Node* head, int p1, int p2){ 
    if (!head || p1 == p2) { 
        return head; 
    } 
 
    Node* prev1 = NULL; 
    Node* cur1 = head; 
    for (int i = 0; cur1 && i < p1; i++) { 
        prev1 = cur1; 
        cur1 = cur1->next; 
    } 
    if (cur1 == NULL) { 
        return head; 
    } 
 
    if (prev1 != NULL) { 
        prev1->next = cur1->next; 
    } 
    else { 
        head = cur1->next; 
    } 
 
    if (p2 == 0) { 
        cur1->next = head; 
        return cur1; 
    } 
 
    Node* cur2 = head; 
    for (int i = 0; cur2 && i < p2 - 1; i++) { 
        cur2 = cur2->next; 
    } 
    if (cur2 == NULL) { 
        return head; 
    } 
 
    cur1->next = cur2->next; 
    cur2->next = cur1; 
 
    return head; 
 
} 
  
Node* reverse(Node* head){ 
    Node* prev = NULL; 
    Node* cur = head; 
    while (cur != NULL) { 
        Node* nxt = cur->next; 
        cur->next = prev; 
        prev = cur; 
        cur = nxt; 
    } 
    return prev; 
} 
  
void print(Node* head){ 
    Node* cur = head; 
    while (cur != NULL) { 
        cout << cur->val << " "; 
        cur = cur->next; 
    } 
    cout << endl; 
} 
 
int length(Node* head) { 
    int len = 0; 
    while (head != NULL) { 
        len++; 
        head = head->next; 
    } 
    return len; 
} 
  
Node* cyclic_left(Node* head, int x){ 
    if (head == NULL || head->next == NULL) { 
        return head; 
    } 
    int n = length(head); 
    x %= n; 
    if (x == 0) { 
        return head; 
    } 
 
    Node* cur = head; 
    for (int i = 0; i < x - 1; i++) { 
        cur = cur->next; 
    } 
 
    Node* newHead = cur->next; 
    cur->next = NULL; 
 
    Node* tail = newHead; 
    while (tail->next != NULL) { 
        tail = tail->next;  
    } 
    tail->next = head; 
    return newHead; 
} 
  
Node* cyclic_right(Node* head, int x){ 
    if (head == NULL || head->next == NULL) { 
        return head; 
    } 
    int n = length(head); 
    x %= n; 
    if (x == 0) { 
        return head; 
    } 
    return cyclic_left(head, n - x); 
} 
  
int main(){ 
    Node* head = NULL; 
    while (true) 
    { 
        int command; cin >> command; 
        if (command == 0){ 
            break; 
        }else if(command == 1){ 
            int x, p; cin >> x >> p; 
            head = insert(head, new Node(x), p); 
        }else if (command == 2){ 
            int p; cin >> p; 
            head = remove(head, p); 
        }else if (command == 3){ 
            print(head); 
        }else if (command == 4){ 
            int p1, p2; cin >> p1 >> p2; 
            head = replace(head, p1, p2); 
        }else if (command == 5){ 
            head = reverse(head); 
        }else if (command == 6){ 
            int x; cin >> x; 
            head = cyclic_left(head, x); 
        }else if (command == 7){ 
            int x; cin >> x; 
            head = cyclic_right(head, x); 
        }    
    } 
    return 0; 
}