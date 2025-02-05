#include<bits/stdc++.h>
using namespace std;

void addInarray(vector<int>&arr , int a , int b){
    int n = arr.size();
    //instead of adding from a to b effective we do arr[a] +=100 and arr[b+1] -= 100 so when doing prefix sum if become equivalent to final array
    a = min(a,b);
    b = max(a,b);

    a = max(0 , a);
    arr[a] += 100;

    b = min(n-2 , b);
    arr[b+1] -= 100;
    return; 
}

int prefixSum(vector<int>&arr){
    //gets the prefix array and return maximum element as answer
    int maxEle = arr[0];
    for(int i=1 ; i<arr.size() ; i++){
        arr[i] = arr[i-1] + arr[i];
        maxEle = max(maxEle , arr[i]);
    }
    return maxEle;
}

int main(){
    int t;
    cin>>t;
    while(t--){

        int n , m;
        cin>>n>>m;
        vector<int>arr(n,0);
        if(n==0 or m==0){
            cout<<0<<endl;
            continue;
        } 
        while(m--){
            int a , b;
            cin>>a>>b;
            addInarray(arr,a,b);
        }

        cout<<prefixSum(arr)<<endl;
    }
    return 0;
}

/*
5

5 3
0 3
4 4
2 4

6 4
0 6
3 0
2 0
1 0

6 4
-1 3
4 4
5 6
2 3

5 5
0 0
1 1
2 2 
3 3 
4 4

6 6
-1 7
0 2 
3 4
5 6
1 3
3 4


*/

/*
200
400
200
100
400
*/