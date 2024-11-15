/*
leetcode 1197
in an infinite  chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].
A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

set<pair<int, int>> visited;

int main(){
    int x , y;
    cin>>x>>y;
    x = abs(x);
    y = abs(y);
    queue<pair<int , int>> qu;
    int steps = 0;
    qu.push({0,0});
    visited.insert({0,0});

    while(!qu.empty()){
        pair<int,int>p = qu.front();
        int i = p.first;
        int j = p.second;
        int size = qu.size();
        qu.pop();
        if(i==x and j==y) break;
        vector<pair<int , int>> dir = {{2 , -1} , {2 , 1} , {-2 , -1} , {-2 , 1} , {1 , -2} , {1 , 2} , {-1 , -2} , {-1 , 2}};
        for(int k=0 ; k<size ; k++){
            for(pair<int,int> p : dir){
                int di = p.first;
                int dj = p.second;
                int newRow = i + di;
                int newCol = j + dj;
                if(visited.find({newRow , newCol}) != visited.end()) continue;
                qu.push({newRow,newCol});
                visited.insert({newRow , newCol});
            }
        }
        steps++;
    }
    cout<<steps<<endl;
    return 0;
}