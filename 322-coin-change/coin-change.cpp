class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int> (amount+1,-1));

        // function<int(int,int)> dfs = [&](int i, int sum){
        //     if(sum == amount) return 0;
        //     if(sum > amount || i == n) return INT_MAX; 

        //     if(dp[i][sum] != -1) return dp[i][sum];

        //     int take = INT_MAX;
        //     if(coins[i] <= INT_MAX-sum) take = dfs(i,sum+coins[i]);
        //     int notTake = dfs(i+1,sum);

        //     if(take != INT_MAX) take += 1;

        //     return dp[i][sum] = min(take,notTake);
        // };

        // int result = dfs(0,0);
        // return (result != INT_MAX ? result : -1);

        vector<vector<int>> dp(n+1,vector<int> (amount+1,INT_MAX));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= coins[i-1] && dp[i][j-coins[i-1]] != INT_MAX) dp[i][j] = min(dp[i][j],dp[i][j-coins[i-1]] + 1);
            }
        }

        return (dp[n][amount] == INT_MAX ? -1 : dp[n][amount]);
    }
};