class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> mp;
        for(auto it:chars) mp[it]+=1;
        int ans = 0;
        for(auto it:words){
            int f = 1;
            int n = it.size();
            map<char,int> mp1;
            for(int i = 0;i<n;i++){
                mp1[it[i]]++;
            }
            for(auto jt:mp1){
                if(mp[jt.first]<jt.second){
                    f = 0;
                    break;
                }
            }
            if (f) ans+=n;
        }
        return ans;
    }
};