/*
leetcode 130
*/
class Solution {
public:

    int m , n ;

    void dfs(vector<vector<char>>& board , int i , int j){
        if(i<0 or i>=m or j<0 or j>=n or board[i][j] != 'O') return;
        board[i][j] = 'N';
        dfs(board , i+1 , j);
        dfs(board , i-1 , j);
        dfs(board , i , j+1);
        dfs(board , i , j-1);
        return;
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        //bfs
        // queue<pair<int , int>> qu; // regions to be not capture , also will be marked with N
        // for(int i=0 ; i<m ; i++){
        //     if(board[i][0] == 'O'){
        //         qu.push({i,0});
        //         board[i][0] = 'N';
        //     } 
        //     if(board[i][n-1] == 'O') {
        //         qu.push({i,n-1});
        //         board[i][n-1] = 'N';
        //     }
        // }

        // for(int i=1 ; i<n-1 ; i++){
        //     if(board[0][i] == 'O') {
        //         qu.push({0,i});
        //         board[0][i] = 'N';
        //     }
        //     if(board[m-1][i] == 'O'){
        //         qu.push({m-1,i});
        //         board[m-1][i] = 'N';
        //     }
        // }

        // while(!qu.empty()){
        //     auto [i , j] = qu.front();
        //     qu.pop();
        //     for(auto [di , dj] : vector<pair<int,int>>{{1,0} , {-1,0} , {0,1} , {0,-1}}){
        //         int newRow = di + i;
        //         int newCol = dj + j;
        //         if(newRow < 0 or newRow >= m or newCol < 0 or newCol >= n or board[newRow][newCol] != 'O') continue;
        //         board[newRow][newCol] = 'N';
        //         qu.push({newRow , newCol});
        //     }
        // }

        // for(int i=0 ; i<m ; i++){
        //     for(int j=0 ; j<n ; j++){
        //         if(board[i][j] == 'O') board[i][j] = 'X';
        //         if(board[i][j] == 'N') board[i][j] = 'O';
        //     }
        // }


        // dfs 
        for(int i=0 ; i<m ; i++){
            if(board[i][0] == 'O'){
                dfs(board , i , 0);
            } 
            if(board[i][n-1] == 'O') {
                dfs(board , i , n-1);
            }
        }

        for(int i=1 ; i<n-1 ; i++){
            if(board[0][i] == 'O') {
                dfs(board , 0 , i);
            }
            if(board[m-1][i] == 'O'){
                dfs(board , m-1 , i);
            }
        }

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'N') board[i][j] = 'O';
            }
        }

        return ;
    }
};