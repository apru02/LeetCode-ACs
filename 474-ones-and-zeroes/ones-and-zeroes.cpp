class Solution {
public:
    int f(int ind,int cnt_zero,int cnt_ones,vector<string>& strs, int m, int n,vector<vector<vector<int>>> &dp){
        if(ind== strs.size()) return 0;
        if(dp[ind][cnt_zero][cnt_ones] != -1) return dp[ind][cnt_zero][cnt_ones];
        int take = 0;
        int nottake = 0;
        string s = strs[ind];
        int cnt0=0,cnt1=0;
        for(auto it:s){
            if (it == '0') cnt0++;
            if(it == '1') cnt1++;
        }
        if(cnt_zero + cnt0 <= m && cnt_ones + cnt1 <=n) take = 1 + f(ind + 1,cnt_zero + cnt0,cnt_ones + cnt1,strs,m,n,dp);
        nottake = f(ind+1,cnt_zero,cnt_ones,strs,m,n,dp);
        return dp[ind][cnt_zero][cnt_ones] = max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> dp(l+1,vector<vector<int>> (m+1,vector<int> (n+1,-1)));
        return f(0,0,0,strs,m,n,dp);
    }
};