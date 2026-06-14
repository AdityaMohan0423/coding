class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        bool row1HasZero = false;
        bool col1HasZero = false;

        for(int j = 0; j < m; j++){
            if(matrix[0][j] == 0) row1HasZero = true;
        }
        for(int j = 0; j < n; j++){
            if(matrix[j][0] == 0) col1HasZero = true;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++){
             for(int j = 1; j < m; j++){
                if(!matrix[0][j] || !matrix[i][0]) matrix[i][j] = 0;
             }
        }

        

        if(row1HasZero){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        if(col1HasZero){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};