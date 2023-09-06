
class Solution {
public:

    // void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int &flag){
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     vector<int> drow = {-1,0,1,0};
    //     vector<int> dcol = {0,1,0,-1};
    //     if(row == 0 || row == n-1 || col == 0 || col == m-1){
    //         flag = 0;
    //     }
    //     for(int i = 0;i<4;i++){
    //         int nrow = row + drow[i];
    //         int ncol = col + dcol[i];
    //         if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[ncol][nrow] == 0 && vis[ncol][nrow] != 1){
    //             vis[nrow][ncol] = 1;
    //             dfs(nrow,ncol,grid,vis,flag);
    //         }
    //     }
    // }
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int& flag) {
        int n = grid.size();
        int m = grid[0].size();
        stack<pair<int, int>> st;
        st.push({row, col});
        vis[row][col] = 1;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while (!st.empty()) {
            pair<int, int> current = st.top();
            st.pop();
            int r = current.first;
            int c = current.second;

            if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
                flag = 0;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && vis[nrow][ncol] != 1) {
                    st.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,-1));
        int ans = 0;
        for(int i = 1;i<n-1;i++){
            for(int j = 1;j<m-1;j++){
                if(grid[i][j] == 0 && vis[i][j]!=1){
                    int flag = 1;
                    //vis[i][j] = 1;
                    dfs(i,j,grid,vis,flag);
                    if(flag == 1) ans++;
                }
            }
        }
        return ans;
    }
};

