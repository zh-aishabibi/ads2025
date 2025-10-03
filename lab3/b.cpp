
#include <iostream>
#include <vector>
using namespace std;

bool feasible(vector<long long>& a, int n, int k, long long limit) {
    int blocks = 1;
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > limit) {
            return false;
        }
        if (cur + a[i] <= limit) {
            cur += a[i];
        }
        else {
            blocks++;
            cur = a[i];
            if (blocks > k) {
                return false;
            }
        }
    }
    return blocks <= k;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long sum = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    long long low = mx, high = sum;
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if(feasible(a, n, k, mid)) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}
