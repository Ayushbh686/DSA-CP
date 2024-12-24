/*
leetcode 1368
Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.
*/

class Solution {
public:

    int m , n ;
    vector<vector<int>>dist;
    vector<vector<int>>dir = {{0,1} , {0,-1} , {1,0} , {-1,0}};

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dist.resize(m , vector<int>(n , INT_MAX));

        deque<vector<int>> dq; //<i , j>
        dq.push_front({0 , 0});
        dist[0][0] = 0;

        while(!dq.empty()){
            auto top = dq.front();
            int i = top[0] , j = top[1];
            dq.pop_front();

            for(int x = 0 ; x<4 ; x++){
                int newi = i + dir[x][0];
                int newj = j + dir[x][1];
                int edgewt = 1;
                if(x+1 == grid[i][j]) edgewt = 0;
                if(newi >= 0 and newi < m and newj >=0 and newj < n){ //newcell in grid
                    if(dist[newi][newj] > dist[i][j] + edgewt){
                        dist[newi][newj] = dist[i][j] + edgewt;
                        if(edgewt == 1) dq.push_back({newi, newj});
                        else dq.push_front({newi, newj});
                    }  
                }
            }
        }

        return dist[m-1][n-1];
    }
};
//special dijkstra in 0-1 bfs