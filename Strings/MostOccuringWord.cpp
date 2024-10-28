#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    string str="Ayush Bhagat is learning DSA. Ayush is also learning webd";
    stringstream ss(str);
    string temp;
    vector<string> v;
    while(ss>>temp){
       v.push_back(temp);
    }
    cout<<endl;
    sort(v.begin(), v.end());
    int max = 0;
    int count = 1;
    for(int i=0 ; i<v.size() ; i++){
        if(v[i]==v[i-1]) count++;
        else count = 1;
        if(max<count ) max=count;
    }
    count = 1;
    for(int i = 0 ; i<v.size() ; i++){
        if(v[i]==v[i-1]) count++;
        else count = 1;
        if(count == max) cout<<v[i]<<" "<<max<<endl;
    }
    return 0;
    
}