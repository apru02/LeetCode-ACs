#define ll long long
class Solution {
public:
    int mod = 1000000007;
    ll f(int stations,vector<ll> &dp){
        if(stations == 0) return 1;
        if(dp[stations] != -1) return dp[stations];
        ll temp= f(stations-1,dp)*(2*stations-1)*stations%mod;
        
        return dp[stations] = temp;
    }
    int countOrders(int n) {
        vector<ll> dp(n+1,-1);
        return (int)f(n,dp);

    }
};