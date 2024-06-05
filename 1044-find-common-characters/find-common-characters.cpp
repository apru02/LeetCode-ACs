class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common_count(26, INT_MAX);  
        
        for (const auto& word : words) {
            vector<int> count(26, 0); 
            for (const char& c : word) {
                count[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                common_count[i] = min(common_count[i], count[i]);
            }
        }
        
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            while (common_count[i]-- > 0) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        
        return ans;
    }
};
