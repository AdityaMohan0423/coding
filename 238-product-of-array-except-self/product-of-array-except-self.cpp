class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;

        int preProd = nums[0];
        for(int i = 1; i < n; i++){
            ans[i] = preProd;
            preProd *= nums[i];
        }

        int sufProd = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i] *= sufProd;
            sufProd *= nums[i];
        }

        return ans;
    }
};