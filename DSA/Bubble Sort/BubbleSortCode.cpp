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

    // bubblesort
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
    cout << "the sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
