class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int bubble = 0;

        for(int i = 0; i < n-1; i++){
            if(bubble < i) return false;
            bubble = max(bubble,nums[i]+i);
        }

        return (bubble >= n-1) ? true : false;
    }
};