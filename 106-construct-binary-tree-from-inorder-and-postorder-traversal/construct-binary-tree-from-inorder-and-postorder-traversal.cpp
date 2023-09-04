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
        TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int &ind,int inorderStart,int inorderEnd,map<int,int> &mp){
         int n = inorder.size();
         if(ind < 0 || inorderStart > inorderEnd){
             return NULL;
         }
         int element = postorder[ind--];
         int position = mp[element];
         TreeNode* node = new TreeNode(element);
         node->right = solve(postorder,inorder,ind,position+1,inorderEnd,mp);
         node->left = solve(postorder,inorder,ind,inorderStart,position - 1,mp);
         return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
         int n = in.size();
         int postorderindex  = n-1 ;  
         map<int,int> mp;
         for(int i =0;i<n;i++) mp[in[i]] = i;
         TreeNode* ans = solve(post , in , postorderindex , 0  , n-1 , mp );
         return ans ;
    }
};