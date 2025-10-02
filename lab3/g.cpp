#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool can_deliver(int children[], int flight, int island, int capacity) {
    int sum = 0;
    int flight_needed;
    for(int i = 0; i < island; i++) {
        flight_needed = ceil(double(children[i])/double(capacity));
        sum += flight_needed;
    }
    return sum <= flight;
}


int main() {
    int island, flight;
    cin >> island >> flight;
    int children[island];

    for(int i = 0; i < island; i++) {
        cin >> children[i];
    }

    int max = children[0];
    for(int i = 0; i < island; i++) {
        if(max < children[i]) {
            max = children[i];
        }
    }

    int low = 1, high = max;
    int result;
    while(low <= high) {
        int mid = (low + high)/ 2;
        if(can_deliver(children, flight, island, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;
}