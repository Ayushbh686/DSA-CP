#include<iostream>
using namespace std;

void sortSwappedElements(int arr[], int n) {
    // Edge case: If array size is less than 2, no sorting is needed
    if (n < 2) {
        return;
    }

    int j = -1, k = -1; // Initialize indices for swapped elements

    // Find the first element (j) where arr[j] > arr[j+1]
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            j = i;
            break;
        }
    }

    // Find the second element (k) where arr[k] < arr[k-1]
    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            k = i;
            break;
        }
    }

    if (j == -1 || k == -1) {
        // If j or k is not found, array is already sorted
        return;
    }

    // Swap the misplaced elements to restore the sorted order
    swap(arr[j], arr[k]);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 6, 5, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortSwappedElements(arr, n);

    return 0;
}
