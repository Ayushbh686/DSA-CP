#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number : ";
    cin >> n;

    // if ((n % 3 == 0 || n % 5 == 0) && n % 15 != 0)    // bracket required as && is greater in hierarchy than ||
    // {
    //     cout << "condition matching";
    // }
    // else
    //     cout << "condition not matching";

    if (n % 3 == 0 || n % 5 == 0) // bracket required as && is greater in hierarchy than ||
    {
        if (n % 15 != 0)
        {
            cout << "condition matching";
        }
        else
            cout << "condition not matching";
    }
    else
        cout << "condition not matching";

    return 0;
}

// prittier extension alt+shift+f