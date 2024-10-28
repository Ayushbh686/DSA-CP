#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&a, vector<int>&b , vector<int>&arr){
    int i =0; //for a
    int j=0;  // for b
    int k=0; // for arr
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
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
    if(i==a.size()){ //  i at end
        while(j<b.size()) arr[k++]=b[j++];
    }
    if(j==b.size()){ //  j at end
        while(i<a.size()) arr[k++]=a[i++];
    }
    return ;
}

void MergeSort(vector<int>&arr){
    int n=arr.size();
    if(n==1) return ;  //base case
    int n1=n/2 , n2=n-n/2;
    //diving the array into two parts
    vector<int> a(n1) , b(n2);
    for(int i=0 ; i<n1 ; i++){
        a[i]=arr[i];
    }
    for(int i=0 ; i<n2 ; i++){
        b[i]=arr[i+n1];
    }
    //sorting the divided arrays (recursively)
    MergeSort(a);
    MergeSort(b);
    //merging two sorted arrays
    merge(a,b,arr);
    a.clear();
    b.clear();
}

int main(){
    int n ;
    vector<int> arr;
    cout<<"enter the number of elements : ";
    cin>>n;
    cout<<"enter the elements : ";
    for(int i=0; i<n ; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    MergeSort(arr);
    cout<<"the sorted array is : ";
    for(int i = 0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// O(nlogn) -> Time Complexity , O(n)->Space Complexity
// Stable Sort