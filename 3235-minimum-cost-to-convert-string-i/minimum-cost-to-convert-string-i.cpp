#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<pair<ll, ll>> adj[26];
        for (ll i = 0; i < original.size(); i++) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        ll total_cost = 0;
        vector<vector<ll>> dist(26, vector<ll>(26,INT_MAX));
        for (ll i = 0; i < source.size(); i++) {
            if (source[i] == target[i])
                continue;
            
            dist[source[i] - 'a'][source[i] - 'a'] = 0;
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,greater<pair<ll, ll>>> pq;
            pq.push({0, source[i] - 'a'});
            while (!pq.empty()) {
                ll node = pq.top().second;
                ll distance = pq.top().first;
                pq.pop();
                for (auto it : adj[node]) {
                    if (it.second + distance < dist[source[i]-'a'][it.first]) {
                        dist[source[i]-'a'][it.first] = it.second + distance;
                        pq.push({it.second + distance, it.first});
                    }
                }
            }
            if(dist[source[i]-'a'][target[i]-'a'] == INT_MAX) return -1;
            total_cost += dist[source[i]-'a'][target[i]-'a'];
        }
        return total_cost;
    }
};