class Solution {
public:
    vector<int> p;

    int getLongest(int cen , bool odd){ //returning the longest palindrome subtring with cen index as centre and odd means # and even means actual character
        int pos = 2*cen + 1 + (!odd);
        return p[pos] - 1;
    }

    bool isPalindrome( int l , int r){ // is palindrome from l to r
        if( (r-l+1) <= getLongest((l+r)/2 , l%2 == r%2)){ // same parity means odd length 
            return true;
        }
    }

    void ManachersAlgo(string str){
        int n = str.size();
        p.assign(n, 1);
        int l = 1, r = 1;

        for(int i = 0; i < n; i++){
            if(i < r && (l + r - i) >= 0 && (l + r - i) < n)
                p[i] = max(0, min(r - i, p[l + r - i]));
            else
                p[i] = 0;

            while(i + p[i] < n && i - p[i] >= 0 && str[i + p[i]] == str[i - p[i]]){
                p[i]++;
            }

            if(i + p[i] > r){
                r = i + p[i];
                l = i - p[i];
            }
        }
    }


    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return "";
        
        string NewStr = "";
        for(int i = 0; i < n; i++){
            NewStr += '#';
            NewStr += s[i];
        }
        NewStr += '#';

        ManachersAlgo(NewStr);
        for(auto v : p) cout<<v<<" ";
        int maxIdx = max_element(p.begin(), p.end()) - p.begin();
        int l = (maxIdx - p[maxIdx] + 1) / 2;
        if(maxIdx < p[maxIdx]) l = 0;
        return s.substr(l, p[maxIdx] - 1);
    }
};
