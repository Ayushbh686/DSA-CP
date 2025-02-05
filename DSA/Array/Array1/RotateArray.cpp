#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int>&v, int i , int j){
     int temp;
     while (i<=j){
        temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
     }
     return ;
}
int main(){
    vector<int>v = {1,2,3,4,5,6,7,8};
    int k;
    int n = v.size();
    cout<<"enter the number of times to be rotated : ";
    cin>>k;
    if(k>n) k%=n;
    reverse(v,0,n-k-1);
    // for( int i=0; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    // }
    reverse(v,n-k,n-1);
    reverse(v,0,n-1);
    for( int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}
// 1 2 3 4 5 6
// 0 1 2 3 4 5 