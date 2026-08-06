class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        function<int(int)> dfs = [&](int i){
            if(i >= n) return 0;
            if(i == n-1) return nums[n-1];

            if(dp[i] != -1) return dp[i];

            int rob = nums[i] + dfs(i+2);
            int skip = dfs(i+1);

            return dp[i] = max(rob,skip);
        };

        return dfs(0);
    }
};