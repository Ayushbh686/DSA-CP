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
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >= 1 && v[j] < v[j - 1])
        {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
    cout << "the sorted array is : ";
    for (int ele : v)
    {
        cout << ele << " ";
    }
    return 0;
}