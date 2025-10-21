#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<string> &v, int left, int right) {
    int i = left;
    int j = right;
    string p = v[(left + right)/2];

    while(i <= j) {
        while(v[i] < p) i++;
        while(v[j] > p) j--;

        if(i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    if(left < j) quick_sort(v, left, j);
    if(i < right) quick_sort(v, i, right);
}


int main() {
    int n;
    cin >> n;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string key = s.substr(6, 4) + s.substr(3, 2) + s.substr(0, 2);
        string combined = key + " " + s;
        v.push_back(combined);
    }

    quick_sort(v, 0, n - 1);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].substr(9) << endl;
    }

    return 0;
}