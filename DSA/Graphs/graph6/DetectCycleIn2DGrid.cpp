
/*
leetcode 1559
Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.

 
*/

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
//its not valid to create set for hash or pair so we made custom hash function
class Solution {
public:
    int m , n;
    std::unordered_set< std::pair<int, int>,  pair_hash> visited;

    bool dfsVisit(int i , int j , int pari , int parj ,vector<vector<char>>& grid){
        visited.insert({i,j});
        vector<vector<int>> dir = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};

        for(auto dr : dir){
            int newi = i + dr[0];
            int newj = j + dr[1];
            if(newi >= 0 and newi < m and newj >= 0 and newj < n and grid[i][j] == grid[newi][newj]){
                if(visited.count({newi,newj}) and pari != newi and parj != newj){
                    return true;
                }
                else if(!visited.count({newi,newj})){
                    bool b = dfsVisit(newi , newj , i , j , grid);
                    if(b) return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(!visited.count({i,j})){
                    bool b = dfsVisit(i,j,-1,-1,grid);
                    if(b) return true;
                }
            }
        }
        return false;
    }
};
//we used detect cycle by dfs