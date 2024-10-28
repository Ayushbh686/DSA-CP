#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class maxHeap {
private:
    vector<int> heap; // Vector to store heap elements

public:
    maxHeap() {
        // Constructor initializes the heap vector
        // The line `vector<int> heap = this->heap;` is unnecessary and incorrect
        // as it would just create a local copy of the heap vector.
    }

    // Function to maintain the max-heap property from the root downwards
    void downHeapify() {
        int idx = 0;
        int size = heap.size();
        
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

    // Function to remove the highest priority element (root)
    void pop() {
        //O(logn)
        if (heap.empty()) return;

        // Swap the root with the last element and remove the last element
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();

        // Restore the max-heap property
        downHeapify();
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

int main() {
    maxHeap a;
    a.insert(3);
    a.insert(4);
    a.insert(11);
    a.insert(9);
    a.insert(14);
    a.insert(-1);
    a.insert(30);
    a.insert(44);
    a.insert(50);
    a.display();
    cout << a.peak() << endl;
    a.pop();
    a.display();
    cout << a.peak() << endl;
    a.popIdx(3);
    a.display();
    cout << a.peak() << endl;
    return 0;
}

// The heap is a binary tree but it's represented in the form of an array using BFS traversal.
// Therefore, every node at index i will have:
//   - Left child at index 2*i + 1
//   - Right child at index 2*i + 2
//   - Parent at index (i - 1) / 2

// A max-heap means every parent node has a greater value than its child nodes.
// Similarly, a min-heap means every parent node has a smaller value than its child nodes.
// Heaps are used to implement priority queues where operations are done according to priority.
// It is efficient to implement it as a binary tree where insertion is O(log n) and retrieving the max priority element is O(1).
