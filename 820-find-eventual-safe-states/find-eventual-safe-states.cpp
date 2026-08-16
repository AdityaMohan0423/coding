class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);

        for(int i = 0; i < n; i++){
            for(int j = 0 ; j <  graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        map<int,bool> mpp;

        function<bool(int)> dfs = [&](int node){
            mpp[node] = false;

            bool isBad = false;
            for(int i = 0; i < adj[node].size(); i++){
                int child = adj[node][i];
                if(mpp.find(child) != mpp.end() && mpp[child] == false) isBad = true;
                if(mpp.find(child) == mpp.end()) isBad = isBad || dfs(child); 
            }
            if(!isBad) mpp[node] = true;
            return isBad;
        };

        for(int i = 0; i < n; i++){
            if(vis[i] ==  0) dfs(i);
        }

        vector<int> ans;
        for(auto it:mpp){
            if(it.second == true) ans.push_back(it.first);
        }

        return ans;
    }
};