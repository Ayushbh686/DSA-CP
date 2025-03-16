#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long long num) {
    long long root = sqrt(num);
    return (root * root == num);
}

vector<int> generatePermutation(int n) {
    vector<int> perm(n);
    
    // Fill the array in reverse order: n, n-1, ..., 1
    iota(perm.rbegin(), perm.rend(), 1);
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += perm[i];

        // If the sum is a perfect square, try swapping
        if (isPerfectSquare(sum) && i + 1 < n) {
            swap(perm[i], perm[i + 1]);
            sum = 0;  // Reset sum and recalculate from beginning
            for (int j = 0; j <= i; j++) {
                sum += perm[j];
                if (isPerfectSquare(sum)) return {-1};  // Invalid case
            }
        }
    }

    return perm;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> result = generatePermutation(n);
        if (result[0] == -1) {
            cout << "-1\n";
        } else {
            for (int num : result) cout << num << " ";
            cout << "\n";
        }
    }
    return 0;
}
