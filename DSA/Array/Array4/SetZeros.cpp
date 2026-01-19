class Solution {
public:

    void setRowZero(vector<vector<int>>& matrix , int i){
        for(int j=0 ; j<matrix[0].size() ; j++){
            matrix[i][j] = 0;
        }
        return;
    }

    void setColZero(vector<vector<int>>& matrix , int i){
        for(int j=0 ; j<matrix.size() ; j++){
            matrix[j][i] = 0;
        }
        return;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirstRowZero = false;
        bool isFirstColZero = false;

        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == 0){
                    if(i==0) isFirstRowZero = true;
                    if(j==0) isFirstColZero = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1 ; i<n ; i++){
            if(matrix[i][0] == 0) setRowZero(matrix , i);
        }

        for(int i=1 ; i<m ; i++){
            if(matrix[0][i] == 0) setColZero(matrix , i);
        }

        if(isFirstRowZero) setRowZero(matrix , 0);
        if(isFirstColZero) setColZero(matrix , 0);

        return;

    }
};