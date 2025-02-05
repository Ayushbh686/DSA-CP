#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>&v){
    int n = v.size();
    int i = 0 ;
    int j = n-1;
    while(i<j){
        if(v[i]==0) i++;
        if(v[j]==1) j--;
        // if(i>j) break;
        else if( (v[i] == 1) && (v[j] == 0) ){
           v[i]=0;
           v[j]=1;
           i++;
           j--;
        }
    }
    return ;
}
int main(){
    vector<int>v = {1,1,0,1,0,1,1,0};
    sort(v);
    cout<<"sorted loop : ";
    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}