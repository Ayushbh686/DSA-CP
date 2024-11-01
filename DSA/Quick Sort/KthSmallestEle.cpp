#include<iostream>
using namespace std;

int partition(int arr[], int si , int ei){
    int pivotEle = arr[(si+ei)/2];
    int count =0;
    for(int i=si ; i<=ei; i++){ //count number of elements less than pivotEle to find its position
        if(i == (si+ei)/2) continue;
        if(arr[i]<=pivotEle) count++;
    }
    int pivotIdx = si + count;
    swap(arr[(si+ei)/2] , arr[pivotIdx]); //placing pivotEle on correct position
    int i =si;
    int j =ei;
    while(i<pivotIdx && j>pivotIdx){  //placing smaller on left and greater on right (dividing)
        if(arr[i]<=pivotEle) i++;
        if(arr[j]>pivotEle) j--;
        else if(arr[i]>pivotEle && arr[j]<=pivotEle){
            swap(arr[i] , arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx; 
}

int Kthsmallest(int arr[], int si , int ei, int k){
    int pivotIdx = partition( arr , si , ei);
    if(pivotIdx == k ) return arr[pivotIdx];
    else if(pivotIdx > k) return Kthsmallest(arr, si , pivotIdx-1, k);
    else if(pivotIdx < k) return Kthsmallest(arr, pivotIdx+1 , ei , k);
}

int main(){
    int arr[]={5,2,9,7,1,8,6,42,34,19} , k;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"enter the value of k : ";
    cin>>k;
    cout<<Kthsmallest(arr , 0 , n-1, k-1);
    return 0 ;
}

// O(n) TC with this method (avg case) , o(n2) worst case 
// S,B,I sort se O(k*n)
// merge sort se O(nlogn)
// LC kth largest element 