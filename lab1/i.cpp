#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> k;
    queue<int> s;
    
    char c; int n; cin >> n;
    
    for (int i=0; i < n; i++){
        cin >> c;
        if (c=='K') k.push(i);
        else s.push(i);
    }
    int pos =n;
    while(!k.empty() && !s.empty()){
        if (k.front() < s.front()){
            s.pop(); k.pop();
            k.push(pos);
        }
        else {
            s.pop(); k.pop();
            s.push(pos);
        }
        pos++;
    }
    if (k.empty()){
        cout << "SAKAYANAGI";
    }
    else 
    cout << "KATSURAGI";
    
}