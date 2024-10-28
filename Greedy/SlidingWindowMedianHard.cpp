/*
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
*/

class Solution {
public:
    double getMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, int k) {
        if (k % 2 == 0) {
            return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
        } else {
            return (double)maxHeap.top();
        }
    }

    void balanceHeaps(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, int &actualSizeL, int &actualSizeR) {
        while (actualSizeL > actualSizeR + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            actualSizeL--;
            actualSizeR++;
        }
        while (actualSizeR > actualSizeL) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            actualSizeR--;
            actualSizeL++;
        }
    }

    // Prune function for max-heap
    void prune(priority_queue<int>& heap, unordered_map<int, int>& mp) {
        while (!heap.empty() && mp[heap.top()]) {
            mp[heap.top()]--;
            heap.pop();
        }
    }

    // Prune function for min-heap
    void prune(priority_queue<int, vector<int>, greater<int>>& heap, unordered_map<int, int>& mp) {
        while (!heap.empty() && mp[heap.top()]) {
            mp[heap.top()]--;
            heap.pop();
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        unordered_map<int, int> mp;  // Map for lazy deletion
        priority_queue<int> maxHeap;  // Max-heap for the smaller half
        priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap for the larger half
        int actualSizeL = 0, actualSizeR = 0;  // Actual sizes of maxHeap and minHeap

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            if (maxHeap.empty() || nums[i] <= maxHeap.top()) {
                maxHeap.push(nums[i]);
                actualSizeL++;
            } else {
                minHeap.push(nums[i]);
                actualSizeR++;
            }
        }

        // Balance the heaps after the first window is initialized
        balanceHeaps(maxHeap, minHeap, actualSizeL, actualSizeR);

        // Add the first median
        ans.push_back(getMedian(maxHeap, minHeap, k));

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            int outElem = nums[i - k], inElem = nums[i];

            // Insert the new element based on comparison with current median
            double median = getMedian(maxHeap, minHeap, k);
            if (inElem <= median) {
                maxHeap.push(inElem);
                actualSizeL++;
            } else {
                minHeap.push(inElem);
                actualSizeR++;
            }

            // Handle the outgoing element
            if (outElem <= maxHeap.top()) {
                actualSizeL--;
                if (outElem == maxHeap.top()) {
                    maxHeap.pop();
                } else {
                    mp[outElem]++;
                }
            } else {
                actualSizeR--;
                if (outElem == minHeap.top()) {
                    minHeap.pop();
                } else {
                    mp[outElem]++;
                }
            }

            // Balance the heaps after inserting and handling the outgoing element
            balanceHeaps(maxHeap, minHeap, actualSizeL, actualSizeR);

            // Prune the heaps for lazy deletion
            prune(maxHeap, mp);
            prune(minHeap, mp);

            balanceHeaps(maxHeap, minHeap, actualSizeL, actualSizeR);

            // Add the current median
            ans.push_back(getMedian(maxHeap, minHeap, k));
        }

        return ans;
    }
};
