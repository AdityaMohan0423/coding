class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp1(n,-1);
        dp1[1] = nums[1];
        for(int i = 2; i < n; i++){
            dp1[i] = dp1[i-1];
            dp1[i] = max(dp1[i],nums[i] + (i > 2 ? dp1[i-2] : 0));
        }


        vector<int> dp2(n,-1);
        dp2[0] = nums[0];
        for(int i = 1; i < n-1; i++){
            dp2[i] = dp2[i-1];
            dp2[i] = max(dp2[i],nums[i] + (i > 1 ? dp2[i-2] : 0));
        }

        return max(dp1[n-1],dp2[n-2]);
    }
};