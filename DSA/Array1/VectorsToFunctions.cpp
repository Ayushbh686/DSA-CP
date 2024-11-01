#include<iostream>
#include<vector>
using namespace std;
void change(vector<int>&v){   // put & before v to pass through the function by reference 
    v[0]=100;
    for(int i=0; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>A;
    int n;
    cout<<"enter the number of elements : ";
    cin>>n; 
    for(int i=0 ; i<n ;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    A.pop_back();
    for(int i=0; i<A.size() ; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    change(A);
    for(int i=0; i<A.size() ; i++){
        cout<<A[i]<<" ";
    }
}