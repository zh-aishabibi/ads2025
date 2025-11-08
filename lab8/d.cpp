#include <bits/stdc++.h>
using namespace std;

unsigned long long P = 131;

unsigned long long get_hash(string &s) {
    unsigned long long h = 0;
    for (char c : s) h = h * P + c;
    return h;
}

int main() {

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<string> patterns(n);
        for (int i = 0; i < n; i++) 
            cin >> patterns[i];
        string text;
        cin >> text;

        int N = text.size();
        vector<unsigned long long> h(N + 1, 0), p(N + 1, 1);
        for (int i = 0; i < N; i++) {
            h[i + 1] = h[i] * P + text[i];
            p[i + 1] = p[i] * P;
        }

        vector<int> freq(n, 0);
        for (int idx = 0; idx < n; idx++) {
            string &pat = patterns[idx];
            int m = pat.size();
            if (m > N) 
                continue;

            unsigned long long hash_pat = get_hash(pat);
            for (int i = 0; i + m <= N; i++) {
                unsigned long long sub_hash = h[i + m] - h[i] * p[m];
                if (sub_hash == hash_pat) 
                    freq[idx]++;
            }
        }

        int mx = *max_element(freq.begin(), freq.end());
        cout << mx << endl;
        for (int i = 0; i < n; i++)
            if (freq[i] == mx)
                cout << patterns[i] << endl;
    }
}