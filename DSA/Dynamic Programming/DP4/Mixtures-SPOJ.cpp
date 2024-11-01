/*
Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

Input
There will be a number of test cases in the input.

The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.

The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

Output
For each test case, output the minimum amount of smoke.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<long long>> dp; // dp[i][j] means smoke on mixing i to j
int n ;

long long g(vector<int>& arr , int i , int j){ //g [i][j] means result color on mixing from i to j 
    long long res = 0;
    for(int m = i ; m <= j ; m++){
        res = (arr[m]%100 + res%100) % 100;
    }
    return res;
}

long long fDownTop(vector<int>&arr){
    dp.clear();
    dp.resize(n+1 , vector<long long> ( n+1 , 0));
    for(int len = 2 ; len <= n ; len++){
        for(int i=0 ; i+len-1 <= n-1 ; i++){
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k = i ; k <= j-1 ; k++){
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] + g(arr , i , k)*g(arr , k+1 , j));
            }
        }
    }
    return dp[0][n-1];
}

long long int fUpDown(vector<int> &arr , int i , int j){  // minimum smoke generated in mixing from i to j
    if(j-i < 1) return 0;
    if(j-i == 1) return dp[i][j] = arr[i]*arr[j];
    if(dp[i][j] != -1) return dp[i][j];

    long long ans = INT_MAX;
    for(int k = i ; k <= j-1 ; k++){
        ans = min(ans , fUpDown(arr , i , k) + fUpDown(arr, k+1 , j) + g(arr , i , k)*g(arr , k+1 , j));
    }
    return dp[i][j] = ans;
}

int main(){
    while(cin>>n){
        vector<int>arr(n+1 , 0);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        dp.clear();
        //dp.resize(n+1 , vector<long long> ( n+1 , -1));
        //cout<<fUpDown(arr , 0 , n-1)<<endl;
        cout<<fDownTop(arr)<<endl;
        arr.clear();
    }
    return 0;
}