#include<iostream>
using namespace std;

int main() {
    int arr[] = {2, -3, 4, 4, -7, -1, 4, -2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int p = -1;

    // Find the first negative number in the first k elements
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            p = i;
            break;
        }
    }

    int res[n - k + 1];

    // Initialize the result for the first window
    if (p != -1) {
        res[0] = arr[p];
    } else {
        res[0] = 0; // If no negative number is found, initialize with 0
    }

    int i = 1, j = k;

    // Sliding window logic
    while (j < n) {
        if (p >= i) {
            res[i] = arr[p];
        } else {
            p = -1; // Reset p to find the next negative number
            for (int m = i; m <= j; m++) {
                if (arr[m] < 0) {
                    p = m;
                    break;
                }
            }
            if (p != -1) {
                res[i] = arr[p];
            } else {
                res[i] = 0; // If no negative number is found, initialize with 0
            }
        }
        i++;
        j++;
    }

    // Output the result
    for (int i = 0; i < n - k + 1; i++) {
        cout << res[i] << " ";
    }
}
