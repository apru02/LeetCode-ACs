class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid,int n,int m){
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        for (int i = 0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >=0 && nrow < n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
             grid[nrow][ncol] == '1'){
                 vis[nrow][ncol] = 1;
                 dfs(nrow,ncol,vis,grid,n,m);
             }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count  = 0;
        for (int i =0;i<n;i++){
            for (int j =0 ;j<m;j++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    vis[i][j] = 1;
                    dfs(i,j,vis,grid,n,m);
                    count ++;
                }
            }
        }
        return count;
    }
};