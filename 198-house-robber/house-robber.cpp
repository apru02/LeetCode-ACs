class Solution {
public:
    int f(int ind,vector<int> &nums,int n){
        if (ind >=n ) return 0;
         int notRob = f(ind+1,nums,n);
         int rob = nums[ind] + f(ind+2,nums,n);
         return max(notRob,rob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2,0);
        for (int ind=n-1;ind>=0;ind--){
                int notRob = dp[ind + 1];
                int rob = nums[ind] + dp[ind + 2];
                dp[ind] = max(notRob,rob);
        }
        return dp[0];
    }
};