class Solution {
    public:
        bool check(long long spd, vector<int>& piles, int h) {
        int n = piles.size();
        long long t = 0;
        for (int i = 0; i < n; i++) {
            if (piles[i] == 0)
                continue; // Skip piles with zero elements
            long long div = (long long)piles[i] / spd;
            if ((div * spd) < piles[i]) // Adding 1 if remainder exists
                t++;
            t += div;
        }
        return t <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if (n == 0) return 0; // Edge case: empty piles
        long long sum = 0; // Using long long to handle potential overflow
        int maxm = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += piles[i];
            maxm = max(piles[i], maxm);
        }
        if (h >= sum) return 1; // Edge case: enough hours to eat all piles
        long long lo = 1;
        long long hi = maxm;
        int ans = -1; // Default value
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(mid, piles, h)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
        }
    };