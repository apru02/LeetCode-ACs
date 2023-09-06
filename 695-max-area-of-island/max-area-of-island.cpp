class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int &area){
         vector<int> drow = {-1,0,1,0};
         vector<int> dcol = {0,-1,0,1};
         int n = grid.size();
         int m = grid[0].size();
         area = area + 1;
         vis[row][col] = 1;
         for(int i = 0;i<4;i++){
             int r = row + drow[i];
             int c = col + dcol[i];
             if(r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == 1 && vis[r][c] != 1){
                 dfs(r,c,grid,vis,area);
             }
         }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,-1));
        int max_area = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] != 1){
                    int area = 0;
                    dfs(i,j,grid,vis,area);
                    max_area = max(max_area,area);
                }
            }
        }
        return max_area;
    }
};