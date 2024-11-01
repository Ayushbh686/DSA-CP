#include <iostream>
#include <vector>
using namespace std;
void subseq(vector<int> &v, vector<int> ans, int k, int idx)
{
        if (ans.size() == k )
        {
            for (int i = 0; i < k; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            return;
        }
        if(idx== v.size() || ans.size()+(v.size()-idx) < k) return; //2nd condition improves time complexity 
    subseq(v, ans, k, idx + 1);
    ans.push_back(v[idx]);
    subseq(v, ans, k, idx + 1);
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> ans;
    int k = 3;
    subseq(v, ans, k, 0);
}