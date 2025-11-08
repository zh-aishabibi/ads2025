#include <bits/stdc++.h>
using namespace std;

string compute_hash(string s) {
    long long h = 0, p = 1;
    long long mod = 1000000007;

    for (char c : s) {
        h = (h + (c - 47) * p % mod) % mod;
        p = (p * 11) % mod;
    }

    return to_string(h);
}

int main() {
    int n;
    cin >> n;

    vector<string> v(2 * n);
    unordered_set<string> st;

    for (int i = 0; i < 2 * n; i++) {
        cin >> v[i];
        st.insert(v[i]);
    }

    int cnt = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (cnt == n) 
            break;
        string h = compute_hash(v[i]);
        if (st.count(h)) {
            cout << "Hash of string \"" << v[i] << "\" is " << h << endl;
            cnt++;
        }
    }

    return 0;
}