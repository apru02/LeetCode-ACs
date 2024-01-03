class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int ans = 0;
        int prev = 0;
        for(int i = 0;i<n;i++){
            int curr= 0;
            for(int j = 0;j<m;j++){
                if(bank[i][j] == '1'){
                    curr++;
                    ans+=prev;
                }
            }
            if(curr) prev = curr;
        }
        return ans;
    }
};