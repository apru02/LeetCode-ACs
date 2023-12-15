class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = 0;
        map<string,int> mp;
        for(auto it:paths){
            if(mp.find(it[0]) == mp.end()){
                mp[it[0]] = n;
                n++;
            }
            if(mp.find(it[1]) == mp.end()){
                mp[it[1]] = n;
                n++;
            }           
        }
        vector<int> adj[n];
        for(auto it:paths){
            adj[mp[it[0]]].push_back(mp[it[1]]);
        }
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(adj[i].size()==0){
                ans = i;
                break;
            }
        }
        for(auto it:mp){
            if(it.second == ans) return it.first;
        }
        return "";
    }
};