#include <iostream>
#include <queue>

using namespace std;

int main() {
    int nur,bor;
	queue<int> n;
	queue<int> b;
	
	for (int i = 0; i < 5; i++) {
        cin >> bor;
        b.push(bor);
    }

    for (int i = 0; i < 5; i++) {
        cin >> nur;
        n.push(nur);
    }
    
	int k = 0;
	while (!b.empty() && !n.empty() && k < 1000000 ){
	    int o = b.front();
	    int u = n.front();
	    if (b.front() == 0 && n.front() == 9) {
            b.push(b.front());
            b.push(n.front());
        } else if (n.front() == 0 && b.front() == 9) {
            n.push(b.front());
            n.push(n.front());
        }
	    else if (b.front() > n.front()) {
            b.push(b.front());
            b.push(n.front());
        } else {
            n.push(b.front());
            n.push(n.front());
        }
	    b.pop();
        n.pop();
	    k++;
	}
	
	if (k == 1000000){
	    cout << "blin nichya";
	    return 0;
	}
	
	if (n.empty()){
	    cout << "Boris" << " " << k;
	}
	else {
	    cout << "Nursik" << " " << k;
	}

}