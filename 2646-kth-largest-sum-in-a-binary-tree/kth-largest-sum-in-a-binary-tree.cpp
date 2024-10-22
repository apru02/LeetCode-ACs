/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    void solve(TreeNode* root,long long level,vector<long long>& levelSum,long long& max_level){
         max_level = max(max_level,level);
         levelSum[level] += root->val;
         if(root->left!= nullptr){
            solve(root->left,level+1,levelSum,max_level);
         }
        if(root->right!= nullptr){
            solve(root->right,level+1,levelSum,max_level);
         }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSum(1e5,0);
        long long max_level = 0;
        solve(root,0,levelSum,max_level);
        if(max_level < k-1) return -1;
        sort(levelSum.begin(),levelSum.end());
        // for(long long i = 0;i<=max_level;i++) cout<<levelSum[i]<<" ";
        long long n = levelSum.size();
        return levelSum[n-k];
        

    }
};