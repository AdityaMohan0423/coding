class Solution {
public:
    int dfs(int i, int sum,vector<int>& coins,vector<vector<int>> &dp){
        if(sum == 0) return 1;
        if(sum < 0 || i == coins.size()) return 0;

        if(dp[i][sum] != -1) return dp[i][sum];

        int take = dfs(i,sum-coins[i],coins,dp);
        int notTake = dfs(i+1,sum,coins,dp);

        return dp[i][sum] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));

        return dfs(0,amount,coins,dp);
    }
};