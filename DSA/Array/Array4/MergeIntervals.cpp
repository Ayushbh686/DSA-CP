class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Sort the intervals based on the start times.
        // If two intervals have the same start time, sort by end time.
        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) -> bool {
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
        });

        vector<vector<int>> ans; // To store the merged intervals
        int i = 0;

        // Iterate through each interval
        while (i < n) {
            vector<int> temp(2);
            temp[0] = intervals[i][0]; // Start of the new merged interval
            int maxEnd = intervals[i][1]; // End of the new merged interval

            // Check if the current interval can be merged with the next one (if next interval starts before the maxtime of previous interval)
            while (i < n - 1 && maxEnd >= intervals[i + 1][0]) {
                i++;
                maxEnd = max(maxEnd, intervals[i][1]); // Extend the end if the next interval is overlapping
            }

            temp[1] = maxEnd; // Finalize the end of the merged interval
            ans.push_back(temp); // Add the merged interval to the result
            i++;
        }

        return ans;
    }
};
