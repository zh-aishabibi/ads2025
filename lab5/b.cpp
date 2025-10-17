#include <iostream>
#include <vector>
using namespace std;

int abs(int a) {
    if(a < 0) {
        a = 0 - a;
    }
    return a;

}

class maxHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1)/2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMax() {
        return a[0];
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
        if(left(i) > a.size() - 1) {
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
        int max_element = getMax();

        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if(a.size() > 0) {
            heapify(0);
        }
        return max_element;
    }
};

int main() {

    maxHeap *heap = new maxHeap();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        heap->insert(k);
    }

    while(heap->a.size() >= 2) {
        int x = heap->extractMax();
        if(heap->a.size() > 0) {
            int y = heap->extractMax();
            int z = abs(x - y);
            heap->insert(z);
        }
    }

    cout << heap->extractMax() << endl;
    return 0;
}