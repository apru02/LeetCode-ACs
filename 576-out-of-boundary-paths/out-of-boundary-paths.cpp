class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,int m,int n,int maxMove){
        if(i<0 || i>=m || j<0 || j>=n) return 1;
        if(maxMove == 0) return 0;
        if(dp[i][j][maxMove] !=-1) return dp[i][j][maxMove];
            int up = solve(i+1,j,m,n,maxMove-1); 
            int left = solve(i,j-1,m,n,maxMove-1); 
            int down = solve(i-1,j,m,n,maxMove-1); 
            int right = solve(i,j+1,m,n,maxMove-1);
            return dp[i][j][maxMove] = ((up+down)%mod +(left+right)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(m,vector<vector<int>>(n , vector<int>(maxMove + 1,-1)));

        return solve(startRow,startColumn,m,n,maxMove);
    }
};