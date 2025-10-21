#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<char> &v, int left, int right) {
    int i = left;
    int j = right;

    char p = v[(left + right) / 2];

    while(i <= j) {
        while(v[i] < p) i++;
        while (v[j] > p) j--;

        if(i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    if(left < j) quick_sort(v, left, j);
    if (right > i) quick_sort(v, i, right);
}

int main() {
    string word;
    cin >> word;

    vector<char> v(word.begin(), word.end());

    quick_sort(v, 0, v.size() - 1);

    for(int i = 0; i < v.size(); i++) 
        cout << v[i];
}