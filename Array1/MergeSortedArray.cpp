#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1 = {1, 4, 5, 8};
    vector<int> v2 = {2, 3, 7, 10, 12};
    vector<int> v3(9);
    int i = 0, j = 0, k = 0;
    while (k < 9)
    {
        if (i >= 4)
        {
            v3[k] == v2[j];
            k++;
            j++;
        }
        else if (j >= 5)
        {
            v3[k] == v1[i];
            k++;
            i++;
        }
        else if (v1[i] >= v2[j])
        {
            v3[k] = v2[j];
            k++;
            j++;
        }
        else if (v1[i] < v2[j])
        {
            v3[k] = v1[i];
            k++;
            i++;
        }
    }
    for( int w=0 ; w< 9 ; w++){
        cout<<v3[w]<<" ";
    }
    return 0;
}