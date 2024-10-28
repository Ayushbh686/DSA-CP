#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int smallest = -1, largest = -1;
    for (int i = 0; i < 31; i++)
    {
        if (n & (1 << i))
        {
            smallest = i;
            break;
        }
    }
    for (int i = 30; i >= 0; i--)
    {
        if (n & (1 << i))
        {
            largest = i;
            break;
        }
    }
    cout << smallest << " " << largest << '\n';
}
// 1 0 1 1 1 can be optimised  