class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dis(n+1,INT_MAX);

        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        pq.push({0,k});
        dis[k] = 0;

        while(!pq.empty()){
            auto [wt,node] = pq.top(); pq.pop();

            if(wt > dis[node]) continue;
            
            for(int i = 0; i < adj[node].size(); i++){
                auto [cost,child] = adj[node][i];

                if(cost + wt < dis[child]){
                    dis[child] = cost + wt;
                    pq.push({cost+wt,child});
                }
            }
        }

        int temp = 0;
        for(int i = 1; i <= n; i++){
            temp = max(temp,dis[i]);
        }

        return (temp == INT_MAX ? -1 : temp);
    }
};