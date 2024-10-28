#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int n;
    cout << "enter the number of elements : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            swap(v[i],v[i+1]);
            i++;
        }
    }
    bool flag =true;
    for(int i =0 ;i<n-1;i++){
        if(v[i]>v[i+1]) flag=false;
    }
    if(flag==false) cout<<"not almost sorted";
    else cout<<"almost sorted";
}
//alternate is making another array with sorted and check if difference in of less than one place