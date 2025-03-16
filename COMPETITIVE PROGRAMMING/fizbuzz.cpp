#include<bits/stdc++.h>
using namespace std;

int fn(int n){
    int ans = 1;
    // for(int i=0 ; i<=n ; i++){
    //     if(i%3 == i%5) ans++;
    // }

    int x = n/15;
    ans += x*3;

    int y = n%15;
    ans += ((y >= 2) ? 2 : y);
    
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fn(n)<<endl;
    }
    return 0;
}