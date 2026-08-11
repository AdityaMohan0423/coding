class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        function<int(int,int)> dfs = [&](int i, int j){
            if(i > j) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int total = 1e9;    

            if(s[i] != s[j]){
                total = 1 + min(dfs(i+1,j),dfs(i,j-1));
            }else{
                total = dfs(i+1,j-1);
            }

            return dp[i][j] = total;
        };
        int ans = dfs(0,n-1);

        return (ans == 1e9 ? n : ans);
    }
};