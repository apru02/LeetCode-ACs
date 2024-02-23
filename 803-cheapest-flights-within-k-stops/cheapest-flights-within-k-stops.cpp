class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>> adj[n];
        for (auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});
        vector<int> prices(n,1e9);
        prices[src] = 0;
        while(!pq.empty()){
            int city = pq.front().second.first;
            int price = pq.front().second.second;
            int stops = pq.front().first;
            pq.pop();
            if (stops > K) continue;
            for (auto it: adj[city]){
                if (price + it.second < prices[it.first] && stops <= K){
                    prices[it.first] = price + it.second;
                    pq.push({stops + 1,{it.first,prices[it.first]}});
                }
            }
        }
        if (prices[dst] == 1e9) return -1;
        return prices[dst];
    }
};