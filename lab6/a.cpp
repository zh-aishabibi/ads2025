#include <iostream>
#include <vector>

using namespace std;

bool is_vowel(char c) {
    return (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u');
}


void quick_sort(vector<char> &arr, int l, int r) {
    char p = arr[(l + r)/2];
    int i = l;
    int j = r;

    while(i <= j) {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if(l < j) {
        quick_sort(arr, l, j);
    }

    if(i < r)
        quick_sort(arr, i, r);
}

int main() {
    int n;
    cin >> n;
    vector<char> vowel;
    vector<char> consonant;
    for(int i = 0; i < n; i++) {
        char k; cin >> k;
        if(is_vowel(k)) {
            vowel.push_back(k);
        } else {
            consonant.push_back(k);
        }
    }

    if(vowel.size() != 0) {
        quick_sort(vowel, 0, vowel.size() - 1);
    }
    if(consonant.size() != 0) {
        quick_sort(consonant,0, consonant.size() - 1);
    }
    if(vowel.size() != 0) {
        for(int i = 0; i < vowel.size(); i++) {
            cout << vowel[i];
        }
    }

    if(consonant.size() != 0) {
        for(int i = 0; i < consonant.size(); i++) {
            cout << consonant[i];
        }
    }
    return 0;
}