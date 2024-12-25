#include<bits/stdc++.h>
using namespace std;

vector<string>grid;
vector<vector<string>> ans;

bool canPlaceQueen(int row , int col){
    int n = grid.size();
    //coloumn check
    for(int i=row-1 ; i>=0 ; i--){
        if(grid[i][col] == 'Q') return false; //we are attacked
    }

    //left daignoal check
    for(int i=row-1 , j=col-1 ; i>=0 and j>=0 ; i--,j--){
        if(grid[i][j] == 'Q') return false; //we are attacked
    }

    //right daigonal check
    for(int i=row-1 , j=col+1 ; i>=0 and j<n ; i--,j++){
        if(grid[i][j] =='Q') return false ; // we are attacked
    }

    //no need to check for lower position and row and they are not filled yet 
    return true;
}

void f(int row , int n){ //recursive function for solving nQueens
    if(row >= n){
        ans.push_back(grid);
        return ;
    }

    for(int col=0 ; col<n; col++){
        if(canPlaceQueen(row ,col)){
            grid[row][col] = 'Q';
            f(row+1 , n);
            grid[row][col] = '.';
        }
    }
    return;
}


vector<vector<string>> solveNQueens(int n){ //main function
    f(0,n);
    return ans;
}

int main(){ //just a driver function to call main function
    int n;
    cin>>n;
    grid.resize(n, string(n,'.'));

    solveNQueens(n);

    //cout<<ans.size();
    for(auto ele : ans){
        for(int i=0 ; i<n ; i++){
            cout<<ele[i]<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}
// in pruning step we elenimated remaing call for same row if a queen is already placed in one row and in backtracking we are reverting our updation in grid after every call