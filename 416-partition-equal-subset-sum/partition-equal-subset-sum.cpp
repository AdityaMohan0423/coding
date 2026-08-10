class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        }

        if(total_sum%2 != 0) return false;

        vector<vector<bool>> dp(n+1,vector<bool> (total_sum/2 + 1 ,0));

        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= total_sum/2; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
            }
        }

        return dp[n][total_sum/2];
    }
};