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
        return 2 * i + 2;
    }

    int getMin() {
        return a[0];
    }

    void insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;

        while(ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if(left(i) >= a.size()) {
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

    int extractMin() {
        int min_element = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        if(a.size() > 0)
            heapify(0);
        return min_element;
    }
};

int main() {
    int q, n;
    cin >> q >> n;
    minHeap *heap = new minHeap();

    long long sum = 0;
    for(int i = 0; i < q; i++) {
        string query;
        cin >> query;
        int cookies;
        int box = 0;

        if(query == "insert") { 
            cin >> cookies;
            if(heap->a.size() < n) {
                heap->insert(cookies);
                sum += cookies;
            } else {
                if(cookies > heap->getMin()) {
                    sum -= heap->getMin();
                    heap->extractMin();
                    heap->insert(cookies);
                    sum += cookies;
                }
            }
        } else {
            cout << sum << endl;
        }
    }
    return 0;
}