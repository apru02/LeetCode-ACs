class Solution {
public:

    int f(int ind,string s,vector<int> &dp){
        int n = s.size();
        if(dp[ind] != -1) return dp[ind];
        if(ind < n && s[ind] == '0') return 0;
        if(ind >=n-1) return 1;
        int take_one = f(ind+1,s,dp);
        int take_two = 0;
        int number = (s[ind] - '0')*10 + (s[ind+1] - '0');
        if(number <=26) take_two = f(ind+2,s,dp);
        return dp[ind] = take_one + take_two;

    }
    int numDecodings(string s) {
        int n =  s.size();
        vector<int> dp(n+1,-1);
        return f(0,s,dp);
    }
};