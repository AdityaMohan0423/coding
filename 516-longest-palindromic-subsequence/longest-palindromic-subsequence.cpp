class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        function<int(int,int)> dfs = [&](int i, int j){
            if(i > j) return 0;

            if(dp[i][j] != -1) return dp[i][j];
            int take = 0;
            if(s[i] == s[j]){
                take = ((i != j) ? 2 + dfs(i+1,j-1) : 1);
            }else{
                take = max(dfs(i,j-1),dfs(i+1,j));
            }

            return dp[i][j] = take;
        };

        return dfs(0,n-1);
    }
};