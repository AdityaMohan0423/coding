class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        long long sum = 0;
        long long maxi = 0;

        int i = 0, j = 0;
        for(;j < k; j++){
            mpp[nums[j]]++;
            sum += nums[j];
        }
        --j;

        while(j < n){
            if(maxi < sum && (mpp.size() == j-i+1)) maxi = sum;

            sum -= nums[i]; mpp[nums[i]]--;
            if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
            i++;

            if(j < n-1){
                ++j;
                mpp[nums[j]]++;
                sum += nums[j];
            }else j++;
        }

        return maxi;
    }
};