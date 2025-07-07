#include<bits/stdc++.h>
using namespace std;

void merge1(long long arr1[] , long long arr2[] , int n , int m){ //tc = min(n,m) + mlogm + nlogn
    int left = n-1 ;
    int right = 0 ;

    // we  assure is that arr1[] will contain all the smaller elements and arr2[] will contain all the bigger elements.
    while(left >= 0 and right < m){
        if(arr1[left] <= arr2[right]) break;
        swap(arr1[left] , arr2[right]);
        left--;
        right++;
    }
    
    //now sort them individually 
    sort(arr1 , arr1 + n);
    sort(arr2 , arr2 + m);
    return ;
} 

void merge2(long long arr1[] , long long arr2[] , int n , int m){ //gap method  tc = (m+n)log(m+n)
    int len = n + m;
    int gap = len/2 + len%2; // another way of writting ceil(len/2);

    while(gap > 0){
        int left = 0;
        int right = left + gap;
        
        while(right < len){
            //arr1 and arr2
            if(left < n and right >= n){
                if(arr1[left] > arr2[right-n]) swap(arr1[left] , arr2[right-n]);
            }
            //arr1 and arr1
            else if(left < n and right < n){
                if(arr1[left] > arr1[right]) swap(arr1[left] , arr1[right]);
            }
            //arr2 and arr2
            else{
                if(arr2[left-n] > arr2[right-n]) swap(arr2[left-n] , arr2[right-n]);
            }

            left++;
            right++;
        }

        if(gap == 1) break;

        gap = gap/2 + gap%2;
    }
    return ;
}

int main(){
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    // merge1(arr1, arr2, n, m);
    merge2(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}