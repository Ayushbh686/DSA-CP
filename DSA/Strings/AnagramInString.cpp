#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string p;
    cout<<"enter the main string : ";
    getline(cin,s);
    cout<<"enter the small string : ";
    getline(cin,p);
    vector<int> v;
    int n=s.size();
    int m=p.size();
    for(int i=0 ; i<n ; i++){
        string temp1 , temp2;
        bool flag=true;
        for(int j=i; j<i+m ; j++){
            temp1 += s[j];
        }
        for(int j=0; j<m ; j++){
            temp2 += p[j];
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        for(int j =0 ; j<m ; j++){
            if(temp1[j] != temp2[j]) flag=false;
        }
        if(flag == true) v.push_back(i);
            // cout<<i;}
    }
    cout<<"the following are the indices : ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
//alternative -->sliding window solution -->make seprate array for both strings character frequency and compare 
//them instead of sorting and comparing and for modfying succesively decrease the frequnecy of prev element
//and add the frequency of next element.