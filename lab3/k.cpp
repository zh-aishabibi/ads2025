#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int p[n];
    p[0] = 0;
    for(int i = 1; i < n + 1; i++) {
        p[i] = p[i - 1] + arr[i - 1];
    }

    int ans = n + 1;

    for(int i = 1; i <= n; i++) {
        int target = k + p[i - 1];

        int low = i, high = n;
        int r = n + 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(p[mid] >= target) {
                r = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(r <= n) {
            ans = min(ans, r-(i-1));
        }
    }

    cout << ans << endl;
    return 0;
}