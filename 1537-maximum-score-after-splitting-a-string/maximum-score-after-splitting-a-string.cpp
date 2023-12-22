class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zeros(n,0);
        vector<int> ones(n,0);
        int zeros_cnt = 0;
        int ones_cnt = 0;
        int max_score = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='0') zeros_cnt++;
            else ones_cnt++;
            zeros[i] = zeros_cnt;
            ones[i] = ones_cnt;
        } 
        for(int i = 0;i<n-1;i++){
            max_score = max(max_score,zeros[i]+ones[n-1]-ones[i]);
        }
        return max_score;

    }
};