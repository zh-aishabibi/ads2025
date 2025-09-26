#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
	int n;
	cin >> n;
	
	if (is_prime(n) == true)
	    cout << "YES";
	else
	    cout << "NO";
	
	
	return 0;
}