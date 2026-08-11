class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        // function<int(int,int)> dfs = [&](int i, int j){
        //     if(i > j) return 0;

        //     if(dp[i][j] != -1) return dp[i][j];
        //     int take = 0;
        //     if(s[i] == s[j]){
        //         take = ((i != j) ? 2 + dfs(i+1,j-1) : 1);
        //     }else{
        //         take = max(dfs(i,j-1),dfs(i+1,j));
        //     }

        //     return dp[i][j] = take;
        // };
        // return dfs(0,n-1);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == s[n-j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }

        return dp[n][n];
    }
};