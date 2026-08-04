class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n+1);


        function<void(int)> dfs = [&](int node){
            vis[node] = 1;
            
            for(int j = 0; j < n; j++){
                   if((node-1 != j) && isConnected[node-1][j] == 1 && !vis[j+1]){
                    dfs(j+1);
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