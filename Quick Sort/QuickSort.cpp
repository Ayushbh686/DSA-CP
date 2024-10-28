#include<iostream>
#include<vector>
using namespace std;

int partition(int arr[] , int si , int ei){ //returns the index of pivot element (taken as 1st element) and divide it
    int mid = si + (ei - si) / 2;
        int pivot = arr[mid];
        swap(arr[mid], arr[ei]);  // Move pivot to end
        int i = si;
        for (int j = si; j < ei; j++) {
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[ei]);  // Move pivot to its final place
        return i;
}

void QuickSort(int arr[] , int si , int ei){
    if(si>=ei) return ; // base case
    int pivotIdx = partition(arr, si , ei); //place the pivotelement at correct postion and partition the array 
    //recursive call for left and right side of divided array around pivot element to sort them 
    QuickSort(arr, si ,pivotIdx-1);
    QuickSort(arr, pivotIdx+1 , ei);
    return ;
}

int main(){
    int arr[]={5,2,9,7,1,8,6,42,34,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    for( int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    QuickSort(arr,0,n-1);
    for( int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// TC => Avg case = O(nlogn) , Worst Case = O(n2) (due to unbalanced partitioning and it goes worst in sorted or nearly sorted arrays)
// SC => O(logn)  ( can be considered as inplace sorting )
// Internal sorting is optimised version of this
// Unstable
 