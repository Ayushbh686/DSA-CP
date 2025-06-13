/*
https://codeforces.com/contest/2118/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

void fn(int n) {
    vector<vector<int>> operations; // (row, l, r) => reverse from l to r in row
    
    for (int i = 1; i < n; ++i) {
        
        operations.push_back({i , 1, i});     // reverse prefix
        operations.push_back({i , i+1, n});     // reverse suffix 
    }
    operations.push_back({n , 1 , n});

    // Output number of operations
    cout << operations.size() << endl;
    for (int i=0 ; i<operations.size() ; i++) {
        cout << operations[i][0]<<" "<<operations[i][1]<<" "<<operations[i][2]<<endl;
    }
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        fn(n);
    }
    return 0;
}