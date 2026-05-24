class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        /*
        for ith to be celeb:-
        mat[i][var] = 0; (var != i)
        but mat[var][i] = 1; 
        */
        
        
        //stack approach
        int n = mat.size();
        
        stack<int>stk;
        
        for(int i=0 ; i<n ; i++) stk.push(i);
        
        while(stk.size() > 1){
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            
            if(mat[a][b] == 1){
                stk.push(b);
                continue;
            }
            else if(mat[a][b] == 0){
                stk.push(a);
                continue;
            }
        }
        
        int x = stk.top();
        
        for(int i=0 ; i<n ; i++){
            if(i == x) continue;
            if(mat[i][x] == 0 or mat[x][i] == 1) return -1;
        }
        
        return x;
        
        
        //2nd two pointer approach
        /*
        int n = mat.size();

        int i = 0, j = n - 1;
        while (i < j) {
            
            // j knows i, thus j can't be celebrity
            if (mat[j][i] == 1) 
                j--;
    
            // else i can't be celebrity
            else
                i++;
        }
    
        // i points to our celebrity candidate
        int c = i;
    
        // check if c is actually
        // a celebrity or not
        for (i = 0; i < n; i++) {
            if(i == c) continue;
    
            // if any person doesn't
            // know 'c' or 'c' doesn't
            // know any person, return -1
            if (mat[c][i] || !mat[i][c])
                return -1;
        }
    
        return c;
        */
        
    }
};