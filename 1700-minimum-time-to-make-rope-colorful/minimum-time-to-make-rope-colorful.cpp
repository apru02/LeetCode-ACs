class Solution {
public:
    int solve(int ind,int prev,string colors,vector<int>& neededTime,vector<vector<int>>& dp){
        int n = colors.size();
        if(ind >= n) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int ans = 0;
        if(colors[ind] == colors[prev]){
            ans = min(neededTime[ind] + solve(ind+1,prev,colors,neededTime,dp),
            neededTime[prev] + solve(ind+1,ind,colors,neededTime,dp));
        }
        else ans = solve(ind+1,ind,colors,neededTime,dp);
        return dp[ind][prev] = ans;
    }
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int total = 0;
        int i = 0;
        int j = 0;
        while(i<n && j<n){
            int curr = 0,currMax = 0;
            while(j<n && colors[i]==colors[j]){
                curr+=neededTime[j];
                currMax = max(currMax,neededTime[j]);
                j++;
            }
            total+= curr - currMax;
            i=j;
        }
        return total;
        // return solve(1,0,colors,neededTime,dp);
    }
};