#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> ages(n);
    for (int i = 0; i < n; i++) cin >> ages[i];
    stack<int> s;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= ages[i]) s.pop();
        if (s.empty()) result[i] = -1;
        else result[i] = s.top();
        s.push(ages[i]);
    }

    for (int i = 0; i < n; i++) cout << result[i] << " ";
    cout << "\n";

    return 0;
}
