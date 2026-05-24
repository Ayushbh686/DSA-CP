class Solution {
public:

    vector<int> maxOfMins(vector<int>& arr) {

        int n = arr.size();

        // prev[i]  = index of Previous Smaller Element
        // next[i]  = index of Next Smaller Element
        //
        // If no previous smaller exists -> -1
        // If no next smaller exists -> n
        vector<int> prev(n, -1);
        vector<int> next(n, n);

        // res[len] = maximum among all minimums
        // for window size = len
        //
        // We use n+1 because window sizes are from 1 to n
        // and we ignore index 0 later.
        vector<int> res(n + 1, INT_MIN);

        stack<int> stk;

        /*
        =========================================================
                        PREVIOUS SMALLER ELEMENT
        =========================================================

        Monotonic Increasing Stack

        For every element:
        Remove all greater/equal elements because they can never
        become previous smaller for future elements.

        After popping:
        stack top = nearest smaller element on left
        */

        for(int i = 0; i < n; i++) {

            // Remove all elements >= current element
            while(!stk.empty() && arr[i] <= arr[stk.top()]) {
                stk.pop();
            }

            // If stack not empty,
            // top is previous smaller index
            if(!stk.empty()) {
                prev[i] = stk.top();
            }

            // Push current index
            stk.push(i);
        }

        // Clear stack for next smaller calculation
        while(!stk.empty()) stk.pop();


        /*
        =========================================================
                          NEXT SMALLER ELEMENT
        =========================================================

        Same idea, but traverse from right to left.

        After popping:
        stack top = nearest smaller element on right
        */

        for(int i = n - 1; i >= 0; i--) {

            // Remove all elements >= current element
            while(!stk.empty() && arr[i] <= arr[stk.top()]) {
                stk.pop();
            }

            // Stack top = next smaller index
            if(!stk.empty()) {
                next[i] = stk.top();
            }

            stk.push(i);
        }


        /*
        =========================================================
                        MAIN OBSERVATION
        =========================================================

        Instead of checking every window,
        we ask:

        "For how large a window can arr[i]
         remain the minimum element?"

        Using:
            previous smaller
            next smaller

        arr[i] stays minimum in range:

            (prev[i] + 1) to (next[i] - 1)

        Therefore maximum window length:

            len = next[i] - prev[i] - 1

        Meaning:
        arr[i] can act as minimum for a window
        of size = len

        So:
        res[len] = max(res[len], arr[i])
        */

        for(int i = 0; i < n; i++) {

            int winSize = next[i] - prev[i] - 1;

            res[winSize] = max(res[winSize], arr[i]);
        }


        /*
        =========================================================
                        FILL EMPTY ANSWERS
        =========================================================

        Some window sizes may remain unfilled.

        Important observation:

        If a number can be minimum for a larger window,
        then it can ALSO be minimum for all smaller windows.

        So propagate answers backwards.

        Example:

            res[5] = 10

        then window sizes 4,3,2,1
        can also at least have value 10.
        */

        for(int i = n - 1; i >= 1; i--) {

            res[i] = max(res[i], res[i + 1]);
        }

        // Remove dummy index 0
        res.erase(res.begin());

        return res;
    }
};



//same approach just single pass if dont understand use chatgpt
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> maxOfMin(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n), len(n + 1, 0);
    stack<int> st;

    // find window sizes for each element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            int top = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int right = i;
            int windowSize = right - left - 1;
            len[windowSize] = max(len[windowSize], arr[top]);
        }
        st.push(i);
    }

    // process remaining elements in stack
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int right = n;
        int windowSize = right - left - 1;
        len[windowSize] = max(len[windowSize], arr[top]);
    }

    for (int i = 1; i <= n; i++) {
        res[i - 1] = len[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    return res;
}

int main() {
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> res = maxOfMin(arr);
    for (int val : res) cout << val << " ";
    cout << endl;
    return 0;
}

*/