class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> mpp;
        set<vector<int>> st;
        vector<int> v(3);

        for(int i = 0; i < n; i++){
            mpp.clear();
            for(int j = i+1; j < n; j++){
                int temp = -1*(nums[i]+nums[j]);
                if(mpp.find(temp) != mpp.end()){
                    v = {nums[i],temp,nums[j]};
                    sort(v.begin(),v.end());
                    st.insert(v);
                }
                mpp[nums[j]]++;
            }
        }

        vector<vector<int>> ans;
        for(auto it:st){
            ans.push_back(it);
        }

        return ans;
    }
};