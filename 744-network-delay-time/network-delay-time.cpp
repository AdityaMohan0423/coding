class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({wt,v});
        }

        vector<int> dis(n+1,INT_MAX);
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;

        pq.push({0,k});
        dis[k] = 0;

        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();

            if(wt > dis[node]) continue;

            for(int i = 0; i < adj[node].size(); i++){
                int neiWt = adj[node][i].first;
                int nei = adj[node][i].second;

                if(dis[nei] > wt + neiWt){
                    dis[nei] = wt + neiWt;
                    pq.push({dis[nei],nei});
                }
            }
        }

        int maxi = 0;
        for(int i = 1; i < dis.size(); i++){
            maxi = max(maxi,dis[i]);
        }

        return ((maxi == INT_MAX) ? -1 : maxi);
    }
};