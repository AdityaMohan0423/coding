class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();

        int rottenCount = 0;
        int freshCount = 0;

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    rottenCount++;
                    q.push({i,j});
                }
                if(grid[i][j] == 1) freshCount++;
            }
        }

        if(freshCount == 0) return 0;
        if(rottenCount == 0) return -1;
        if(rottenCount == n*m) return 0;

        vector<vector<int>> vis(m,vector<int> (n));
        vector<pair<int,int>> dxy = {{-1,0},{0,1},{1,0},{0,-1}};


        
        int timer = -1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [x,y] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int ni = x + dxy[j].first;
                    int nj = y + dxy[j].second;

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj] && grid[ni][nj] == 1){
                        vis[ni][nj] = 1;
                        q.push({ni,nj});
                    }
                }
            }

            timer++;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }

        return timer;
    }
};