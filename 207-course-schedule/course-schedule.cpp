class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> vis(n);

        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        unordered_set<int> st;
        function<bool(int)> dfs = [&](int node){
            vis[node] = 1;
            st.insert(node);

            bool isCycle = false;
            for(int i = 0; i < adj[node].size(); i++){
                int child = adj[node][i];
                if(st.find(child) != st.end()) return true; 

                if(!vis[child]) isCycle = isCycle || dfs(child);
            }

            st.erase(node);
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