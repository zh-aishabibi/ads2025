#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];


    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) /2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void print_array(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a;
    vector<int> common;

    for(int i = 0; i < n; i++) {
        int b; cin >> b;
        a.push_back(b);
    }

    merge_sort(a, 0, a.size() - 1);
    stack<int> st1;
    for (int i = 0; i < a.size(); i++)
        st1.push(a[i]);


    stack<int> st2;

    a.clear();

    for (int i = 0; i < k; i++) {
        int b; cin >> b;
        a.push_back(b);
    }

    merge_sort(a, 0, a.size() - 1);

    for(int i = 0; i < a.size(); i++) {
        st2.push(a[i]);
    }

    while (!st1.empty() && !st2.empty()) {
        if(st1.top() < st2.top()) {
            st2.pop();
        } else if (st1.top() > st2.top()) {
            st1.pop();
        } else {
            common.push_back(st1.top());
            st1.pop();
            st2.pop();
        }
    }

    merge_sort(common, 0, common.size() - 1);
    print_array(common);
    return 0;
}