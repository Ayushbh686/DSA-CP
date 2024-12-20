#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class maxHeap {
private:
    vector<int> &heap; // Vector to store heap elements

public:
    maxHeap(vector<int>&v) {
        //O(N) calculate by solving AGP
        heap = v;
        for(int i=heap.size()/2 ; i>=0 ; i--){
            downHeapify(i , v.size());
        }
    }

    // Function to maintain the max-heap property from the root downwards
    void downHeapify(int idx , int bound) {    
        while (true) {
            int leftChild = 2 * idx + 1;
            int rightChild = 2 * idx + 2;
            int largest = idx;

            if (leftChild < bound && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < bound && heap[rightChild] > heap[largest]) {
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

    // Function to remove the highest priority element (root)
    void pop() {
        //O(logn)
        if (heap.empty()) return;

        // Swap the root with the last element and remove the last element
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();

        // Restore the max-heap property
        downHeapify(0 , heap.size()-1);
    }

    void popIdx(int idx){
        //O(logn) + O(logn) = O(logn)
        while(idx>0){
            int parent = (idx-1)/2;
            swap(heap[idx] , heap[parent]);
            idx = parent;
        }
        pop();
    }

    // Function to check if the heap is empty
    bool isEmpty() {
        return heap.size() == 0;
    }

    // Function to get the highest priority element (root)
    int peak() {
        //O(1)
        if (isEmpty()) return INT_MIN;
        else return heap[0];
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

void heapSort(vector<int> &v){
    maxHeap a(v);
    for(int i=v.size()-1 ; i>0 ; i--){
        swap(v[0] , v[i]);
        a.downHeapify(0 , i);
    }
    return;
}

int main(){
    vector<int> v = {9 , 6 , 1 , 19 , 3 , 2 , 8 , 12 , 5};
    heapSort(v);
    for(int i=0 ; i<v.size() ; i++) cout<<v[i]<<" ";
    cout<<endl;
    for(int i=0 ; i<v.size() ; i++) cout<<v[i]<<" ";
}
// identical to slection sort (you can build intutuion in it)