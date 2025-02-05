/*
Min-Heap Approach
Approach:

Use a min-heap of size k+1.
Insert the first k+1 elements into the heap.
For each remaining element, extract the minimum element from the heap and insert the current element.
Continue this until all elements are processed.
*/

#include<bits/stdc++.h>
using namespace std;

void nearlySorted(vector<int>&arr , int k){
    int n = arr.size();
    priority_queue<int , vector<int> , greater<int>> pq;
    for(int i=0 ; i<max(2,k) ; i++){
        pq.push(arr[i]);
    }

    int count = 0;
    int i=max(2,k);

    // for(int i=k ; i<n ; i++){
    //     int minEle = pq.top();
    //     arr[count] = minEle;
    //     count++;
    //     pq.push(arr[i]);
    // }

    while(!pq.empty()){
        int minEle = pq.top();
        pq.pop();
        arr[count] = minEle; 
        count++;
        if(i<n){
            pq.push(arr[i]);
            i++;
        }
    }
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }

        nearlySorted(arr , k);

        for(int ele : arr){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
5

6 3
2 4 1 6 3 5

10 4
3 5 4 1 2 9 10 7 6 8

10 0 
1 2 3 4 5 6 7 8 9 10

10 1
2 1 4 3 6 5 8 7 10 9

10 10
10 8 6 7 9 5 3 1 2 4 
*/