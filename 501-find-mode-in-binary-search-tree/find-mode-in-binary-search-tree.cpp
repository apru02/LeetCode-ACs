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
    void f(TreeNode* root,map<int,int> &mp,int &maxi){
        if(root == nullptr) return;
        mp[root->val]++;
        maxi = max(maxi,mp[root->val]);
        f(root->left,mp,maxi);
        f(root->right,mp,maxi);
    }
    vector<int> findMode(TreeNode* root) {
        map <int,int> mp;
        vector<int> ans;
        int maxi = INT_MIN;
        f(root,mp,maxi);
        for(auto it:mp){
            if(it.second == maxi) ans.push_back(it.first);
        }
        return ans;

    }
};