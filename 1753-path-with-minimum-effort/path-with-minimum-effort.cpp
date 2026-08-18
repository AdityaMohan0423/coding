class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int,int>> dxy = {{0,-1},{-1,0},{0,1},{1,0}};

        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        dis[0][0] = 0;

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto [wt,cell] = pq.top();
            pq.pop();
            int i = cell.first;
            int j = cell.second;

            if(wt > dis[i][j]) continue;

            for(int k = 0; k < 4; k++){
                int ni = i + dxy[k].first;
                int nj = j + dxy[k].second;

                if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                    int maxDis = max(dis[i][j],abs(heights[ni][nj]-heights[i][j]));
                    if(dis[ni][nj] > maxDis){
                        dis[ni][nj] = maxDis;
                        pq.push({dis[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        
        return ((dis[m-1][n-1] == INT_MAX) ? -1 : dis[m-1][n-1]);
    }
};