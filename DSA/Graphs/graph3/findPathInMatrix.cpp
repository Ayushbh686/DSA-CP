/*
Given N X N matrix filled with 1, 0, 2, 3. Find whether there is a path possible from source to destination, traversing through blank cells only. You can traverse up, down, right, and left. 

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>&matrix , int i, int j ){
    int n = matrix.size();
    if(i>n-1 or j>n-1 or i<0 or j<0 or matrix[i][j] == 0) return false;
    if(matrix[i][j] == 2) return true;

    matrix[i][j] = 0;

    vector<int>dir = {0, 1 , 0 , -1 , 0};
    for(int k=0 ; k<4 ; k++){
        int newI = i + dir[k];
        int newJ = j + dir[k+1];
        // if(newI == parI and newJ == parJ) continue;
        if(dfs(matrix , newI , newJ)) return true;
    }
    return false;
}

bool findPath(vector<vector<int>>matrix){
    int n = matrix.size();

    int start_i , start_j ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(matrix[i][j] == 1){
                start_i = i;
                start_j = j;
            }
        }
    }
    cout<<start_i<<" "<<start_j<<endl;
    return dfs(matrix , start_i , start_j );
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>matrix(n, vector<int>(n));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>matrix[i][j];
        }
    }

    cout<<findPath(matrix)<<endl;
    return 0;
}