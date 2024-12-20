/*
leetcode 695
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/

class Solution {
public:

    int m , n , maxArea = 0;
    // vector<vector<int>> visited;

    int dfsVisit(int i , int j , vector<vector<int>>& grid){
        if(i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        vector<vector<int>> dir = { {0,1} , {0,-1} , {1,0} , {-1,0} };

        int area = 1;
        for(auto ele : dir){
            int newi = i + ele[0];
            int newj = j + ele[1];
            area += dfsVisit(newi , newj , grid);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // visited.resize(m , vector<int>( n , -1));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1 ){
                    int area = dfsVisit(i , j , grid);
                    maxArea = max(area , maxArea);
                }
            }
        }
        return maxArea;
    }
};
//instead of visited we modifes in grid itself the visited nodes as 0 so sc will be o(1)