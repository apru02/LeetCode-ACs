class Solution {
public:
    static string replaceWords(vector<string>& dictionary, string& sentence) {
        // Put words in dictionary to hash table
        unordered_set<string> S(dictionary.begin(), dictionary.end());
        
        // split the sentence & find ans
        string ans, word;
        bool isFound=0;

        for (char c: sentence) {
            if (c!= ' ') {
                word+=c;
                if (!isFound && S.count(word)) {
                    ans+=word;
                    isFound=1;
                }
            } 
            else {
                if (!isFound) ans+=word;
                ans+=' ';
                word="";
                isFound=0;
            }
        }
        if (!isFound)
            ans+=word;

        return ans;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();