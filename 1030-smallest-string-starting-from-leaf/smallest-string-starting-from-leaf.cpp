#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    void dfs(TreeNode* root,vector<string> & words, string s){
        if(root == nullptr)
            return;
        
        s = char('a' + root->val) + s;
        
        if(root->left == nullptr && root->right == nullptr){
            words.push_back(s);
            return;
        }
        
        dfs(root->left, words, s);
        dfs(root->right, words, s);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        vector<string> words;
        dfs(root,words,"");
        sort(words.begin(), words.end());
        return words[0];
    }
};
