#include <iostream>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n, count =0, num =2; cin >> n;
    
    while(true){
        if (is_prime(num))
            count++;
        if (count ==n){
            cout << num << endl; break;}
        num++;
    }
    
}