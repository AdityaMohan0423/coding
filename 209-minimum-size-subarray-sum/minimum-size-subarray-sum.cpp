class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        int sum = 0;
        int mini = INT_MAX;

        while(j < n){
            sum += nums[j];
            
            while(sum >= target){
                    mini = min(mini,j-i+1);
                    sum -= nums[i++];
            }
            j++;
        }
        if(sum >= target) mini = min(mini,j-i+1);

        return (mini == INT_MAX ? 0 : mini);
    }
};