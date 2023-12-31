class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        map<char,int> mp;
        int ans = 0;
        int f = 1;
        for(int i = 0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = i;
          
            }
            else{
                f=0;
                ans = max(ans,i-mp[s[i]]-1);
                // mp[s[i]] = i;
            }
        }
        if (f) return -1;
        return ans;
        
    }
};