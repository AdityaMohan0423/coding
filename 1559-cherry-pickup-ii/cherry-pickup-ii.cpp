class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
 

        function<int(int,int, int)> dfs = [&](int i,int j1, int j2){

            if(i == n-1) return ( (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]);

            if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

            int maxi = 0;
            for(int j = -1; j <= 1; j++){
                int ni = i + 1;
                int nj = j1 + j;
                if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                    for(int k = -1; k <= 1; k++){
                        int njj = j2 + k;
                        if(njj >= 0 && njj < m){
                            maxi = max(maxi,dfs(ni,nj,njj));
                        }
                    }
                }
            }

            dp[i][j1][j2] = ((j1 == j2) ? maxi + grid[i][j1] : maxi + grid[i][j1] + grid[i][j2]);
            return dp[i][j1][j2];
        };

        return dfs(0,0,m-1);
    }
};