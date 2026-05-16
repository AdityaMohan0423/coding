class Solution {
public:
    bool compare(string s1, string s2){
    int i = 0, j = 0;

    while(i < s1.size() && j < s2.size()){
        if(s1[i] == s2[j]){
            i++;
        }
        j++;
    }

    return i == s1.size();
}

    int longestStrChain(vector<string>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),[](string &a, string &b){
            return a.length() < b.length();
        });

        vector<vector<int>> dp(n+2,vector<int>(n+1,-1));
        function<int(int,int)> dfs = [&](int i, int par){
            if(i > n) return 0;

            if(dp[i][par] != -1) return dp[i][par]; 
            int take = 0;
            if(par == 0 || ((nums[par-1].size() == nums[i-1].size()-1) && compare(nums[par-1],nums[i-1]))){
                take = 1 + dfs(i+1,i);
            }
            int notTake = dfs(i+1,par);

            return dp[i][par] = max(take,notTake);
        };

        return dfs(1,0);
    }
};