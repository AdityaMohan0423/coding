class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][2],flights[i][1]});
        }

        vector<int> pathPrice(n,INT_MAX);
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

        pq.push({-1,{0,src}});
        pathPrice[src] = 0;

        while(!pq.empty()){
            auto [currK,nodeAndPrice] = pq.top();
            pq.pop();
            int price = nodeAndPrice.first;
            int node = nodeAndPrice.second;

            if(currK == k) continue;

            for(int i = 0; i < adj[node].size(); i++){
                int neigFlightPrice = adj[node][i].first;
                int neig = adj[node][i].second;

                if(pathPrice[neig] > price + neigFlightPrice){
                    pathPrice[neig] = price + neigFlightPrice;
                    pq.push({currK+1,{pathPrice[neig],neig}});
                }
            }
        }
        
        return ((pathPrice[dst] == INT_MAX) ? -1 : pathPrice[dst]);
    }
};
