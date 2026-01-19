class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        string ans = "", currStr = "";
        int len = INT_MAX, curr = 0;

        while (j < n) {
            // 1) expand window on the right
            currStr += s[j];
            if (s[j] == '1') 
                curr++;

            // 2) once we have exactly k '1's, try to record & shrink
            if (curr == k) {
                // 2a) remove leading zeros (they don't change curr but shorten the window)
                while (i <= j && s[i] == '0') {
                    currStr.erase(0, 1);
                    i++;
                }
                // 2b) update answer
                int windowLen = j - i + 1;
                if (windowLen < len || (windowLen == len && currStr < ans)) {
                    len = windowLen;
                    ans = currStr;
                }
                // 2c) now remove the first '1' so curr goes back to k-1 and we can look for the next window
                currStr.erase(0, 1);
                curr--;
                i++;
            }

            // 3) always move right pointer
            j++;
        }

        return ans;
    }
};
