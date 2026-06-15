class Solution {
    void doShit(int i, vector<int>& nums, int &n){
        for(int j = n-1; j > i; j--){
            if(nums[j] > nums[i]){
                swap(nums[j],nums[i]);
                reverse(nums.begin()+i+1,nums.end());
                break;
            }
        }
    }
public:
    bool isSorted = true;
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        for(int i = n-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                doShit(i-1,nums,n);
                isSorted = false;
                break;
            }
        }

        if(isSorted) reverse(nums.begin(),nums.end());
    }
};