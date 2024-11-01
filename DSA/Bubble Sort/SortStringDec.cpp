#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "AZYZXBDJKX";
    string s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'X')
            s.push_back(str[i]);
    }
    cout << "string is : " << s << endl;
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        int swaps=0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (s[j] < s[j + 1])
            {
                swap(s[j], s[j + 1]);
                swaps++;
            }
        }
        if(swaps==0) {
                break;
            }
    }
    cout << "the resulting array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
}