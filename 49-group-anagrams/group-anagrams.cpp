class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,int> mp;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            string u = strs[i];
            sort(u.begin(),u.end());
            if(mp.find(u) == mp.end()){
                mp[u]= cnt;
                cnt++;
            }
        }
        vector<string> adj[cnt];
        for(int i = 0;i<n;i++){
            string u = strs[i];
            sort(u.begin(),u.end());
            adj[mp[u]].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(int i = 0;i<cnt;i++){
            vector<string> temp = adj[i];
            ans.push_back(temp);
        }
        return ans;
    }
};