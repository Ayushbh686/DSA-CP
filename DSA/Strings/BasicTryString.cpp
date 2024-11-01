#include<iostream> 
#include<string>
using namespace std;
int main(){
    // int n;
    // cin>>n;
    string str="ayush";
    str.push_back('b');
    cout<<str;
}
//whats wrong with 2 ways of declaring stringchar str[] is a fixed-size array, while string str is a dynamic object.
//C++ strings (std::string) offer higher-level abstractions and are generally preferred for string manipulation due to their flexibility and ease of use.
//C-style strings (char[]) are still used in certain scenarios, especially when dealing with legacy code or interfacing with C libraries that expect null-terminated character arrays.
