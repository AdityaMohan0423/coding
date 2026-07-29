class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1, k = n-1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        while(i < n){
            if(i != 0){
                while(i < n && nums[i] == nums[i-1]) ++i;
            }
            j = i+1;
            k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }else if(sum > 0){
                    k--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j < n && nums[j] == nums[j-1]) j++;
                    while(k >= 0 && nums[k] == nums[k+1]) k--;
                }
            }
            i++;
        }

        return ans;
    }
};