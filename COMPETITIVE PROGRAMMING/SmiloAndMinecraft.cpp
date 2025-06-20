#include<bits/stdc++.h>
using namespace std;

int fn(vector<vector<char>>& arr, int n, int m, int k){
    //for gold
    vector<vector<int>> help(n , vector<int>(m , 0));

    queue<pair<int,int>> q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == 'g') q.push({i,j});
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=x-k ; i<=x+k ; i++){
            if(y+k <= m-1 and i>=0 and i<n) help[i][y+k]++;
            if(y-k >= 0 and i>=0 and i<n) help[i][y-k]++;
        }

        for(int i=y-k+1 ; i<=y+k-1 ; i++){
            if(x+k <= n-1 and i>=0 and i<m) help[x+k][i]++;
            if(x-k >= 0 and i>=0 and i<m) help[x-k][i]++;
        }
    }

    //for stone
    vector<vector<int>> help2(n , vector<int>(m , 0));

    q.clear();
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == '#') q.push({i,j});
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=x-k ; i<=x+k ; i++){
            for(int j=y-k ; j<=y+k ; j++){
                if(i>=0 and i<n and j>=0 and j<m){
                    help2[i][j]++;
                }
            }
        }

        for(int i=y-k+1 ; i<=y+k-1 ; i++){
            if(x+k <= n-1 and i>=0 and i<m) help[x+k][i]++;
            if(x-k >= 0 and i>=0 and i<m) help[x-k][i]++;
        }
    }


    int ans = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            // cout<<help[i][j]<<" ";
            if(arr[i][j] == '.') ans = max(ans , help[i][j]);
        }
        cout<<endl;
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , m , k;
        cin>>n>>m>>k;

        vector<vector<char>> arr(n, vector<char>(m));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin>>arr[i][j];
            }
        }

        cout<<fn(arr , n , m , k)<<endl;

    }
    return 0;
}