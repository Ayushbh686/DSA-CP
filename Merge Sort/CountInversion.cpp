#include<iostream>
#include<vector>
using namespace std;

int inverison(vector<int>a,vector<int>b){
    int count = 0;
    int i=0; //a
    int j=0; //b
    while( i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            count += (a.size()-i);
            j++;
        }
        else{
            i++;
        }
    }
    return count;
}

void merge(vector<int>& a, vector<int>& b, vector<int>& v) {
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            v[k++] = a[i++];
        } else {
            v[k++] = b[j++];
        }
    }
    while (i < a.size()) {
        v[k++] = a[i++];
    }
    while (j < b.size()) {
        v[k++] = b[j++];
    }
}

int mergeSort(vector<int>&v){
    int n = v.size();
    int count = 0;
    if( n==1 ) return 0;
    vector<int> a(n/2);
    vector<int> b(n-n/2);
    int k = 0;
    for(int i = 0 ; i < a.size() ; i++){
        a[i] = v[k++];
    }
    for(int i = 0 ; i < b.size() ; i++){
        b[i] = v[k++];
    }
    //recursion (for sorting)
    count += mergeSort(a);
    count += mergeSort(b);
    //count inversion before merging 
    count += inverison(a,b);
    //merge them
    merge(a,b,v);
    a.clear();
    b.clear();
    return count;
}

int main(){
    vector<int> v={5,1,3,0,4,9,6};
    cout<<mergeSort(v);
    return 0;
}
//tc = o(nlogn)
// SC= O(N)
//INVERSION COUNT CAN BE MERGED INTO MERGE FUNCTION 