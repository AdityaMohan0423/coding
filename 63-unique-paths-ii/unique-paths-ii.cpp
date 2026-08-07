class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));


        function<int(int,int)> dfs = [&](int i, int j){
            if(i >= m || j >= n) return 0;
            if(obstacleGrid[i][j] == 1) return 0;
            if(i == m-1 && j == n-1) return 1;
            
            if(dp[i][j] != -1) return dp[i][j];

            int path1 = 0,path2 = 0;
            if(i < m) path1 = dfs(i+1,j);
            if(j < n) path2 = dfs(i,j+1);

            return dp[i][j] = path1 + path2;
        };

        return dfs(0,0);
    }
};