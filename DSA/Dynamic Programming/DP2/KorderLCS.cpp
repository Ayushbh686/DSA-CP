/*
In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change at most k elements in the first sequence to any value you wish to
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<vector<int>>> dp;

int fUpDown(vector<int>&arr1 , vector<int>&arr2 , int i , int j , int k){
    if(i >= arr1.size() or j >= arr2.size()) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];

    int res = 0;
    if(arr1[i] == arr2[j]) res = 1 + fUpDown(arr1 , arr2 , i+1 , j+1 , k);
    else {
        if(k > 0){
            res = 1 + fUpDown(arr1 , arr2 , i+1 , j+1 , k-1);
        }    
        res = max(res  , fUpDown(arr1 , arr2 , i+1 , j , k));
        res = max(res  , fUpDown(arr1 , arr2 , i , j+1 , k));
    }
    return dp[i][j][k] = res;
}

int main(){
    int n , m , k;
    cin>>n>>m>>k;
    vector<int>arr1(n); 
    vector<int>arr2(m);
    for(int i=0 ; i<n ; i++) cin>>arr1[i];
    for(int i=0 ; i<m ; i++) cin>>arr2[i];
    dp.clear();
    dp.resize(n , vector<vector<int>> (m , vector<int> (k+1 , -1)));
    cout<<fUpDown(arr1 , arr2 , 0 , 0 , k)<<endl;
    return 0; 
}
//lengthy bottom top solution