class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        map<char,int> mp;
        for(int i = 0;i<n;i++){
            for(auto it:words[i]) mp[it]++;
        }
        for(auto it:mp){
            if(it.second % n != 0) return false;
        }
        return true;
    }
};