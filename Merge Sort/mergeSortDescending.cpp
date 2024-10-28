#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>&a , vector<int>&b , vector<int>&arr){
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>=b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(j<b.size()) arr[k++]=b[j++];
    while(i<a.size()) arr[k++]=a[i++];    
    return ;
}

void mergeSort(vector<int>&arr){
    int n = arr.size();
    if(n==1) return ;
    int n1 = n/2 , n2 = n - n/2;
    vector<int> a(n1), b(n2);
    for(int i=0 ; i<n1 ; i++){
        a[i]=arr[i];
    }
    for(int i=0 ; i<n2 ; i++){
        b[i]=arr[n1+i];
    }
    //recursion
    mergeSort(a);
    mergeSort(b);
    Merge(a,b,arr);
    a.clear();
    b.clear();
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int n = arr.size();
    for(int i =0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr);
    for(int i =0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    return 0 ;
}