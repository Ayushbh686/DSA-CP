/*
A lazy tourist wants to visit as many interesting locations in a city as possible without going one step further than necessary. Starting from his hotel, located in the north-west corner of city, he intends to take a walk to the south-east corner of the city and then walk back. When walking to the south-east corner, he will only walk east or south, and when walking back to the north-west corner, he will only walk north or west. After studying the city map he realizes that the task is not so simple because some areas are blocked. Therefore he has kindly asked you to write a program to solve his problem.

Given the city map (a 2D grid) where the interesting locations and blocked areas are marked, determine the maximum number of interesting locations he can visit. Locations visited twice are only counted once.

Input
The first line in the input contains the number of test cases (at most 20). Then follow the cases. Each case starts with a line containing two integers, W and H (2 ≤ W , H ≤ 100), the width and the height of the city map. Then follow H lines, each containing a string with W characters with the following meaning:

. Walkable area
* Interesting location (also walkable area)
# Blocked area

You may assume that the upper-left corner (start and end point) and lower-right corner (turning point) are walkable, and that a walkable path of length H + W − 2 exists between them.

Output
For each test case, output a line containing a single integer: the maximum number of interesting locations the lazy tourist can visit.
*/

// leetcode 741 cherry pickup

#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#define ll long long int
using namespace std;

ll n , m;
char mat[105][105];
ll dp[105][105][105];

ll  fUpDown(ll x , ll y , ll i , ll j){
    if(x > n or y > m or i > n or j > m or mat[i][j] == '#' or mat[x][y] == '#' ) return 0;
    if(x == n and y == m) return mat[x][y] == '*'; // both of them will reach at same either at end or one will go out of grid as x+y = i+j always
    if(dp[x][y][i] != -1) return dp[x][y][i];
    ll ans = INT_MIN;

    ans = max(ans , fUpDown(x+1 , y , i+1 , j));
    ans = max(ans , fUpDown(x+1 , y , i , j+1));
    ans = max(ans , fUpDown(x , y+1 , i+1 , j));
    ans = max(ans , fUpDown(x , y+1 , i , j+1));

    ans += mat[x][y] == '*';
    ans += mat[i][j] == '*';

    if(x==i and y==j and mat[x][y] == '*') ans--;

    return dp[x][y][i] = ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        memset(dp , -1 , sizeof dp);
        for(ll i=1 ; i<=n ; i++){
            for(ll j=1 ; j<=m ; j++){
                cin>>mat[i][j];
            }
        }
        cout<<fUpDown(1 , 1 , 1 , 1)<<endl;
    }
    return 0;
}