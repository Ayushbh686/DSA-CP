//binary search on answer


// C++ program to find the minimum time for
// painter's partition problem using Binary Search.
#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to 
// paint all boards by k painters such that no 
// painter paints  more than maxTime
bool isPossible(int maxTime, vector<int> &arr, int k) {

    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < arr.size(); i++) {

        // If a single board exceeds maxTime,
        // return false
        if (arr[i] > maxTime) {
            return false;
        }

        // If adding current board exceeds 
        // limit, assign to next painter
        if (currSum + arr[i] > maxTime) {
            painters++;
            currSum = arr[i];
        } else {
            currSum += arr[i];
        }
    }

    // Return true if total painters used is <= k
    return painters <= k;
}

int minTime(vector<int> &arr, int k) {

    int n = arr.size();

    // Find the maximum board length manually
    int maxBoard = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxBoard) {
            maxBoard = arr[i];
        }
    }

    // Find the sum of all board lengths manually
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Apply Binary Search between 
    // maxBoard and totalSum
    int low = maxBoard;
    int high = totalSum;
    int res = totalSum;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If it is possible with max workload as mid
        if (isPossible(mid, arr, k)) {
            res = mid;
            
            // try to minimize further
            high = mid - 1; 
        } else {
            
             // need more time
            low = mid + 1; 
        }
    }

    return res;
}

int main() {
    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;
    int res = minTime(arr, k);
    cout << res << endl;

    return 0;
}

//can also be done using dp 