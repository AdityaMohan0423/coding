class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double,int>>> adj(n);
        vector<double> dis(n,0);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }

        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        dis[start_node] = 1;

        while(!pq.empty()){
            auto [wt,node] = pq.top(); pq.pop();
            
            for(int i = 0; i < adj[node].size(); i++){
                auto [cost,child] = adj[node][i];
                if(cost*wt > dis[child]){
                    dis[child] = cost*wt;
                    pq.push({cost*wt,child});
                }
            }
        }

        return dis[end_node];

    }

};