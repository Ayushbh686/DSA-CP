#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array : ";
    for(int i=0 ; i<n ; i++){
       cin>>arr[i];
    }
    int max = INT_MIN;
    int smax= INT_MIN;
    for(int i=0 ; i<n ; i++){
        if(max < arr[i]) max=arr[i];
    }
    cout<<"maximum : "<<max<<endl;
    for(int i=0 ; i<n ; i++){
        if((smax < arr[i]) && (arr[i] != max)) smax=arr[i];
    }
    cout<<"second maximum : "<<smax<<endl;
    return 0;
}