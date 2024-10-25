class Solution {
public:
    vector<string> splitString(string& str, char delimiter) {
        vector<string> tokens;
        stringstream ss(str);
        string token;

        while (getline(ss, token, delimiter)) {
            if (!token.empty()) {  // Ensuring non-empty tokens are added
                tokens.push_back(token);
            }
        }

        return tokens;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());  // Sort to group potential subfolders together
        vector<string> ans;
        string prev = "";  // Variable to store previous valid folder

        for (const string& f : folder) {
            if (prev.empty() || f.compare(0, prev.size(), prev) != 0 || f[prev.size()] != '/') {
                // Only add if 'f' is not a subfolder of 'prev'
                ans.push_back(f);
                prev = f;  // Update 'prev' to the current valid folder
            }
        }

        return ans;
    }
};
