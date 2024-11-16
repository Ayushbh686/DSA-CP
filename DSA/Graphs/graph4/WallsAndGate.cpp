/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
*/
//SAME AS MATRIX 01 SAME CODE COPY PASTE
class Solution {
public:

    int m , n;
    vector<vector<int>> result;

    void bfsMulti(vector<vector<int>>& rooms){
        queue<pair<int,int>> qu; //with gates(0) in it
        int Zcount = 0 , Ocount = 0; //ocount means empty room count
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(rooms[i][j] == 0){
                    Zcount++;
                    result[i][j] = 0;
                    qu.push({i,j});
                }
                else if(rooms[i][j] == 2147483647){ // empty room
                    Ocount++;
                }
            }
        }
        while(!qu.empty()){
            auto tp = qu.front();
            int i = tp.first , j = tp.second;
            int size = qu.size();
            qu.pop();
            vector<vector<int>> dir ={ {0,1} , {0,-1} , {1,0} , {-1,0}};
            for(auto el : dir){
                int newRow = el[0] + i;
                int newCol = el[1] + j;
                if(newRow < 0 or newRow >= m or newCol < 0 or newCol >= n or rooms[newRow][newCol] == -1) continue;
                if(result[newRow][newCol] == -2){
                    result[newRow][newCol] = result[i][j] + 1;
                    qu.push({newRow , newCol});
                }
            }
        }
    }

    vector<vector<int>> WallsAndGate(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms[0].size();
        result.resize(m , vector<int>(n,-2));
        bfsMulti(rooms);
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(result[i][j] == -2) result[i][j] == -1;
            }
        }
        return result;
    }
};
// multisource bfs