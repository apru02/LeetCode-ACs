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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &ind,int inorderStart,int inorderEnd,map<int,int> &mp){
         int n = inorder.size();
         if(ind >= n || inorderStart > inorderEnd){
             return NULL;
         }
         int element = preorder[ind];
         int position = mp[element];
         TreeNode* node = new TreeNode(element);
         ind++;
         node->left = solve(preorder,inorder,ind,inorderStart,position - 1,mp);
         node->right = solve(preorder,inorder,ind,position+1,inorderEnd,mp);
         return node;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
       
         int preorderindex  = 0 ;  
         int n = in.size();
         map<int,int> mp;
         for(int i =0;i<n;i++) mp[in[i]] = i;
         TreeNode* ans = solve(pre , in , preorderindex , 0  , n-1 , mp );
         return ans ;
    }
};