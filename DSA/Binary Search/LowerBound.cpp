#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 6, 9, 10, 35, 78};
    int n = 9;
    int x = 9;
    int lo = 0, hi = 8;
    bool flag = false;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x)
        {
            cout << arr[mid-1];
            flag = true;
            break;
        }
        else if (arr[mid] > x)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    if (flag == false)
        cout << arr[hi];
    return 0;
}