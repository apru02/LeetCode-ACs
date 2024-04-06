class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int, char>> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push({i, '('});
            } else if (s[i] == ')') {
                if (!st.empty() && st.top().second == '(') {
                    st.pop();
                } else {
                    st.push({i, ')'});
                }
            }
        }

        unordered_set<int> indicesToRemove;
        while (!st.empty()) {
            indicesToRemove.insert(st.top().first);
            st.pop();
        }

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (indicesToRemove.find(i) == indicesToRemove.end()) {
                ans += s[i];
            }
        }

        return ans;
    }
};
