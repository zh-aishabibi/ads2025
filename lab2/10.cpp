#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

int findMaxSum(Node* head) {
    int maxSum = INT_MIN;
    int currentSum = 0;
    Node* cur = head;

    while (cur != nullptr) {
        currentSum = max(cur->val, currentSum + cur->val);
        maxSum = max(maxSum, currentSum);
        cur = cur->next;
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* node = new Node(x);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    cout << findMaxSum(head) << endl;
    return 0;
}