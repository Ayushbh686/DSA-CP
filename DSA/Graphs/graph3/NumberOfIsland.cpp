/*
leetcode 200
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

*/
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i , int j ){
        int m = grid.size();
        int n=grid[0].size();
        if(i>m-1 || i<0 || j>n-1 || j<0 || grid[i][j]!='1') return ;
        //if(j>n-1 || j<0 ) return ;
        
        grid[i][j]='0';
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        // dfs(grid,i+1,j+1);
        // dfs(grid,i+1,j-1);
        // dfs(grid,i-1,j+1);
        // dfs(grid,i-1,j-1);
        return; 
    }

    void bfs(vector<vector<char>>& grid,int i , int j){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int , int>> qu;
        qu.push({i , j});
        grid[i][j] = '0';
        while(not qu.empty()){
            int i = qu.front().first;
            int j = qu.front().second;

            qu.pop();

            if(i+1 < m and grid[i+1][j] == '1'){
                grid[i+1][j] = '0';
                qu.push({i+1 , j});
            }
            if(i-1 >= 0 and grid[i-1][j] == '1'){
                grid[i-1][j] = '0';
                qu.push({i-1 , j});
            }
            if(j+1 < n and grid[i][j+1] == '1'){
                grid[i][j+1] = '0';
                qu.push({i , j+1});
            }
            if(j-1 >= 0 and grid[i][j-1] == '1'){
                grid[i][j-1] = '0';
                qu.push({i , j-1});
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        //int water = 0;
        int m = grid.size();
        int n=grid[0].size();
        for(int i=0; i<m ; i++) {
            for(int j=0; j<n ; j++){
                if(grid[i][j]=='1') {
                    num++;
                    //dfs(grid , i , j );   
                    bfs(grid , i , j); 
                }
            }
        }
        return num;
    }
};