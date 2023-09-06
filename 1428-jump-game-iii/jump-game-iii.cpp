class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int>& arr){
        vis[node] = 1;
        if(arr[node] == 0) return true;
        bool ans = false;
        for(auto it: adj[node]){
            if(vis[it] != 1 ){   
                ans = ans | dfs(it,adj,vis,arr);
            }
        }
        return ans;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> adj[n];
        for(int i =0;i<n;i++){
            if(i + arr[i] < n) adj[i].push_back(i + arr[i]);
            if(i - arr[i] >=0) adj[i].push_back(i - arr[i]);
        }
        vector<int> vis(n,-1);
        return dfs(start,adj,vis,arr);
    }
};