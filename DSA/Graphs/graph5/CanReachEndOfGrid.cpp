//Google Question
/*
given a grid with L , U , R , D can we reach n-1 and m-1 coloumn by starting from the 0,0 coloumn 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m;
    cin>>n>>m;
    
    vector<vector<char>> grid(n , vector<char>(m));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>grid[i][j];
        }
    }

    int counter = 0 , i = 0 , j = 0 ;
    while(counter <= n*m+1){
        if(i<0 or j<0 or i>=n or j>=m) {
            cout<<"false as we go out of grid";
            return 0;
        }
        if(i==n-1 and j==m-1) {
            cout<<"True as we can recah in "<<counter<<" steps";
            return 0;
        }
        if(grid[i][j] == 'L') j--;
        else if(grid[i][j] == 'R') j++;
        else if(grid[i][j] == 'U') i--;
        else if(grid[i][j] == 'D') i++;
        counter++;
    }
    cout<<"false as cycle detected";
    return 0;
}
//alternative -> use tortoise method from linked list as its like linked list only as each coloumn point to only one coloumn so use two pointer fast and slow and if they meet then its cycle