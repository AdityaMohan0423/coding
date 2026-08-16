class Solution {
public:
    void dfs(int node, int &flag,vector<vector<int>> &adj,vector<int> &vis){
        vis[node] = 1;

            for(int i = 0; i < adj[node].size(); i++){
                int child = adj[node][i];
                if(vis[child] == 1){
                    flag = 1;
                    return;
                }
                dfs(child,flag,adj,vis);
            }

            if(flag == 0) vis[node] = 2;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);

        for(int i = 0; i < n; i++){
            for(int j = 0 ; j <  graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        function<bool(int)> dfs = [&](int node){
            vis[node] = 1;

            bool isCycle = false;
            for(int i = 0; i < adj[node].size(); i++){
                int child = adj[node][i];
                if(vis[child] == 1) return true;
                if(!vis[child]) isCycle = isCycle || dfs(child);
            }
            if(!isCycle) vis[node] = 2;
            return isCycle;
        };

        for(int i = 0; i < n; i++){
            if(vis[i] ==  0) dfs(i);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(vis[i] == 2) ans.push_back(i);
        }

        return ans;
    }
};