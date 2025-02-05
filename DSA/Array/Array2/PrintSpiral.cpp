#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"enter the number of rows and coloumns : ";
    cin>>m>>n;
    int arr[m][n];
    cout<<"enter the elements : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int minc=0, minr=0;
    int maxc=(n-1), maxr=(m-1);
    int tne=n*m;
    int count=0;
    while((maxr>=minr) && (maxc>=minc)){
        for(int i=minc; i<=maxc ,count<=tne ; i++){
            cout<<arr[minr][i]<<" ";
            count++;
        }
        minr++;
        for(int i=minr; i<=maxr ,count<=tne; i++){
            cout<<arr[i][maxc]<<" ";
            count++;
        }
        maxc--;
        for(int i=maxc; i>=minc ,count<=tne; i--){
            cout<<arr[maxr][i]<<" ";
            count++;
        }
        maxr--;
        for(int i=maxr; i>=minr ,count<=tne ; i--){
            cout<<arr[i][minc]<<" ";
            count++;
        }
        minc++;
    }

}