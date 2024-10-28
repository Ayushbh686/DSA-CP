#include <iostream>
using namespace std;
int main()
{
    int x = 5;
    int y = 4;
    int z = x / y;
    cout << z << endl;
    float w = x / y;
    cout << w << endl;
    w = (float)x / y;
    cout << w << endl;
    cout << x++ << endl;
    cout << ++x << endl;
    cout << x-- << endl;
    cout << --x << endl;
    cout << 5 / 4 << endl; // if any one is float then answer will be float otherwise it will be integer
    cout << 5 / 4.0 << endl;
    cout << 5.5 << endl;
    cout << 3.14 + 5 << endl;

    //  REMAINDER
    int a = 16, b = 3;
    int r;
    r = a - b * (16 / 3);
    cout << "the remainder is " << r << endl;
    r = a % b;
    cout << r;
    // a % b = a % (-b)
    // (-a) % b = - (a % b)
    // (-a) % (-b) = -(a % b)
    // a and b must be int data type otherwose it will give error in c++ language only 
    return 0;
}