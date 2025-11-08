#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MAXN = 2002;
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll P1 = 31;
const ll P2 = 37;

vector<ll> h1(MAXN, 0), h2(MAXN, 0);
vector<ll> p1(MAXN, 1), p2(MAXN, 1);

pair<ll, ll> get_hash(int l, int r) {
    ll hash1 = (h1[r] - h1[l] * p1[r - l]) % MOD1;
    ll hash2 = (h2[r] - h2[l] * p2[r - l]) % MOD2;
    if (hash1 < 0) 
        hash1 += MOD1;
    if (hash2 < 0) 
        hash2 += MOD2;
    return make_pair(hash1, hash2);
}

int main() {
    for (int i = 1; i < MAXN; i++) {
        p1[i] = (p1[i - 1] * P1) % MOD1;
        p2[i] = (p2[i - 1] * P2) % MOD2;
    }

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] * P1 + (s[i] - 'a' + 1)) % MOD1;
        h2[i + 1] = (h2[i] * P2 + (s[i] - 'a' + 1)) % MOD2;
    }

    unordered_set<ull> unique_hashes;

    for (int length = 1; length <= n; length++) {
        for (int start = 0; start + length <= n; start++) {
            pair<ll, ll> p = get_hash(start, start + length);
            ull combined = ((ull)p.first << 32) | (ull)p.second;
            unique_hashes.insert(combined);
        }
    }

    cout << unique_hashes.size() << endl;
    return 0;
}