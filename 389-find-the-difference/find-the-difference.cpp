class Solution {
public:
    char findTheDifference(string s, string t) {
        // map<char,int> mp1,mp2;
        // int n = s.size();
        // for(int i = 0;i<n;i++){
        //     mp1[s[i]]++;
        //     mp2[t[i]]++;
        // }
        // mp2[t[n]]++;
        // for(auto it:mp2){
        //     if(mp1[it.first] != it.second) return it.first;
        // }
        // return '-1';
        // SPACE COMPLEXITY - O(N) + O(N)
        // TIME COMPLEXITY - O(N) + O(N) + MAP INSERTION
        // HENCE TU CHUTIYA
        // OPTIMIZED : O(n) + O(1)
        int asc = 0;
        for(auto ch : t) asc += ch-'a';
        for(auto ch : s) asc -= ch - 'a';
        return asc+'a';
    }
};