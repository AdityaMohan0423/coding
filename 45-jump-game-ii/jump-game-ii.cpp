class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int lastBubble = nums[0];
        int currBubble = 0;
        int cnt = 1;

        for(int i = 1; i < n-1; i++){
            currBubble = max(currBubble,nums[i]+i);
            if(lastBubble <= i){
                cnt++;
                lastBubble = currBubble;
                currBubble = 0;
            }
        }

        return (n == 1) ? 0 : cnt;
    }
};