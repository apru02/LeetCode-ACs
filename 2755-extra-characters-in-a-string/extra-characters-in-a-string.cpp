#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Trie Node Definition
    struct TrieNode {
        bool isEnd;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEnd(false) {}
    };
    
    // Function to insert a word into the Trie
    void insertTrie(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for(char ch : word){
            if(!node->children.count(ch)){
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        
        // Build Trie from dictionary
        TrieNode* root = new TrieNode();
        for(auto &word : dictionary){
            insertTrie(root, word);
        }
        
        // Initialize DP array with n extra characters (worst case)
        vector<int> dp(n + 1, 0);
        dp[n] = 0; // Base case: no extra characters beyond the string
        
        // Iterate from the end to the beginning
        for(int i = n - 1; i >= 0; --i){
            // Case 1: Assume s[i] is an extra character
            dp[i] = dp[i + 1] + 1;
            
            // Case 2: Try to match dictionary words starting at i
            TrieNode* node = root;
            for(int j = i; j < n; ++j){
                char ch = s[j];
                if(!node->children.count(ch)){
                    break; // No further match possible
                }
                node = node->children[ch];
                if(node->isEnd){
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }
        
        return dp[0];
    }
};
