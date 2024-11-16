/*
leetcode 542
*/

class Solution {
public:

    int m , n;
    vector<vector<int>> result;

    void bfsMulti(vector<vector<int>>& mat){
        queue<pair<int,int>> qu; //with zeros in it
        int Zcount = 0 , Ocount = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(mat[i][j] == 0){
                    Zcount++;
                    result[i][j] = 0;
                    qu.push({i,j});
                }
                else{
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
                if(newRow < 0 or newRow >= m or newCol < 0 or newCol >= n) continue;
                if(result[newRow][newCol] == -1){
                    result[newRow][newCol] = result[i][j] + 1;
                    mat[i][j] = 0;
                    qu.push({newRow , newCol});
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        result.resize(m , vector<int>(n,-1));
        bfsMulti(mat);
        return result;
    }
};
// multisource bfs