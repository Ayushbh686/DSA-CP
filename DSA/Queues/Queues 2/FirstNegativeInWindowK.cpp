#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {0 , -1 , -2 , 3 , 4 , -5 , 6 , 4 , 7 , -8};
    int n = v.size();
    int k = 3;
    vector<int> ans;
    queue<int> q;
    for(int i=0 ; i<n ; i++){
        if(v[i] < 0) q.push(i);
    }
    int i = 0;
    while(i<=n-k){
        while(q.size() > 0 and q.front() < i) q.pop();
        if(q.size() == 0 or q.front() >= i+k) ans.push_back(0);
        else ans.push_back(v[q.front()]);
        i++;
    }

    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
}
//O(N)