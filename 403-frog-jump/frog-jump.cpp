class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int lastEl = stones[n-1];

        unordered_map<string,bool> dp;

        if(stones[1] != 1) return false;

        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++){
            mpp[stones[i]]++;
        }

        function<bool(int,int)> dfs = [&](int stair, int k){
            if(stair == lastEl) return true;
            if(k == 0) return false;
            if(mpp.find(stair) == mpp.end()) return false;

            string toFind = to_string(stair) + '_' + to_string(k);

            if(dp.find(toFind) != dp.end()) return dp[toFind];

            bool jump1 = dfs(stair + k - 1, k - 1);
            bool jump2 = dfs(stair + k, k);
            bool jump3 = dfs(stair + k + 1, k + 1);

            return dp[toFind] = (jump1 || jump2 || jump3);
        };

        return dfs(1,1);
    }
};