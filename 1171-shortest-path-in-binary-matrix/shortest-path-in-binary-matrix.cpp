class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        vector<pair<int,int>> dxy = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

        vector<vector<int>> dis(n,vector<int> (n,INT_MAX));
        dis[0][0] = 1;
        pq.push({1,{0,0}});

        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            int i = node.first;
            int j = node.second;

            if(wt > dis[i][j]) continue;

            for(int k = 0 ; k < 8; k++){
                int ni = i + dxy[k].first;
                int nj = j + dxy[k].second;
                if(ni >= 0 && ni < n && nj >= 0 && nj < n && (grid[ni][nj] == 0) && (wt + 1 < dis[ni][nj])){
                    dis[ni][nj] = wt + 1;
                    pq.push({wt+1,{ni,nj}});
                }
            }
        }

        int ans = dis[n-1][n-1];
        return ((ans == INT_MAX) ? -1 : ans);
    }
};