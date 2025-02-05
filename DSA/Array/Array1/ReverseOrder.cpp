#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>A;
    int n; 
    cout<<"enter the number of elemrnts : ";
    cin>>n;
    cout<<"enter the elements : ";
    for(int i=0; i<n ; i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    cout<<"the reverse array is : ";
    vector<int>rev(A.size());
    for(int i=0; i<A.size() ; i++){
        rev[i]=A[A.size()-i-1];
    }
    for(int i=0; i<n ; i++){
        cout<<rev[i]<<" ";
    }

    //ALTERNATIVE WITHOUT EXTRA ARRAY
    // for(int i=0, j=A.size()-1 ; i<=j ; i++,j--){
    //     int temp=A[i];
    //     A[i]=A[j];
    //     A[j]=temp;
    // }
    
}
