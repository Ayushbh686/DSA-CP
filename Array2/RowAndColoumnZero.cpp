#include<iostream>
using namespace std;
int main(){
    int m ,n ;
    cout<<"enter the number of rows and coloumns:-";
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    bool flag = false;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0){
                for(int k=0; k<max(m,n) ; k++){
                    arr[i][k]=0;
                    arr[k][j]=0;
                }
                flag =true;
                break;
            }
        }
        if(flag ==  true) break;
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}