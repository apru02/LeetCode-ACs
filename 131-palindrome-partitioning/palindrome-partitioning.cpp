class Solution {
public:
bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++) {

        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return false;
        }
    }
    // Return "Yes"
    return true;
}
 
    void solve(string s,int l,int r,vector<string>& temp,vector<vector<string>>& ans){
        int n = s.size();
        string t = s.substr(l,r-l+1);
        if(r == n-1){
            if(isPalindrome(t)){
                temp.push_back(t);
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        if(isPalindrome(t)){
            temp.push_back(t);
            solve(s,r+1,r+1,temp,ans);
            temp.pop_back();
        }
        solve(s,l,r+1,temp,ans);
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp = {};
        vector<vector<string>> ans;
        solve(s,0,0,temp,ans);
        return ans;
    }
};