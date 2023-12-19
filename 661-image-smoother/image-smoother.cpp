class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int sum = 0;
                int cnt = 0;
                for(int r = -1;r<=1;r++){
                    for(int c = -1;c<=1;c++){
                        int new_r = i+r;
                        int new_c = j+c;
                        if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m){
                            sum+=img[new_r][new_c];
                            cnt++;
                        } 
                    }
                }
                ans[i][j] = sum/cnt;
            }
        }
        return ans;
    }
};