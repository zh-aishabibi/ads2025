#include <iostream>
#include <vector>

using namespace std;

int abs(int a) {
    if (a < 0) {
        return 0 - a;
    }
    return a;
}

void quick_sort(vector<long long> &v, int left, int right) {
    int i = left;
    int j = right;
    long long p = v[(right + left) / 2];

    while(i <= j) {
        while (v[i] < p) i++;
        while (v[j] > p) j--;

        if(i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (left < j) quick_sort(v, left, j);
    if (i < right) quick_sort(v, i, right);
}

int main() {
    int n;
    cin >> n;
    vector<long long> vec(n);
    vector<long long> difference;

    for (int i = 0; i < n; i++) cin >> vec[i];

    quick_sort(vec, 0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        difference.push_back(abs(vec[i] - vec[i + 1]));
    }

    long long min = difference[0];
    for(int i = 1; i < n - 1; i++) {
        if (min > difference[i]) min = difference[i];
    }

    for(int i = 0; i < n - 1; i++) {
        if(difference[i] == min) {
            cout << vec[i] << " " << vec[i + 1] << " ";
        }
    }

    return 0;
}