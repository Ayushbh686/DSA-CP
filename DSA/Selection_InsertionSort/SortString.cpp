#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int n;
    cout << "enter the number of elements : ";
    cin >> n;
    vector<string>v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < n - 1; i++)
    { // n-1 passes
        int swaps = 0;
        for (int j = 0; j < n - 1 - i; j++)
        { // n-1-i iterations
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                swaps++;
            }
        }
        if (swaps == 0)
            break;
    }
    cout<<"sorted array : ";
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
}