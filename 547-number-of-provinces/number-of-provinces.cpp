class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(isConnected[i][j] == 1) adj[i+1].push_back(j+1);
            }
        }

        function<void(int)> dfs = [&](int node){
            vis[node] = 1;
            
            for(int i = 0; i < adj[node].size(); i++){
                int currNode = adj[node][i];

                if(!vis[currNode]){
                    dfs(currNode);
                }
            }
        };

        int cnt = 0;

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
                cnt++;
            }
        }

        return cnt;
    }
};