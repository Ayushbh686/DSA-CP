class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1){
          left = max(mpp[s[right]] + 1, left); 
        //   cout<<s[right]<<" found , left "<<left<<" , right "<<right<<endl;
        }
        // else{
        //     cout<<s[right]<<" not found , left "<<left<<" , right "<<right<<endl;
        // }
        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
//taking max in case of both the right and len is so that we dont have to remove charcters before left in case we increment left(although that will not affect TC much it will only be 2*N) , and if doubt uncomment the part and run on efdvdfeghk