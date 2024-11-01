#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ans = 0, l = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            l++;
        else
        {
            ans += (l * (l + 1)) / 2;
            l = 0;
        }
    }
    ans += l * (l + 1) / 2;
    cout << ans;
}