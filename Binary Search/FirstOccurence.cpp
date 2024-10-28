#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,2,3,3,3,4,4,4,4,5,5,5,6,6,8,8,8};
    int n=18;
    int x=7;
    int lo=0;
    int hi=17;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(arr[mid]==x){
            if(arr[mid-1]!=x) {
                cout<<mid;
                return 0;
            }
            else{
                hi=mid-1;
            }
        }
        else if(arr[mid]>x){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<-1;
    return 0;
}