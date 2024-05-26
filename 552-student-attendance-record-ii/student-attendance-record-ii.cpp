class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int ind,int n,int a,int l,vector<vector<vector<int>>>& dp){
        if(ind>=n) return 1;
        if(dp[ind][a][l] != -1) return dp[ind][a][l];
        int ans = 0;
        if(a == 0) ans = (ans + solve(ind+1,n,a+1,0,dp))%mod;
        if (l < 2) ans = (ans + solve(ind+1,n,a,l+1,dp))%mod;
        ans = (ans + solve(ind+1,n,a,0,dp))%mod;
        return dp[ind][a][l] = ans%mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(3,vector<int>(4,-1)));
        return solve(0,n,0,0,dp);
    }
};