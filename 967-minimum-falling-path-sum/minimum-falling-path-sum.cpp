class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,0),curr(n,0);
        for(int j=0;j<n;j++){
            prev[j]=matrix[0][j];
        }
        for (int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int top = prev[j]+matrix[i][j];
                int ld = matrix[i][j];
                if(j-1 < 0) ld = INT_MAX;
                else ld+=prev[j-1];
                int rd =matrix[i][j];
                if(j+1<n) rd+=prev[j+1];
                else rd = INT_MAX;
                curr[j] = min(top,min(ld,rd));
            }
            prev=curr;
        }
        int mini=prev[0];
        for(int k=1;k<n;k++){
           mini=min(mini,prev[k]);
        }
        return mini;
    }
};