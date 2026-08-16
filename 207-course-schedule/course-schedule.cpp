class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);

        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        function<bool(int)> dfs = [&](int node){
            vis[node] = 1;

            bool isCycle = false;
            for(int i = 0; i < adj[node].size(); i++){
                int child = adj[node][i];
                if(vis[child] == 1) return true; 

                if(!vis[child]) isCycle = isCycle || dfs(child);
            }

            vis[node] = 2;
            return isCycle;
        };

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(i)) return false;
            }
        }

        return true;
    }

};