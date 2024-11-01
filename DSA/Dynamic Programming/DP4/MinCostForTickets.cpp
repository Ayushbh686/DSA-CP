/*
leetcode 983
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.
*/
class Solution {
public:
    int n;
    vector<long long int> dp;

    long long int fUpDown(vector<int>& days, vector<int>& costs, int i) { //dp i sotres mincost for ith to lats given day
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        // Calculate minimum cost by choosing each type of pass
        long long int oneDayPass = costs[0] + fUpDown(days, costs, i + 1);

        int j = i;
        while (j < n && days[j] < days[i] + 7) j++;
        long long int sevenDayPass = costs[1] + fUpDown(days, costs, j);

        j = i;
        while (j < n && days[j] < days[i] + 30) j++;
        long long int thirtyDayPass = costs[2] + fUpDown(days, costs, j);

        // Store and return the minimum of the three choices
        return dp[i] = min({oneDayPass, sevenDayPass, thirtyDayPass});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //top down
        // n = days.size();
        // dp.clear();
        // dp.resize(n, -1);
        // return fUpDown(days, costs, 0);



        //bottom up (true tabulation as only time time dp value finalised)
        n = days.size()-1;
        dp.resize(n+2, -1); //dp i sotres mincost for ith to lats given day
        dp[n+1]=0;

        for(int i=n;i>=0;i--)
        {
            //1day
            int cost1 = costs[0] + dp[i+1];

            //7days
            int endDayof7=days[i] + 7 - 1;
            int currDayfor7 = i;
            while(currDayfor7<days.size() && days[currDayfor7] <= endDayof7)
                currDayfor7++;
            int cost7=costs[1] + dp[currDayfor7];

            //30days
            int endDayof30=days[i] + 30 - 1;
            int currDayfor30=i;
            while(currDayfor30<days.size() && days[currDayfor30] <= endDayof30)
                currDayfor30++;
            int cost30=costs[2] + dp[currDayfor30];

            dp[i] = min(cost1, min(cost7, cost30));
        }

        return dp[0];


        //bottom up ( in this one a dp value is updated many times in array so not a one time tabulation as dp i gives mincost for 0 to ith day given in array)
        // n = days.size();
        // dp.resize(n + 1 , INT_MAX);  // dp[i] stores the min cost to cover up to day `days[i]`
        // dp[0] = 0;  // No cost for no days

        // for (int i = 0; i < n; i++) {
        //     // 1-day pass
        //     dp[i + 1] = min(dp[i + 1], dp[i] + costs[0]);

        //     // 7-day pass
        //     int j = i;
        //     while (j < n && days[j] < days[i] + 7) j++;
        //     dp[j] = min(dp[j], dp[i] + costs[1]);

        //     // 30-day pass
        //     j = i;
        //     while (j < n && days[j] < days[i] + 30) j++;
        //     dp[j] = min(dp[j], dp[i] + costs[2]);
        // }

        // return dp[n];

    }
};
