#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostRec(int ){

}

int minCost(int m, int n, vector<int> horizontal, vector<int> vertical) {
    sort(horizontal.begin(), horizontal.end(), greater<int>());  // Sort in descending order
    sort(vertical.begin(), vertical.end(), greater<int>());

    int cost = 0, h = 0, v = 0;
    int hrz = 1;  // Number of horizontal pieces
    int vrt = 1;  // Number of vertical pieces

    // Process both horizontal and vertical cuts
    while (h < m - 1 && v < n - 1) {
        if (horizontal[h] >= vertical[v]) {
            cost += horizontal[h] * vrt;
            hrz++;
            h++;
        } else {
            cost += vertical[v] * hrz;
            vrt++;
            v++;
        }
    }

    // Process remaining horizontal cuts
    while (h < m - 1) {
        cost += horizontal[h] * vrt;
        hrz++;
        h++;
    }

    // Process remaining vertical cuts
    while (v < n - 1) {
        cost += vertical[v] * hrz;
        vrt++;
        v++;
    }

    return cost;
}

int main() {
    vector<int> horizontal = {2, 1, 3, 1, 4};
    vector<int> vertical = {4, 1, 2};
    int m = horizontal.size() + 1;  // number of pieces is one more than number of cuts
    int n = vertical.size() + 1;    // same here

    cout << "Minimum Cost: " << minCost(m, n, horizontal, vertical) << endl;

    return 0;
}
