class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(matrix[i][j] == target) return true;
            if(i+1 < n && matrix[i+1][j] <= target){
                i++;
            }else{ 
                j++;
            }
        }

        return false;
    }
};