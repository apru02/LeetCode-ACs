#define ll long long
class Solution {
public:
ll mod = 1000000007;
ll f(ll length,int low, int high, int zero, int one,vector<ll> &dp){
    if(length > high) return 0;
    if(dp[length] != -1) return dp[length];
    if(length >=low & length <= high){
        return dp[length] = (1 + (f(length+zero,low,high,zero,one,dp))%mod + (f(length+one,low,high,zero,one,dp))%mod)%mod;
    }
    return dp[length] = ((f(length+zero,low,high,zero,one,dp))%mod + (f(length+one,low,high,zero,one,dp))%mod)%mod;
}
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll> dp(high + 1,-1);
        return (int)(f(0,low,high,zero,one,dp))%mod;
    }
};