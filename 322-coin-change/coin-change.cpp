class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));

        function<int(int,int)> dfs = [&](int i, int sum){
            if(sum == amount) return 0;
            if(sum > amount || i == n) return INT_MAX; 

            if(dp[i][sum] != -1) return dp[i][sum];

            int take = INT_MAX;
            if(coins[i] <= INT_MAX-sum) take = dfs(i,sum+coins[i]);
            int notTake = dfs(i+1,sum);

            if(take != INT_MAX) take += 1;

            return dp[i][sum] = min(take,notTake);
        };

        int result = dfs(0,0);
        return (result != INT_MAX ? result : -1);
    }
};