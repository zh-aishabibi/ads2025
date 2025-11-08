#include <iostream>
#include <vector>

using namespace std;

int get_hash(string s) {
    int h = 0;
    int p = 29;
    int p_pow = 1;
    for (int i = 0; i < s.size(); i++) {
        h += s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}

vector<int> get_h(string s) {
    int n = s.size();
    vector<int> h(n);
    h[0] = s[0];
    int p = 29;
    int p_pow = 29;
    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}

vector<int> power(int n) {
    vector<int> p(n);
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] * 29;
    }
    return p;
}

int subst_hash(vector<int> &h, int l, int r) {
    int hash = h[r];
    if (l > 0) 
        hash -= h[l - 1];
    return hash;
} 

int main() {

    string s;
    cin >> s;
    int q;
    cin >> q;

    int n = s.size();
    vector<int> h = get_h(s);
    vector<int> p = power(n);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int sub_hash = subst_hash(h, l, r);
        int len = r - l + 1;

        int cnt = 0;
        for (int j = 0; j + len - 1 < n; j++) {
            int cur_hash = subst_hash(h, j, j + len - 1);
            if (cur_hash * p[l] == sub_hash * p[j])
                cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}