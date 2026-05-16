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

        // return dfs(1,0);

        //tabulation.
        vector<vector<int>> DP(n+2,vector<int> (n+1,0));
        
        for(int i = n; i > 0; i--){
            for(int j = n; j >= 0; j--){
                int take = 0;
                if(j == 0 || ((nums[j-1].size() == nums[i-1].size()-1) && compare(nums[j-1],nums[i-1]))){
                    take = 1 + DP[i+1][i];
                }
                int notTake = DP[i+1][j];

                DP[i][j] = max(take,notTake);
            }
        }

        return DP[1][0];
    }
};