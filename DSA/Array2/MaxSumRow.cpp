#include<iostream>
using namespace std;
int main(){
    int arr[][4] = {{1, 3, 5, 7},
               {3, 4, 7, 8},
               {1, 4, 12, 3}};

    int x,max=0;
    for(int i=0 ; i<3 ; i++){
        int sum;
        for(int j=0 ; j<4 ; j++){
            sum+=arr[i][j];
        }
        if (max<=sum){
            max=sum;
            x=i;
        }
    }
    for(int j=0 ; j<4 ; j++){
        cout<<arr[x][j]<<" ";
    }
    return 0;
}
