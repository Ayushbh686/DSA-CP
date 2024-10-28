//Minimum sum of two elements from two arrays
// Difficulty: BasicAccuracy: 25.62%Submissions: 6K+Points: 1
// Given two arrays a[] and b[] of same size.Your task is to find minimum sum of two elements such that they belong to different arrays and are not at same index in their arrays

class Solution {
public:
    int minSum(int a[], int b[], int n) {
        int minA = 0, min2A = -1;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[minA]) {
                min2A = minA;
                minA = i;
            } else if (min2A == -1 || a[i] < a[min2A]) {
                min2A = i;
            }
        }

        int minB = 0, min2B = -1;
        for (int i = 1; i < n; i++) {
            if (b[i] < b[minB]) {
                min2B = minB;
                minB = i;
            } else if (min2B == -1 || b[i] < b[min2B]) {
                min2B = i;
            }
        }

        // If the minimum indices are different, return their sum
        if (minA != minB) {
            return a[minA] + b[minB];
        }

        // If the minimum indices are the same, return the minimum of the two alternative sums
        int option1 = (min2A != -1) ? a[min2A] + b[minB] : INT_MAX;
        int option2 = (min2B != -1) ? a[minA] + b[min2B] : INT_MAX;

        return min(option1, option2);
    }
};