#include<bits/stdc++.h>
using namespace std;

vector<int> repeatingNum(vector<int>arr , int n){
    int num = 0;
    vector<int>ans;
    for(int i=0 ; i<n+2 ; i++) num ^= arr[i];
    for(int i=1 ; i<=n ; i++) num ^= i;
    
    //repating number a , b then num = a^b
    int k=0;
    while(true){
        if(num & 1) break;
        num = num >> 1;
        k++;
    }
    // cout<<k<<endl;

    int numA = 0 , numB = 0;
    for(int i=0 ; i<n+2 ; i++){
        if((arr[i] >> k) & 1){
             numA ^= arr[i];
        }
        else numB ^= arr[i];
    }

    for(int i=1 ; i<=n ; i++){
        if((i >> k) & 1){
            numA ^= i;
        }    
        else numB ^= i;
    }

    ans.push_back(numA);
    ans.push_back(numB);
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        //taking n input
        int n;
        cin>>n;
        vector<int>arr(n+2);

        //taking array input
        for(int i=0 ; i<n+2 ; i++) cin>>arr[i];
        
        //output result
        vector<int> ans = repeatingNum(arr , n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}