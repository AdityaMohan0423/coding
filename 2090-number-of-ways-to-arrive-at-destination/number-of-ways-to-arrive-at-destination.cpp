class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pair<long long,int>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({wt,v});
            adj[v].push_back({wt,u});
        }

        vector<long long> dis(n,LLONG_MAX);
        vector<long long> ways(n,0);
        

        priority_queue< pair<long long,int> , vector<pair<long long,int>>, greater<pair<long long,int>> > pq;
        pq.push({0,0});
        dis[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();


            if(dis[node] < wt) continue;

            for(int i = 0; i < adj[node].size(); i++){
                int neiWt = adj[node][i].first;
                int nei = adj[node][i].second;

                if(dis[nei] > wt + neiWt){
                    dis[nei] = wt + neiWt;
                    ways[nei] = ways[node];
                    pq.push({dis[nei],nei});
                }else if(dis[nei] == wt + neiWt){
                    ways[nei] = (ways[nei] + ways[node])%MOD;
                }
            }
        }

        return ways[n-1];
    }
};