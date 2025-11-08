#include <vector>
#include <iostream>
using namespace std;

int get_hash(string s) {
    int n = s.size();
    int h = 0;
    int p = 29;
    int p_pow = 1;
    for (int i = 0; i < n; i++) {
        h += s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}

vector<int> get_h(string s) {
    int p = 29;
    int p_pow = 29;
    int n = s.size();
    vector<int> h(n);
    h[0] = s[0];
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

int get_substr_hash(vector<int> &h, int l, int r) {
    int hash = h[r];
    if (l > 0) 
        hash = hash - h[l - 1];
    return hash;
}

int min(int a, int b) {
    if (a > b) 
        return b;
    return a;
}

int main() {

    string s1, s2, parasite;
    cin >> s1 >> s2 >> parasite;

    int hash_parasite = get_hash(parasite);
    
    vector<int> h1 = get_h(s1);
    vector<int> h2 = get_h(s2);
    int n = s1.size();
    int m = s2.size();
    int min_size = min(n, m);
    vector<int> p = power(min_size);
    int k = parasite.size();

    int count = 0;

    for (int i = 0; i + k <= min_size; i++) {
        int j = i + k - 1;
        int hash_1 = get_substr_hash(h1, i, j);
        int hash_2 = get_substr_hash(h2, i, j);

        if(hash_parasite * p[i] == hash_1 && hash_parasite * p[i] == hash_2) {
            count++;
        }
    }
    cout << count;
    return 0;
}