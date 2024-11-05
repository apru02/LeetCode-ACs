class Solution {
public:
    int solve(char c, int ind, string& s, vector<vector<int>>& dp) {
        int n = s.size();
        if (ind >= n)
            return 0;
        if (dp[ind][c - '0'] != -1)
            return dp[ind][c - '0'];

        if (s[ind] == c) {
            if (ind + 1 < n && s[ind + 1] == c) {
                return dp[ind][c - '0'] = solve(c, ind + 2, s, dp);
            } else if (ind + 1 < n) {
                return dp[ind][c - '0'] =
                           min(1 + solve(c, ind + 2, s, dp),
                               1 + solve(s[ind + 1], ind + 2, s, dp));
            } else {
                return dp[ind][c - '0'] = 1;
            }
        }

        int extra = (ind + 1 < n && s[ind + 1] != c);
        if (!extra) {
            return dp[ind][c - '0'] = min(1 + solve(c, ind + 2, s, dp),
                                          1 + solve(s[ind], ind + 2, s, dp));
        }
        return dp[ind][c - '0'] = min(2 + solve(c, ind + 2, s, dp),
                                      solve(s[ind], ind + 2, s, dp));
    }

    int minChanges(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, -1));
        return min(solve('0', 0, s, dp), solve('1', 0, s, dp));
    }
};
