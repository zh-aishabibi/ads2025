#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l_bound(vector<int> &arr, int x) {
    int low = 0, high = arr.size();
    while(low < high) {
        int mid = low + (high - low)/2;
        if(arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int r_bound(vector<int> &arr, int x) {
    int low = 0, high = arr.size();
    while(low < high) {
        int mid = low + (high - low)/2;
        if(arr[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int count_in_range(vector<int> &vec, int L, int R) {
    if(L > R) {
        return 0;
    }
    int left = l_bound(vec, L);
    int right = r_bound(vec, R);
    return right - left;
}

int main() {
     int sz, q;
    cin >> sz >> q;
    vector<int> vec(sz);

    for(int i = 0; i < sz; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    
    int l1, r1, l2, r2;
    for(int i = 0; i < q; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        
        int count1 = count_in_range(vec, l1, r1);
        int count2 = count_in_range(vec, l2, r2);
        
        int L = max(l1, l2), R = min(r1, r2);
        int overlap = count_in_range(vec, L, R);

        cout << count1 + count2 - overlap << endl;
    }
   
}