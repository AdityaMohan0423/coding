class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        set<vector<int>> st;
        vector<int> v(4);
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                mpp.clear();
                for(int k = j+1; k < n; k++){
                    long long sum = 1LL*nums[i] + nums[j] + nums[k];
                    long long complement = (long long)target - sum;

                    
                    if(complement >= INT_MIN && complement <= INT_MAX){
                        if(mpp.find(int(target-sum)) != mpp.end()){
                        v = {nums[i],nums[j],nums[k],int(complement)};
                        sort(v.begin(),v.end());

                        st.insert(v);
                    }
                    }
                    mpp[nums[k]]++;
                }
            }
        }

        for(auto it:st) ans.push_back(it);

        return ans;
    }
};