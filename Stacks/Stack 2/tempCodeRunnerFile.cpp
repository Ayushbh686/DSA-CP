#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        string ans;
        for(int i=0 ; i<s.size(); i++){
            if( !stk.empty() && s[i]==(char)stk.top()) stk.pop();
            else stk.push(s[i]);
        }
        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.removeDuplicates("abbaca")<<endl;
    cout<<sol.removeDuplicates("aaabbcddaabffg");
}