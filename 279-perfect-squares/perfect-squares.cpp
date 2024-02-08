class Solution {
public: 
    int numSquares(int n) {
        vector <int> dp(n+1,0);
        for (int i =1;i<=n;i++){
            int ans = 1e9;
            for (int j =1;j*j <=i;j++){
              ans = min(ans,1 + dp[i - j*j]);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};