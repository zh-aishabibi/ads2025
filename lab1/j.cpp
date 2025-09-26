#include <iostream>
#include <deque>

using namespace std;

int main() {
    char c;
    deque<int> d;
    int n;
    
    while (true){
        cin >> c;
        if (c == '+'){
            cin >> n;
            d.push_front(n);
        }
        else if (c == '-'){
            cin >> n;
            d.push_back(n);
        }
        else if (c == '!'){
            return 0;
        }
            else if (c == '*') {
        if (d.empty()) {
            cout << "error" << endl;
        } else if (d.size() == 1) {
            cout << d.front() + d.front() << endl;
            d.pop_back();
        } else {
            cout << d.front() + d.back() << endl;
            d.pop_front();
            d.pop_back();
            }
        }
    }
    
}