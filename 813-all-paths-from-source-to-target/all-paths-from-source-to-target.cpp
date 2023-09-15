class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& temp){
        if(node == graph.size() - 1){
            temp.push_back(node);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(node);
        for(auto it:graph[node]){
            dfs(it,graph,ans,temp);
        }
        temp.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        //vector<int> vis(n,-1);
        dfs(0,graph,ans,temp);
        return ans;
    }
};