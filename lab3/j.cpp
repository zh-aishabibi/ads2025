#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool can_steal(int bars[], int H, int sumka, int steal) {
    int sum = 0;
    int hours_needed;
    for(int i = 0; i < sumka; i++) {
        hours_needed = ceil(double(bars[i])/double(steal));
        sum += hours_needed;
    }
    return sum <= H;
}


int main() {
    int sumka, H;
    cin >> sumka >> H;
    int bars[sumka];

    for(int i = 0; i < sumka; i++) {
        cin >> bars[i];
    }

    int max = bars[0];
    for(int i = 0; i < sumka; i++) {
        if(max < bars[i]) {
            max = bars[i];
        }
    }

    int low = 1, high = max;
    int result;
    while(low <= high) {
        int mid = (low + high)/ 2;
        if(can_steal(bars, H, sumka, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;
}