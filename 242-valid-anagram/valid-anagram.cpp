class Solution {
public:
    bool isAnagram(string s, string t) {
        int n =s.size();
        int m = t.size();
        if (n!=m) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
       // cout<<t<<s<<endl;
        if(t==s) return true;
        return false;
    }
};