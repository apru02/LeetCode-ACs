class Solution {
public:
    int solve(int ind,int d,vector<int> jobDifficulty){
        int n = jobDifficulty.size();
        if(d==1){
            int level = 0;
            for(int i = ind;i<n;i++) level = max(level,jobDifficulty[i]);
            return level;
        }
        if(ind >= n) return 0;

        int maxi = -1e5;
        int ans = 1e8;
        int i = ind;
        while(n-i-1>=d-1){
            maxi = max(maxi,jobDifficulty[i]);
            // cout<<"TEST "<<maxi<<endl;
            ans = min(ans,maxi + solve(i+1,d-1,jobDifficulty));
            i++;
        }
        return ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int days) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n+1,vector<int>(days+1,1e8));
        for(int i = 0;i<n;i++){
            int level = 0;
            for(int j = i;j<n;j++) level = max(level,jobDifficulty[j]);
            dp[i][1] = level;
        }
        dp[n][0] = 0;
        for(int ind = n-1;ind>=0;ind--){
            for(int d = 1;d<=days;d++){    
                int maxi = -1e5;
                int ans = 1e8;
                int i = ind;
                while(n-i-1>=d-1){
                    maxi = max(maxi,jobDifficulty[i]);
                    // cout<<"TEST "<<maxi<<endl;
                    ans = min(ans,maxi + dp[i+1][d-1]);
                    i++;
                }
                dp[ind][d] = ans;              
            }
        }
        if (dp[0][days] == 1e8) return -1;
        return dp[0][days];
    }
};