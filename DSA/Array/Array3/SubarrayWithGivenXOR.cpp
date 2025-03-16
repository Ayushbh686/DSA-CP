int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    int n = A.size();
    
    unordered_map<int, int> mp; //xor , count
    
    mp[0] = 1;
    int xorr = 0;
    //finding the prefix xor ending at somw index less than i with value xor^B so that B can be found
    for(int i=0 ; i<n ; i++){
        xorr^=A[i];
        ans += mp[xorr^B];
        mp[xorr]++;
    }
    
    return ans;
}
//alternative will be n^2 to do nested loops
