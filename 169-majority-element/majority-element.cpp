class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int currEl = nums[0];
        int cnt = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] == currEl) cnt++;
            else if(cnt != 0) cnt--;
            else{
                cnt = 1;
                currEl = nums[i];
            }
        }

        return currEl;
    }
};