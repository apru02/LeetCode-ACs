class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map <int,int> mp1;
        map <int,int> mp2;
        int n = matches.size();
        for(int i = 0;i<n;i++){
            int winner = matches[i][0];
            int loser = matches[i][1];
            mp2[loser]++;
            if (mp1.find(loser) != mp1.end()) mp1[loser] = 0;
            if(mp2.find(winner) == mp2.end()) mp1[winner] = 1;
            else mp1[winner] = 0;
        }
        vector<vector<int>> ans(2,vector<int>());
        for(auto it:mp2){
            if (it.second == 1) ans[1].push_back(it.first);
        }
        for(auto it:mp1){
            if (it.second == 1) ans[0].push_back(it.first);
        }
        return ans;
    }
};