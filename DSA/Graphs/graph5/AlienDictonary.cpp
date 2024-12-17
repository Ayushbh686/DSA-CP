/*
leetcode 269
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
*/
#include<bits/stdc++.h>
using namespace std;

// Dictionary of words from the alien language
vector<string> dict;
// Adjacency list to store the graph (a -> b means a < b)
vector<vector<int>> adj(26);
// Array to track in-degrees of each character
vector<int> inDeg(26, 0);
// Set to keep track of characters present in the dictionary
unordered_set<char> CharPresent;
// Total number of characters in the alphabet (fixed to 26 for lowercase Latin letters)
int s = 26;

// Function to perform topological sorting using Kahn's Algorithm
void KahnAlgoBFS() {
    queue<int> qu; // Queue for BFS
    unordered_set<int> visited; // Set to track visited nodes

    // Push nodes with in-degree 0 into the queue
    for (int i = 0; i < s; i++) {
        if (inDeg[i] == 0 && CharPresent.count((char)(i + 'a'))) {
            qu.push(i);
            visited.insert(i);
        }
    }

    // Process the graph in topological order
    while (!qu.empty()) {
        int top = qu.front();
        qu.pop();
        cout << (char)(top + 'a') << " "; // Output the character

        // Reduce in-degrees of neighbors and enqueue if they reach 0
        for (int ele : adj[top]) {
            inDeg[ele]--;
            if (inDeg[ele] == 0 && !visited.count(ele)) {
                qu.push(ele);
                visited.insert(ele);
            }
        }
    }
}

int main() {
    int n; // Number of words in the dictionary
    cin >> n;
    
    // Input the dictionary and record all unique characters
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (char ch : str) {
            CharPresent.insert(ch);
        }
        dict.push_back(str);
    }

    // Build the adjacency list and calculate in-degrees
    for (int i = 0; i < n - 1; i++) {
        int s1 = dict[i].size();
        int s2 = dict[i + 1].size();
        bool foundDifference = false; // Flag to check if a difference was found

        // Compare characters of two consecutive words
        for (int x = 0; x < min(s1, s2); x++) {
            if (dict[i][x] != dict[i + 1][x]) {
                adj[dict[i][x] - 'a'].push_back(dict[i + 1][x] - 'a'); // Add edge
                inDeg[dict[i + 1][x] - 'a']++; // Increment in-degree
                foundDifference = true;
                break; // Stop comparing after the first difference
            }
        }

        // Check for invalid lexicographical order (prefix issue)
        if (!foundDifference && s1 > s2) {
            cout << "Invalid dictionary order" << endl;
            return 0;
        }
    }

    // Perform topological sort and print the result
    KahnAlgoBFS();
    return 0;
}
