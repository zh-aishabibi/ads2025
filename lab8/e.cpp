#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void letter(vector<long long> &a) {
    for(int i = 0; i < a.size(); i++) {
        long long s = 97 + a[i]/pow(2, i);
        cout << char(s); 
    }
}

int main() {
    long long n; cin >> n;
    vector<long long> h(n);

    for(int i = 0; i < n; i++) 
        cin >> h[i];

    for (int i = n - 1; i > 0; i--) {
        h[i] = h[i] - h[i - 1];
    }

    letter(h);
    return 0;
}