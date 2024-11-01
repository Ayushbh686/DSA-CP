#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class maxHeap {
private:
    vector<int> heap; // Vector to store heap elements

public:
    maxHeap(vector<int>&v) {
        heap = v;
        for(int i=heap.size()/2 ; i>=0 ; i--){
            downHeapify(i);
        }
    }

    // Function to maintain the max-heap property from the root downwards
    void downHeapify(int idx) {
        int size = heap.size()-1;
        while (true) {
            int leftChild = 2 * idx + 1;
            int rightChild = 2 * idx + 2;
            int largest = idx;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != idx) {
                swap(heap[idx], heap[largest]);
                idx = largest;
            } else {
                break;
            }
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
    //O(N) calculate by solving AGP
}
//alternate way is to make it directly sort as every sorted array is heap but not vice versa
