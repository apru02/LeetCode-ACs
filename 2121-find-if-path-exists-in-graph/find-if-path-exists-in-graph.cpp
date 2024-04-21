class Solution {
public:
    bool bfs(int node,vector<int> adj[],vector<int> &vis,int destination){
        if (node == destination) return true;
        vis[node] = 1;
        bool f = false;
        for(auto it:adj[node]){
            
            if(!vis[it]){
                cout << it <<endl;
                f =  bfs(it,adj,vis,destination);
                if (f) return true;
            }
        }
        return f;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        for (auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return bfs(source,adj,vis,destination);
    }
};