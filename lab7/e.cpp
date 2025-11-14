#include <bits/stdc++.h>
using namespace std;

int n, m;

struct row {
    int sum;
    int elements[502];
};

bool lessThan(const row &a, const row &b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    for (int i = 1; i <= m; i++) {
        if (a.elements[i] != b.elements[i])
            return a.elements[i] < b.elements[i];
    }
    return false;
}

void mergeRows(row arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<row> L(n1);
    vector<row> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (lessThan(L[i], R[j])) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(row arr[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeRows(arr, left, mid, right);
}

int main() {
    static row rows[502];

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        rows[i].sum = 0;
        for (int j = 1; j <= m; j++) {
            cin >> rows[i].elements[j];
            rows[i].sum += rows[i].elements[j];
        }
    }

    mergeSort(rows, 1, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << rows[i].elements[j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
