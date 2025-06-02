/*
https://www.geeksforgeeks.org/minimum-steps-to-delete-a-string-after-repeated-deletion-of-palindrome-substrings/


Given a string str, containing only digits from '0' to '9'. Your task is to find the minimum number of operations required to delete all the digits of string, where in each operation we can delete a palindromic substring.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int n;

int minSteps(string s , int l , int r){
    //base cases
    if(l>r) return 0;  //string deleted
    if(l==r) return 1; //string 1 size
    if(r==l+1 and s[l] == s[r]) return dp[l][r] = 1; //string already 2 size palindrome

    //stored result
    if(dp[l][r] != -1) return dp[l][r];

    //intialise result with delete this charater only
    int ans = minSteps(s , l+1 , r) + 1;

    //if l and l+1 equal then substring found to delete 
    if(s[l] == s[l+1]) ans = min(ans , minSteps(s , l+2 , r) + 1);

    //now find to delete if any other character match with it then delete middle parts as these will be deleted alongwith middle part only( dry run for 21924568 where 2192 here 2 will be palindromic pair and deleted along with 19 middle string and 4568 will be dealt seprately)
    for(int i=l+2 ; i<=r ; i++){
        if(s[l] == s[i]){
            ans = min(ans , minSteps(s , l+1 , i-1) +  minSteps(s , i+1 , r));
        }
    }
    
    return dp[l][r] = ans;
}

int main(){
    string s;
    cin>>s;
    n = s.size();
    dp.resize(n , vector<int>(n , -1));
    cout<<minSteps(s , 0 , n-1);
    return 0;
}
//o(n3) tc and sc