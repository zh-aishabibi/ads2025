#include <iostream>
#include <vector>
using namespace std;

class maxHeap {
    public:
    vector<int> a;

    int getMax() {
        return a[0];
    }

    int parent(int i) {
        return (i - 1)/2;
    }

    int left(int i) {
        return 2*i + 1;
    }

    int right(int i) {
        return 2*i + 2;
    }

    void insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;

        while(ind > 0 && a[ind] > a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if(left(i) >= a.size()) {
            return;
        }

        int j = left(i);
        if(right(i) < a.size() && a[right(i)] > a[left(i)]) {
            j = right(i);
        }

        if(a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMax() {
        int root_value = getMax();

        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        if(a.size() > 0) {
            heapify(0);
        }

        return root_value;
    }

    int heap_size() {
        return a.size();
    }
};

int main() {
    int n, k;
    maxHeap *heap = new maxHeap();

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        heap->insert(val);
    }

    long long sum = 0;
    for(int i = 0; i < k; i++) {
        sum += heap->a[0];
        heap->a[0]--;
        if(heap->a[0] == 0) {
            heap->extractMax();
        } else 
            heap->heapify(0);
    }

    cout << sum << endl;

    return 0;
}