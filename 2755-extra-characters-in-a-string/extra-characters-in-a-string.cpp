class Solution {
public:
    int solve(int ind,string s,vector<string>& dictionary,vector<int>& dp){
        int n = s.size();
        if(ind >= n) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int taken = INT_MAX;
        for(auto word:dictionary){
            int l = word.size();
            string t = s.substr(ind,l);
            if(t == word) taken = min(taken,solve(ind+l,s,dictionary,dp));
        }
        return dp[ind] = min(taken,1+solve(ind+1,s,dictionary,dp));
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dictionary,dp);
    }
};