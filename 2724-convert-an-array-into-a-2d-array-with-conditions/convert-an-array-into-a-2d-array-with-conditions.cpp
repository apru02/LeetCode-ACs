class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        int max_n = 0;
        for(auto it:nums){
            mp[it]++;
            max_n=max(max_n,mp[it]);
        }
        vector<vector<int>> adj(max_n);
        for(auto it:mp){
            for(int i =0;i<it.second;i++) adj[i].push_back(it.first);
        }
        return adj;

    }
};