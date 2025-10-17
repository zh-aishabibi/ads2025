#include <iostream>
#include <vector>
using namespace std;

class minHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1)/2;
    }

    int left(int i) {
        return 2*i + 1;
    }

    int right(int i) {
        return 2*i + 2;
    }

    int getMin() {
        return a[0];
    }

    int heap_size() {
        return a.size();
    }

    void insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;

        while(a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if(left(i) > a.size() - 1) {
            return;
        }

        int j = left(i);
        if(right(i) < a.size() && a[right(i)] < a[left(i)]) {
            j = right(i);
        }

        if(a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    bool empty() {
        return heap_size() == 0;
    }

    int extractMin() {
        int min_element = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        if(a.size() > 0) {
            heapify(0);
        }
        return min_element;
    }
};

int main() {

    minHeap *heap = new minHeap();
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        heap->insert(d);
    }

    int moves = 0;
    while(heap->getMin() < k && !heap->empty()) {
        int x = heap->extractMin();
        if(heap->heap_size() > 0) {
            int y = heap->extractMin();
            int z = x + 2 * y;
            heap->insert(z);
            moves++;
        } else {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << moves << endl;
    return 0;
}