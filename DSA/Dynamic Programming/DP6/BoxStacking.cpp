// C++ program to implement
// box stacking problem
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum height 
// with box i as base.
int maxHeightRecur(int i, vector<vector<int>> &boxes,
                   vector<int> &memo) {
    
    // If value is memoized
    if (memo[i] != -1) return memo[i];
    
    int ans = boxes[i][2];
    
    // Check all the next boxes 
    for (int j=i+1; j<boxes.size(); j++) {
        
        // If size of box j is less than
        // size of box i.
        if (boxes[i][0]>boxes[j][0] && boxes[i][1]>boxes[j][1]){
            ans = max(ans, boxes[i][2] + maxHeightRecur(j, boxes, memo));
        }
    }
    
    return memo[i] = ans;
}

int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
    int n = height.size();
    
    // Create a 2d array to store all 
    // orientations of boxes in (l, b, h)
    // manner.
    vector<vector<int>> boxes;
    for (int i=0; i<n; i++) {
        int a = height[i], b = width[i],
        c = length[i];
        
        boxes.push_back({a, b, c});
        boxes.push_back({a, c, b});
        boxes.push_back({b, a, c});
        boxes.push_back({b, c, a});
        boxes.push_back({c, a, b});
        boxes.push_back({c, b, a});
    }
    
    // Sort the boxes in descending 
    // order of length and width.
    sort(boxes.begin(), boxes.end(), greater<vector<int>>());
    
    vector<int> memo(boxes.size(), -1);
    
    int ans = 0;
    
    // Check for all boxes starting as base.
    for (int i=0; i<boxes.size(); i++) {
        ans = max(ans, maxHeightRecur(i, boxes, memo));
    }
    
    return ans;
}

int main() {
    vector<int> height = {4,1,4,10};
    vector<int> width = {6,2,5,12};
    vector<int> length = {7,3,6,32};
    
    cout << maxHeight(height, width, length);
    return 0;
}
