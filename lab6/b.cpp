#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void quick_sort(vector<int> &v, int left, int right) {
    int i = left;
    int j = right;
    int p = v[(left + right) / 2];

    while(i <= j) {
        while(v[i] < p) i++;
        while(v[j] > p) j--;

        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    if (left < j) quick_sort(v, left, j);
    if (i < right) quick_sort(v, i, right);
}

int main() {
    int n, k;
    cin >> n >> k;
    bool first_zero = false;
    bool second_zero = false;
    if (n == 0) first_zero = true;
    if (k == 0) second_zero = true;

    vector<int> first(n);
    vector<int> second(k);

    if (!first_zero)
        for(int i = 0; i < n; i++) cin >> first[i];

    if (!second_zero)
        for (int i = 0; i < k; i++) cin >> second[i];


    if(!first_zero) quick_sort(first, 0, n - 1);
    if(!second_zero) quick_sort(second, 0, k - 1);

    queue<int> q1;
    queue<int> q2;

    if(!first_zero) 
        for (int i = 0; i < n; i++) q1.push(first[i]);
    else {
        cout << "";
        return 0;
    }

    if(!second_zero)
        for (int i = 0; i < k; i++) q2.push(second[i]);
    else {
        cout << "";
        return 0;
    }

    while(!q1.empty() && !q2.empty()) {
        if(q1.front() > q2.front()) q2.pop();
        else if (q1.front() < q2.front()) q1.pop();
        else  {
            cout << q1.front() << " ";
            q1.pop();
            q2.pop();
        }
    }

    return 0;
}