#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void merge(vector<string> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].size() <= R[j].size())
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSort(vector<string> &arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {

    int T;
    cin >> T;
    cin.ignore();

    for (int t = 0; t < T; t++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> words;
        string word;
        while (ss >> word)
            words.push_back(word);

        mergeSort(words, 0, (int)words.size() - 1);

        for (int i = 0; i < (int)words.size(); i++) {
            cout << words[i];
            if (i < (int)words.size() - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}