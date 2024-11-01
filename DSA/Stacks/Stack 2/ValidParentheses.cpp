#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n%2 == 1) return false;
        stack<char> stk;
        for(int i=0 ; i<n ; i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '[') stk.push(s[i]);
            else {
                if(stk.size() > 0 and stk.top() == '(' and s[i] == ')') stk.pop();
                else if(stk.size() > 0 and stk.top() == '[' and s[i] == ']') stk.pop();
                else if(stk.size() > 0 and stk.top() == '{' and s[i] == '}') stk.pop();
                else return false;
            }
        }
        if(stk.size() > 0) return false;
        return true;
    }
};

int main(){
    Solution sol;
    cout<<sol.isValid("()()()()");
}