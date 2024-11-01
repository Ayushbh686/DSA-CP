#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of elements : ";
    cin>>n;
    vector<int>v(n);
    cout<<"enter the elements : ";
    for( int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>visited(n,0);
    int x=0;
    for(int i=0;i<n;i++){
        int min=INT_MAX;
        int mindx=0;
        for(int j=0;j<n;j++){
        if (visited[j]==1) continue;
        if(v[j]<min){
            min=v[j];
            mindx=j;
        }
        }
        v[mindx]=x;
        x++;
        visited[mindx]=1;
    }
    cout<<"the required array will be : ";
    for( int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
//alternative by making similar array and sorting and doing same 
// another alternative by placing negative numbers in same array and then making them positive but none element of array should be less than 0
//hash maps 