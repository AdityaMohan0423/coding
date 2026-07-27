class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mpp;

        int cnt = 0;

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == k) cnt++;
            if(mpp.find(sum-k) != mpp.end()){
                cnt += mpp[sum-k];
            }
            mpp[sum]++;
        }

        return cnt;
    }
};