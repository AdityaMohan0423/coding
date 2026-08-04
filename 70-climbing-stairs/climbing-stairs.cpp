class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n+1,-1);

        function<int(int)> dfs = [&](int stair){
            if(stair == n) return 1;
            if(stair > n) return 0;

            if(v[stair] != -1) return v[stair];

            int oneStep = dfs(stair + 1);
            int twoStep = dfs(stair + 2);

            return v[stair] = oneStep + twoStep;
        };

        return dfs(0);
    }
};