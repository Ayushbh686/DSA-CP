#include <bits/stdc++.h>
using namespace std;

void downHeapify(vector<int>& heap, int i) {
    int n = heap.size();
    
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largestIdx = i;

        if (l < n && heap[l] > heap[largestIdx]) {
            largestIdx = l;
        }
        if (r < n && heap[r] > heap[largestIdx]) {
            largestIdx = r;
        }

        if (largestIdx != i) {
            swap(heap[i], heap[largestIdx]);  // Swap to maintain heap property
            i = largestIdx;  // Move down the heap
        } else {
            break;  //  exit loop
        }
    }
}

void buildHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        downHeapify(heap, i);
    }
}

void mergePQ(vector<int>& heap1, vector<int>& heap2) {
    heap1.insert(heap1.end(), heap2.begin(), heap2.end());  // Merge vectors

    buildHeap(heap1);

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n1, n2;
        cin >> n1 >> n2;
        vector<int> heap1(n1), heap2(n2);

        for (int i = 0; i < n1; i++) {
            cin >> heap1[i];
        }
        for (int i = 0; i < n2; i++) {
            cin >> heap2[i];
        }

        mergePQ(heap1, heap2);

        for (int i = 0; i < n1 + n2; i++) {  
            cout << heap1[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
9

3 3
10 20 30
40 50 60

3 0
10 20 30

0 0

1 1
5
10

4 2
5 15 20 25
10 30

5 5
1 2 3 4 5
6 7 8 9 10

3 3
5 5 5
5 5 5

3 3
-10 -5 0
5 10 15

4 4
40 30 20 10
80 70 60 50
*/

/*
60 50 40 30 20 10
30 20 10
empty
10 5
30 25 20 10 15 5
10 9 8 7 6 5 4 3 2 1
5 5 5 5 5 5
15 10 5 0 -5 -10
80 70 60 50 40 30 20 10
*/