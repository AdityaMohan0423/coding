class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;
        int cnt = 1;
        int el = nums[0];

        int count = 1;

        while(j < n){
            if(nums[j] == el){
                if(cnt == 2){
                    while(j < n && nums[j] == el) j++;
                }else{
                    swap(nums[i+1],nums[j]);
                    cnt++;
                    count++;
                    i++;
                    j++;
                }
            }else{
                el = nums[j];
                cnt = 1;
                swap(nums[i+1],nums[j]);
                count++;
                j++;
                i++;
            }
        }
        return count;
    }
};