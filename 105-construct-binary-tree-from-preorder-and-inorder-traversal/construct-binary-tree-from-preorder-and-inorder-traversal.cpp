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
    // TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int ind,int inorderStart,
    //  int inorderEnd,map<int,int> &mp){
    //      int n = inorder.size();
    //      if(ind >= n || inorderStart > inorderEnd){
    //          return nullptr;
    //      }
    //      int element = preorder[ind];
    //      int position = mp[element];
    //      TreeNode* node = new TreeNode(element);
    //      ind++;
    //      node->left = solve(preorder,inorder,ind,inorderStart,position - 1,mp);
    //      node->right = solve(preorder,inorder,ind,position+1,inorderEnd,mp);
    //      return node;
    // }
      int Findposition(vector<int>& in,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }
    TreeNode* solve(vector<int>& in, vector<int>& pre, int &index ,int inorderStart , int inorderEnd , int n){
        if(index>=n || inorderStart>inorderEnd){
            return NULL ;
        }

        int element = pre[index++]; 
        TreeNode* root  = new TreeNode(element); 
        int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
        root->left = solve(in , pre , index  , inorderStart , position-1 ,n);
        root->right = solve(in , pre , index , position+1 , inorderEnd ,n);
        
        return root ;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
       
         int preorderindex  = 0 ;  
         int n = pre.size();
         TreeNode* ans = solve(in , pre , preorderindex , 0  , n-1 , n );
         return ans ;
    }
};