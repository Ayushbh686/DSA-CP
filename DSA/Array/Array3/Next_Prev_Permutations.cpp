class Solution {
    public:
    
        void rev(vector<int>& nums , int i , int j){
            while(i<=j){
                swap(nums[i] , nums[j]);
                i++;
                j--;
            }
            return ;
        }
    
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int idx ;
    
            for(int i=n-1 ; i>=0 ; i--){
                if(i == 0) idx = 0;
                else if(nums[i-1] < nums[i]){
                    idx = i;
                    break;
                }
            }
            // cout<<idx<<endl;
            if(idx == 0){
                rev(nums , 0 , n-1);
                return ;
            }
    
            rev(nums , idx , n-1);
            int nextMax = 0;
            for(int i=idx ; i<=n-1 ; i++){
                if(nums[i] > nums[idx-1]){
                    nextMax = i;
                    break;
                }
            }
            swap(nums[idx-1] , nums[nextMax]);
            return ;
        }
    };

/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        next_permutation(nums.begin() , nums.end() );
    }
};
*/



// prev permutation

// C++ program to print all permutations with
// duplicates allowed using prev_permutation()
#include <bits/stdc++.h>
using namespace std;

// Function to compute the previous permutation
bool prevPermutation(string& str)
{
    // Find index of the last element of the string
    int n = str.length() - 1;

    // Find largest index i such that str[i - 1] >
    // str[i]
    int i = n;
    while (i > 0 && str[i - 1] <= str[i])
        i--;

    // if string is sorted in ascending order
    // we're at the last permutation
    if (i <= 0)
        return false;

    // Note - str[i..n] is sorted in ascending order

    // Find rightmost element's index that is less
    // than str[i - 1]
    int j = i - 1;
    while (j + 1 <= n && str[j + 1] < str[i - 1])
        j++;

    // Swap character at i-1 with j
    swap(str[i - 1], str[j]);

    // Reverse the substring [i..n]
    reverse(str.begin() + i, str.end());

    return true;
}

// Driver code
int main()
{
    string str = "4321";
    if (prevPermutation(str))
        cout << "Previous permutation is " << str;
    else
        cout << "Previous permutation doesn't exist";
    return 0;
}


/*
// C++ program to demonstrate working of
// prev_permutation()
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    string str = "4321";
    if (prev_permutation(str.begin(), str.end()))
        cout << "Previous permutation is " << str;
    else
        cout << "Previous permutation doesn't exist";
    return 0;
}
*/