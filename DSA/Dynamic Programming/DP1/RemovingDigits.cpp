/*
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
*/
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<int> dp;

vector<int> getDigits(int n){
    vector<int> digits ;
    while(n > 0){
        if(n%10 != 0){
            digits.push_back(n%10);
        }
        n = n/10;
    }
    return digits;
}

int fGreedy(int n){
    if(n==0) return 0;
    if(n <= 9 ) return 1;
    int x = n;
    int maxDigit = 0;
    while(x > 0){
        int r = x % 10;
        maxDigit = max(maxDigit , r);
        x = x/10;
    }
    return dp[n] = 1 + fGreedy(n-maxDigit);
}

int fTopDown(int n){
    if(n==0) return 0;
    if(n <= 9) return 1;
    
    if(dp[n] != -1) return dp[n]; //if already computed then return 

    vector<int> d = getDigits(n);

    int result = INT_MAX;
    for(int i=0 ; i<d.size() ; i++){
        result = min(result , n - d[i]);
    }
    return 1 + result;
}

int fDownTop(int num){
    dp.clear();
    dp.resize(num+1 , -1);
    dp[0] = 0;
    for(int i=1 ; i<=9 ; i++) dp[i] = 1;
    for(int n=10 ; n<=num ; n++){
        int result = INT_MAX;
        vector<int> d = getDigits(n);
        for(int i=0 ; i<d.size() ; i++){
            result = min(result , dp[n - d[i]]);
        }
        dp[n] = 1 + result;
    }
    return dp[num];
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1 , -1);
    cout<<fGreedy(n)<<endl;
    //cout<<fTopDown(n)<<endl;
    //cout<<fDownTop(n)<<endl;
    return 0;
}