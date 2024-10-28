#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){

    //only small letters

    // string s;
    // cout<<"enter the string : ";
    // getline(cin,s);
    // int n=s.length();
    // char ch;
    // int max=0;
    // for(int i = 0 ; i<n ; i++){
    //     ch=s[i];
    //     int count =1;
    //     for(int j=i+1; j<n ; j++){
    //         if(s[j]==s[i]) count++;
    //     }
    //     if(max<count) max=count;
    // }

    // for(int i = 0 ; i<n ; i++){
    //     ch=s[i];
    //     int count =1;
    //     for(int j=i+1; j<n ; j++){
    //         if(s[j]==s[i]) count++;
    //     }
    //     if(count == max) {
    //         cout<<ch<<" "<<max<<endl;
    //     }
    // }
    // return 0;

    //BETTER ALTERNATIVE
    string s;
    cout<<"enter the string : ";
    getline(cin,s);
    int n=s.length();
    vector<int>arr(26,0);
    for(int i=0 ; i<n ; i++){
        int x=(int)s[i];
        arr[x-97]++;
    }
    int max=0;
    for(int i=0 ; i<n ; i++){
        if(max<arr[i]) max=arr[i];
    }
    for(int i=0 ; i<n ; i++){
        if(arr[i]==max){
            cout<<(char)(97+i)<<" "<<arr[i]<<endl;
        }
    }
    return 0;
}