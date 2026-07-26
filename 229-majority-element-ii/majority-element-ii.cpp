class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        int checker = n/3 + 1;
        vector<int> ans;

        for(auto it:mpp){
            if(it.second >= checker) ans.push_back(it.first);
        }

        return ans;
    }
};