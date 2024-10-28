#include <iostream>
using namespace std;
int main()
{
    int p, q, n, m;
    cout<<"enter the 1st array dimensions : ";
    cin>>p>>q;
    cout<<"enter the 2nd array dimensions : ";
    cin>>m>>n;
    int arr1[p][q];
    int arr2[m][n];
    int arr3[p][n];
    cout << "enter the 1st array elements : ";
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cin >> arr1[i][j];
        }
    }

    cout << "enter the 2nd array elements : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr2[i][j];
        }
    }

    cout << "resultant array :-" << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr3[i][j] = 0;
            for (int k = 0; k < q; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr3[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}