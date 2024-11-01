#include<iostream>
using namespace std;
int main(){
    cout<<"enter the number : ";
    int n;
    cin>>n;
    int k=1;
    int arr[n][n];
    int minr= 0, minc=0 , maxr = n-1 , maxc=n-1;
    while((minc<=maxc) && (minr<=maxr) && k<=(n*n)){
        for(int i=minc ; i<=maxc ; i++){
            arr[minr][i]=k;
            k++;
        }
        minr++;
        for(int i=minr ; i<=maxr ; i++){
            arr[i][maxc]=k;
            k++;
        }
        maxc--;
        for(int i=maxc ; i>=minc ; i--){
            arr[maxr][i]=k;
            k++;
        }
        maxr--;
        for(int i=maxr ; i>=minr ; i--){
            arr[i][minc]=k;
            k++;
        }
        minc++;
    }
    for(int i=0;i<n;i++){
        for(int j=0 ; j<n ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}