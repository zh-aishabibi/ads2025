#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    char letter; cin >> letter;

    for(int i = 0; i < n; i++) {
        if (v[i] > letter) {
            cout << v[i]; 
            return 0;
        }
    }

    cout << v[0];
    return 0;
}