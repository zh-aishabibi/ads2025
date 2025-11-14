#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <string>
using namespace std;

bool less_student(pair<pair<string, string>, double> &a, pair<pair<string, string>, double> &b) {
    if (a.second != b.second) return a.second < b.second;
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}

void merge(vector<pair<pair<string, string>, double>> &v, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<pair<pair<string, string>, double>> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = v[left + i];
    for (int j = 0; j < n2; j++) R[j] = v[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (less_student(L[i], R[j]))
            v[k++] = L[i++];
        else
            v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}

void merge_sort(vector<pair<pair<string, string>, double>> &v, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    string name, surname;
    vector<pair<pair<string, string>, double>> student;
    for (int i = 0; i < n; i++) {
        double gpa = 0;
        int overall = 0;
        cin >> surname >> name;
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            string mark;
            int mark_count;
            cin >> mark >> mark_count;
            overall += mark_count;
            if (mark == "A") gpa += mark_count * 3.75;
            else if (mark == "A+") gpa += mark_count * 4.00;
            else if (mark == "B+") gpa += mark_count * 3.50;
            else if (mark == "B") gpa += mark_count * 3.00;
            else if (mark == "C+") gpa += mark_count * 2.50;
            else if (mark == "C") gpa += mark_count * 2.00;
            else if (mark == "D+") gpa += mark_count * 1.50;
            else if (mark == "D") gpa += mark_count * 1.00;
            else gpa += mark_count * 0.00;
        }
        gpa = gpa / overall;
        student.push_back(make_pair(make_pair(surname, name), gpa));
    }

    merge_sort(student, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(3)
             << student[i].first.first << " "
             << student[i].first.second << " "
             << student[i].second << endl;

    return 0;
}