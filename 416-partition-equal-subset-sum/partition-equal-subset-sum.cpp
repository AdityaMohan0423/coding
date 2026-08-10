class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        }

        if(total_sum%2 != 0) return false;

        vector<bool> dp(total_sum/2 + 1,false);

        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = total_sum/2; j > 0; j--){
                if(j >= nums[i-1]) dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }

        return dp[total_sum/2];
    }
};