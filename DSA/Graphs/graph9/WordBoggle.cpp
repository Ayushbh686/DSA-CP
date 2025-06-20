#include <bits/stdc++.h>
using namespace std;

// function to perform dfs on the grid
bool dfs(vector<vector<char>>& letters, 
        string word, int i, int j, int index) {

    // check if the current cell is out of bounds
    if (i < 0 || i >= letters.size() || j < 0 || j >= letters[0].size()) {
        return false;
    }
    
    // check if the current cell matches 
    // the character in the word
    if (letters[i][j] != word[index]) {
        return false;
    }
    
    // check if we have found the complete word
    if (index == word.size() - 1) {
        return true;
    }
    
    // mark the current cell as visited
    char temp = letters[i][j];
    letters[i][j] = '#';
    
    // perform dfs on all 8 directions
    for(int row = -1; row <= 1; row++) {
        for (int col = -1; col <= 1; col++) {

            // skip the current cell
            if (row == 0 && col == 0) continue; 
            if (dfs(letters, word, i + row, j + col, index + 1)) {

                // unmark the current cell as visited
                letters[i][j] = temp;
                return true;
            }
        }
    }
    
    // unmark the current cell as visited
    letters[i][j] = temp;
    
    return false;
}

// find all words in a given grid of characters
// and a given dictionary
vector<string> findWords(vector<string>& words, 
                    vector<vector<char>>& letters) {
    int n = letters.size(), m = letters[0].size();
    int r = words.size();
    vector<string> ans;
    
    // store the unique words in the hashSet
    unordered_set<string> result;
                        
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(dfs(letters, words[i], j, k, 0)) {
                    result.insert(words[i]);
                }
            }
        }
    }

    // convert the set to vector
    for(auto word : result) {
        ans.push_back(word);
    }
    return ans;
}

int main() {
    vector<string> words = {"geeks", "for", "quiz", "go"};
    vector<vector<char>> letters = {
        {'g', 'i', 'z'},
        {'u', 'e', 'k'},
        {'q', 's', 'e'}
    };
    vector<string> ans = findWords(words, letters);
    for (string word : ans) {
        cout << word << " ";
    }
    return 0;
}