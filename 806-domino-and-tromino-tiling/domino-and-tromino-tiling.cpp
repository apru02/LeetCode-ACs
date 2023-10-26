class Solution {
public:
    int mod=1e9+7;
    long f(int n, vector<long>& dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;

        if(dp[n]!=-1) return dp[n]%mod;

        long Ans1=0, Ans2=0;
        Ans1=f(n-1,dp)%mod;
        Ans2=f(n-3,dp)%mod;

        dp[n]=(Ans1*2+Ans2)%mod;
        return dp[n]%mod;
    }
    
    int numTilings(int n) {
        vector<long> dp(n+1,-1);
        long ans=f(n,dp)%mod;
        return (int)ans;        
    }
};