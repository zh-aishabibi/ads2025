#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> func (int n){
    vector<int> v(n+1);
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    int k = 1;
    while(k <=n){
        for (int i = 0; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        v[q.front()] = k;
        q.pop();
        k++;
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }

    return v;
}

int main() {
    int a;
	cin>> a;
	for (int i = 1; i <= a; i++) {
        int b;
        cin >> b;
        func(b);
        cout << endl;
    }
    return 0;
}