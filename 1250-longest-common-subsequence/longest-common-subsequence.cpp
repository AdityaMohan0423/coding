class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1,vector<int> (n2,-1));

        function<int(int,int)> dfs = [&](int i, int j){
            if(i == n1 || j == n2) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int total = 0;
            if(text1[i] == text2[j]){
                total = 1 + dfs(i+1,j+1);
            }else{
                total = max(dfs(i+1,j),dfs(i,j+1));
            }

            return dp[i][j] = total;
        };

        return dfs(0,0);
    }
};