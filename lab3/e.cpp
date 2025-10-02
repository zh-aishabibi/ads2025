#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int x1[200000], y1[200000], x2[200000], y2[200000];
    int max_coord = 0;

    for(int i = 0; i < N; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        max_coord = max({max_coord, x2[i], y2[i]});
    }

    int low = 0, high = max_coord;

    while(low < high) {
        int mid = (low + high) / 2;
        int count = 0;
        for(int i = 0; i < N; i++) {
            if(x2[i] <= mid && y2[i] <= mid)
                count++;
        }

        if(count >= K)
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << endl;
}