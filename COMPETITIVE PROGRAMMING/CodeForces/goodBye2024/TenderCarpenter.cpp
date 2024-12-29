#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        vector<int>arr(n);
        for(int i=0 ; i<n ; i++) cin>>arr[i];
        bool flag = true;
        for(int i=0 ; i<=n-2 ; i++){
            if(2 * min(arr[i] , arr[i+1]) > max(arr[i] , arr[i+1])) {
                cout<<"yes"<<endl;
                flag = false;
                break;
            }
        }
        if (flag == true) cout<<"no"<<endl;
    }
    return 0;
}