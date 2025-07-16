#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;

vector<int> method1(vector<int>& nums, int target) {
    // for(int i=0 ; i<nums.size() ; i++){
    //    for( int j =i+1; j<nums.size() ; j++){
    //        if((nums[i]+nums[j])==target) 
    //        return {i,j};
    //    }
    // }
    // return {};  

    //method 2 (o(n))
    int n = nums.size();
    unordered_map<int , int> mp; // num , idx
    for(int i=0 ; i<n ; i++){
        if(mp.find(target - nums[i]) != mp.end()) return {mp[target - nums[i]] , i};
        mp[nums[i]] = i;
    }
    return {}; 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x , n; //target

        // cout<<"enter array size : ";
        cin>>n; //array size

        // cout<<"enter array : "; 
        vector<int> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        
        // cout<<"enter target : "<<endl;
        cin>>x;

        vector<int>res = method1(arr , x);
        if(res.size() == 2)cout<<res[0]<<" "<<res[1]<<endl;
        else cout<<-1<<endl;
    }
    return 0;

}