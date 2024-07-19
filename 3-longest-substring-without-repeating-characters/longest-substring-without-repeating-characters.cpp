class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans = 0;
        int n = s.size();
        map<char,int> mp;
        for(int i = 0;i<n;i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= l){
                l = mp[s[i]] + 1;
            
            }
            ans = max(ans,i-l+1);
            mp[s[i]] = i;
        }
        return ans;
    }
};