class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        } 
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }

        vector<int> ans;
        while(k != 0){
            ans.push_back(pq.top().second);
            pq.pop();
            --k;
        }

        return ans;
    }
};