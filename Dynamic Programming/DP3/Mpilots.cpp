#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int, int>> pilots; // Store (captain_salary, assistant_salary) pairs
vector<vector<int>> dp; // Memoization table
int N;

// Recursive function to calculate minimum salary
int solve(int index, int captains) {
    // Base case: If all pilots are processed
    if (index == N) {
        return (captains == N / 2 and index - captains == N / 2) ? 0 : INT_MAX; // Valid if exactly N/2 captains assigned
    }

    // Check memoization
    if (dp[index][captains] != -1) {
        return dp[index][captains];
    }

    int result1 = INT_MAX;
    int result2 = INT_MAX;
    int assistants = index - captains; // Current number of assistants assigned

    if (assistants <=  captains) {
        result1 = pilots[index].second + solve(index + 1, captains); // Add assistant's salary
        return dp[index][captains] = result1;
    }

    else if(assistants > captains and assistants <= N/2) {
        if(assistants < N/2) result1 = min(result1, pilots[index].second + solve(index + 1, captains)); // Add assistant's salary
        result2 = min(result2, pilots[index].first + solve(index + 1, captains + 1)); // Add captain's salary
    }

    //if(result1 == INT_MAX and result2 == INT_MAX) return dp[index][captains] = 0;

    // Store the result in the DP table
    return dp[index][captains] = min(result1 , result2);
}

int main() {
    // Read the number of pilots
    cin >> N;
    pilots.resize(N);
    dp.assign(N + 1, vector<int>(N / 2 + 1, -1)); // Initialize DP table

    // Input salaries for each pilot
    for (int i = 0; i < N; i++) {
        cin >> pilots[i].first >> pilots[i].second; // Read captain and assistant salaries
    }

    // Start solving from the first pilot (index 0) with 0 captains assigned
    int result = solve(0, 0);

    // Output the minimal total salary required
    cout << result << endl;

    return 0;
}

