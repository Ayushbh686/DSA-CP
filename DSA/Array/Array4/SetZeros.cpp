class Solution {
public:

    void setRow(vector<vector<int>>& matrix , int i){
        int m = matrix.size();
        int n = matrix[0].size();

        for(int c=0 ; c<n ; c++){
            matrix[i][c] = 0;
        }

        return ;
    } 

    void setCol(vector<vector<int>>& matrix , int j){
        int m = matrix.size();
        int n = matrix[0].size();

        for(int r=0 ; r<m ; r++){
            matrix[r][j] = 0;
        }

        return ;
    } 

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1; //from col0 with j=1 to j=n-1 will give us the coloumn to be set zero and i=0 to i = m-1 will give row to set 0

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0){
                        matrix[0][j] = 0;
                    }
                    else col0 = 0;
                }
            }
        }

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }


        for(int j=1 ; j<n ; j++){
            if(matrix[0][j] == 0) setCol(matrix , j);
        }

        for(int i=0 ; i<m ; i++){
            if(matrix[i][0] == 0) setRow(matrix , i);
        }
        
        if(col0 == 0) setCol(matrix , 0);

        return ;
    }
};