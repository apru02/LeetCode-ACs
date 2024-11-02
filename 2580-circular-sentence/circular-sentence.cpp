class Solution {
public:
    bool isCircularSentence(string sentence) {
        sentence += " ";
        
        string s;
        vector<string> v;
        for (int i = 0; i < sentence.size(); i++) {
            if (!isalpha(sentence[i])) {
                if (!v.empty()) {
                    string prev = v.back();
                    if (s[0] != prev[prev.size() - 1]) { 
                        return false;
                    }
                }
                v.push_back(s); 
                s = ""; 
            } else {
                s.push_back(sentence[i]); 
            }
        }
        string last = v[v.size() - 1];
        if (v[0][0] != last[last.size() - 1]) return false;
        
        return true;
    }
};