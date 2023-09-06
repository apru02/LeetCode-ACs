class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target +1);
        dp[0] = 1;
        int n=nums.size();
        for(int tar = 1;tar<=target;tar++){
            long long int temp=0;
            for(int i=0;i<n;i++){
                if(tar>=nums[i]) temp+= dp[tar - nums[i]];
            }
            dp[tar] = temp;
        }
        return dp[target];
    }
};