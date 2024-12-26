/*
If you want to explicitly list all possible paths, DP is not the best approach because it doesn't store the exact path sequences. Instead:

Use Backtracking to explore all paths and store them in a list.
Backtracking has higher complexity (𝑂(2^𝑚+𝑛)) due to the exponential growth of paths but can enumerate all paths.
DP is thus better for counting paths efficiently, while backtracking is better for finding all paths explicitly.
*/

#include <bits/stdc++.h>
using namespace std;

int m , n;
vector<string>ans;
int paths = 0;

void f(int i , int j , vector<vector<int>> &mat , string &temp){
    if(i>=m or j>=n or i<0 or j<0 or mat[i][j] == 0) return ; //pruning step 

    if(i==m-1 and j==n-1){
        ans.push_back(temp);
        paths++;
        return;
    }

    vector<vector<int>>dir = {{0,-1} , {-1,0} , {0,1} , {1,0}}; //LURD

    for(int x=0 ; x<4 ; x++){
        mat[i][j] = 0; //block this path as it will be marked visited and we dont want to visit again on it to avaoid cycle
        if(x==0)temp.push_back('L');
        if(x==1)temp.push_back('U');
        if(x==2)temp.push_back('R');
        if(x==3)temp.push_back('D');
        f(i+dir[x][0] , j+dir[x][1] , mat , temp);
        temp.pop_back(); //reverting step
        mat[i][j] = 1; //again mark unvisited or unblock it; 
    }
    return;
}

vector<string> findPath(vector<vector<int>> &mat) {
    m = mat.size();
    n = mat[0].size();
    string temp;
    f(0,0,mat,temp);
    return ans;
}

int main(){
    cin>>m>>n;
    vector<vector<int>>mat(m,vector<int>(n));

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>mat[i][j];
        }
    }

    findPath(mat);
    cout<<paths<<endl;
    return 0;
}       
// 1 means path and 0 means blocked and here we do not want to visit blocked and visited path again in a path so we made visited also as 0 (blocked)
//pruning step and reverting step marked in code