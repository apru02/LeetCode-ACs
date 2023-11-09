class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int ans = 0;
        int mod = 1e9+7;
        int j = 0;
        for(int i = 0;i<n;i++){
            if(s[j] == s[i]) ans = (ans + i-j+1)% mod;
            else{
                ans = (ans+1)%mod;
                j=i;
            }
        }
        return ans%mod;
    }
};