#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int m = sizeof(arr);
    int n =sizeof(arr[0]);
    cout<<m<<n<<endl;
    for(int i = 0; i <3;i++){
        if(i%2==0){
            for(int j=2;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
        else {
            for(int j=0;j<3;j++){
                cout<<arr[j][i]<<" ";
            }
        }
    }
    return 0;
}