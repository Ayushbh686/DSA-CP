#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout << "enter the number of elements : ";
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX;
        int mindx = -1;
        for (int j = i; j < n; j++)
        {
            if (v[j] < min)
            {
                min = v[j];
                mindx = j;
            }
        }
        swap(v[i], v[mindx]);
    }
    cout << "the sorted array is : ";
    for (int ele :v)
    {
        cout << ele << " ";
    }
}