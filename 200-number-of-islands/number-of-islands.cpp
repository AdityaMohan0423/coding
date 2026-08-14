class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));

        function<void(int,int)> dfs = [&](int i, int j){
            if(i < 0 || i >= m || j < 0 || j >= n || (vis[i][j] == 1) || (grid[i][j] != '1') ) return;
            vis[i][j] = 1; 

            dfs(i-1,j);
            dfs(i,j+1);
            dfs(i+1,j);
            dfs(i,j-1);
        };

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};