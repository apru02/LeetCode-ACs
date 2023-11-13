class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vowels;
        vector<int> indices;
        map<char,int> mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        mp['A'] = 1;
        mp['E'] = 1;
        mp['I'] = 1;
        mp['O'] = 1;
        mp['U'] = 1;
        for(int i =0;i<n;i++){
            if(mp[s[i]] == 1){
                vowels.push_back(s[i]);
                indices.push_back(i);
            }
        }
        sort(vowels.begin(),vowels.end());
        for(int i = 0;i<indices.size();i++){
            s[indices[i]] = vowels[i];
        }
        return s;
    }
};