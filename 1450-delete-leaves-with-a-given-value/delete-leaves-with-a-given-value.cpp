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

    void solve(TreeNode* parent,int direction,TreeNode* node,int target){
        if(node == nullptr) return;
        solve(node,1,node->left,target);
        solve(node,2,node->right,target);
        if(node->left == nullptr && node->right == nullptr){
            if(node-> val == target){
                if(direction == 1) parent->left = nullptr;
                else parent->right = nullptr;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* head = new TreeNode(0);
        head->left = root;
        solve(head,1,root,target);
        return head->left;

    }
};