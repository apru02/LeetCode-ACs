class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        set<int> st;
        int r1=0,r2=0,r3=0,c1=0,c2=0,c3=0,d1=0,d2=0;
        for(int i = 0;i<=n-3;i++){
            for(int j = 0;j<=m-3;j++){
                int flag = 0;
                for(int r=i;r<i+3;r++){
                    for(int c=j;c<j+3;c++){
                        if(grid[r][c] > 9 || grid[r][c] < 1){
                            flag = 1;
                            break;
                        }
                        st.insert(grid[r][c]);
                    }
                    if(flag) break;
                }
                if(st.size() != 9) flag = 1;
                r1 = grid[i][j]+grid[i][j+1]+grid[i][j+2];
                r2 = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                r3 = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                c1 = grid[i][j]+grid[i+1][j]+grid[i+2][j];
                c2 = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                c3 = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
                d1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                d2 = grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                if(!flag && r1==r2 && r1==r3 && r1==c1 && r1==c2 && r1 == c3 && r1==d1 && r1==d2) ans++;
            }
        }
        return ans;
    }
};