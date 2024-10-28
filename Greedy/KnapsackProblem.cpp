#include <iostream>
#include <vector>
#include <algorithm>  // For sort
using namespace std;

// Comparator function to sort items by decreasing profit-to-weight ratio
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    double r1 = (p1.first * 1.0) / (p1.second * 1.0);  // Ratio for first item
    double r2 = (p2.first * 1.0) / (p2.second * 1.0);  // Ratio for second item
    return r1 > r2;  // Return true if first item has a higher ratio
}

// Function to calculate maximum profit for the fractional knapsack problem
double fractionalKnapsack(vector<int> &profits, vector<int> &weights, int n, int w) {
    vector<pair<int, int>> arr;  // Vector to store profit-weight pairs
    for (int i = 0; i < n; i++) arr.push_back({profits[i], weights[i]});
    
    // Sort items by profit-to-weight ratio
    sort(arr.begin(), arr.end(), cmp);

    double result = 0;  // Total profit
    int weight = 0;     // Current weight in the knapsack

    for (int i = 0; i < n; i++) {
        if (weight == w) return result;  // If the knapsack is full, return the result
        if (w - weight >= arr[i].second) {  // If the whole item can be added
            result += arr[i].first;  // Add the entire profit of the item
            weight += arr[i].second;  // Add the item's weight
        } else {  // If only part of the item can be added
            result += ((arr[i].first * 1.0) * ((w - weight) * 1.0)) / (arr[i].second * 1.0);
            break;  // Break since the knapsack is now full
        }
    }
    return result;  // Return total profit
}

int main() {
    vector<int> profits = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int n = 3;  // Number of items
    int w = 50;  // Maximum weight capacity of the knapsack

    cout << "Maximum profit: " << fractionalKnapsack(profits, weights, n, w) << endl;
    return 0;
}