#include <iostream>
#include <vector>
using namespace std;

class minHeap {
    public:
    vector<long long> a;

    long long parent(long long i) {
        return (i - 1)/2;
    }

    long long left(long i) {
        return 2 * i + 1;
    }

    long long right(long long i) {
        return 2 * i + 2;
    }

    long long getMin() {
        return a[0];
    }

    void insert(long long k) {
        a.push_back(k);
        long long ind = a.size() - 1;

        while(a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(long long i) {
        if(left(i) > a.size() - 1) {
            return;
        } 

        long long j = left(i);
        if(right(i) < a.size() && a[right(i)] < a[left(i)]) {
            j = right(i);
        }

        if(a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    long long extractMin() {
        long long root_value = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        if(a.size() > 0) {
            heapify(0);
        }
        return root_value;
    }
};

int main() {

    long long n;
    cin >> n;
    vector <long long> sum_arr;

    minHeap *heap = new minHeap();

    for(long long i = 0; i < n; i++) {
        long long val;
        cin >> val;
        heap->insert(val);
    }

    while(heap->a.size() != 0) {
        long long b = heap->extractMin();
        if(heap->a.size() != 0) {
            long long c = heap->extractMin();
            sum_arr.push_back(b + c);
            heap->insert(b + c);
        }
    }

    long long sum = 0;

    for(long long i = 0; i < sum_arr.size(); ++i) {
        sum += sum_arr[i];
    }
    cout << sum << endl;

    return 0;
}