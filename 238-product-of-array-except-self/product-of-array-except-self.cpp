class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<long long> preProd(n,1),sufProd(n,1);
        
        preProd[0] = nums[0];
        sufProd[n-1] = nums[n-1];

        for(int i = 1; i < n; i++){
            preProd[i] = nums[i]*preProd[i-1];
            sufProd[n-1-i] = nums[n-1-i]*sufProd[n-i];
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(i+1 < n) ans[i] = sufProd[i+1];
            }else if(i == n-1){
                if(i-1 >= 0) ans[i] = preProd[i-1];
            }else{
                if(i+1 < n) ans[i] = sufProd[i+1];
                if(i-1 >= 0) ans[i] *= preProd[i-1];
            }
        }

        return ans;
    }
};