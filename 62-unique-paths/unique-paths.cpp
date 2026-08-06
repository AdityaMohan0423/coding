class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));

        function<int(int,int)> dfs = [&](int i, int j){
            if(i >= m || j >= n) return 0;
            if(i == m-1 && j == n-1) return 1;

            if(dp[i][j] != -1) return dp[i][j];

            int path1 = dfs(i+1,j);
            int path2 = dfs(i,j+1);

            return dp[i][j] = path1 + path2;
        };

        return dfs(0,0);
    }
};