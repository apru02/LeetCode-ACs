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
    TreeNode* findLastNode(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr) return root;
        if(root->right == nullptr) return findLastNode(root->left);
        return findLastNode(root->right);
    }
    void solve(TreeNode* root){
        if(root == nullptr) return ;
        
        TreeNode* rightChild = root->right;
        if(root->left != nullptr){
            TreeNode* lastNode = findLastNode(root->left);
            solve(root->left);
            root->right = root->left;
            root->left = nullptr;
            lastNode->right = rightChild;
        }
        if(root->right !=nullptr) solve(root->right);


    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};