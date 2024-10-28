#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class maxHeap {
private:
    vector<int> heap; // Vector to store heap elements
    int i;

public:
    maxHeap(vector<int>&v) {
        heap = v;
        this->i = 0;
        for(i=0 ; i<v.size() ; i++){
            upHeapify(i);
        }
    }

    // Function to maintain the max-heap property from a given index upwards
    void upHeapify(int idx) {
        int parentIdx = (idx - 1) / 2;
        while (idx > 0 && heap[idx] > heap[parentIdx]) {
            swap(heap[idx], heap[parentIdx]);
            idx = parentIdx;
            parentIdx = (idx - 1) / 2;
        }
    }

    // Function to insert a new value into the heap
    void insert(int val) {
        //O(Logn)
        heap.push_back(val);
        upHeapify(heap.size() - 1);
    }

    // Function to display the heap
    void display() {
        cout << "[";
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    vector<int> v = {9 , 6 , 1 , 19 , 3 , 2 , 8 , 12 , 5};
    maxHeap a(v);
    a.display();
    a.insert(100);
    a.display();
    return 0;
    //O(N LOGN) as n times upheapify
}
//alternate way is to make it directly sort as every sorted array is heap but not vice versa
