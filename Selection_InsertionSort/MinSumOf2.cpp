#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout << "enter the number of elements : ";
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int x=0;
    for(int i=0; i<n;i++){
        x=(x*10)+v[i];
    }
    for(int i=n-1;i>=1;i--){
        if(v[i]!=v[i-1]){
            swap(v[i],v[i-1]);
            break;
        }
    }
    int y=0;
    for(int i=0; i<n;i++){
        y=(y*10)+v[i];
    }
    cout<<x<<endl<<y;
    cout<<"the required sum is : "<<x+y;
    return 0;
}