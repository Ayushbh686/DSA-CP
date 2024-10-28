#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "enter the three numbers : ";
    cin >> a >> b >> c;

    // if (a > b)
    // {
    //     if (a > c)
    //         cout << a << " is greatest";
    //     else
    //         cout << c << " is greatest";
    // }
    // else
    // {
    //     if (a > c)
    //         cout << b << " is greatest";
    //     else
    //         cout << c << " is greatest";
    // }

    int max = a;
    if (b > a)
    {
        max = b;
        if (c > max)
            max = c;
    }
    else
    { // a>b
        if (c > a)
            max = c;
    }
    cout << max << " is greatest";
    return 0;
}


// every if statement is checked (ordering does not matter)
// else if statement is checked if previous statement not true (ordering does matter)
// else will be checked only if every statement is false (ordering matter as else will always be last)
