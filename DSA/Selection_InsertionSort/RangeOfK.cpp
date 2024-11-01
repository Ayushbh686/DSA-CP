#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int min(int a,  int b){
    if(a>=b) return a;
    else return b;
}
int max(int a,  int b){
    if(a<=b) return b;
    else return a;
}
int main(){
    int arr[]={5,3,10,3};
    int n =4;
    float kmin=(float)INT_MIN;
    float kmax=(float)INT_MAX;
    bool flag=true;
    for(int i=0; i<n-1;i++){
        if(arr[i]>=arr[i+1]){
            kmin=max(kmin,(float)(arr[i]+arr[i+1])/2);
        }
        else{
            kmax=min(kmax,(float)(arr[i]+arr[i+1])/2);
        }
        if(kmin>kmax){
            flag = false;
            break;
        }
    }

    if(((int)kmin+1) > (int)kmax){
        cout<<-1;
        return 0;
    }
    else{
        if((int)kmin-kmin>0){
            kmin=(int)kmin +1;
        }
        cout<<"range of k is "<<kmin<<" to "<<(int)kmax;
    }
    // if(flag==false){
    //     cout<<-1;
    //     return 0;
    // }
    // else{
    //     cout<<"range of k is "<<(int)kmin +1 <<" to "<<(int)kmax;
    // }
}
//can be more optimised at end