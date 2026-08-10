class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        }

        vector<vector<int>> dp(n,vector<int> (total_sum+1,-1));
        function<bool(int,int)> dfs = [&](int i, int sum){
            if(sum > total_sum-sum || i >= n) return false;
            if(sum == total_sum-sum) return true;

            if(dp[i][sum] != -1) return ((dp[i][sum] == 0) ? false : true);

            bool take = dfs(i+1,sum + nums[i]);
            bool notTake = dfs(i+1,sum);

            bool ans = take || notTake;
            dp[i][sum] = ((ans == false) ? 0 : 1);

            return ans; 
        };

        return dfs(0,0);
    }
};