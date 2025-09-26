#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes;
    int num = 2;
    while (primes.size() <= 1000) { 
        if (isPrime(num)) primes.push_back(num);
        num++;
    }
    
    vector<int> superprimes;
    for (int i = 0; i < (int)primes.size(); i++) {
        if (isPrime(i + 1)) { 
            superprimes.push_back(primes[i]); 
        }
    }
    
    cout << superprimes[n - 1];

    return 0;
}