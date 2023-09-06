/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int> adj[]){
        if(root == nullptr) return;
        if(root->left != nullptr){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right != nullptr){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);   
        }
        inorder(root->left,adj);
        inorder(root->right,adj);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> adj[500];
        inorder(root,adj);
        // for(int i = 0;i<500;i++){
        //     for(auto it : adj[i]) cout << it << " ";
        //     cout<<endl;
        // }
        int targetNode = target->val;
        vector<int> distance(500,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,targetNode});
        distance[targetNode] = 0;
        vector<int> ans;
        while(!pq.empty()){
            int node = pq.top().second;
            int steps = pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                if(steps + 1 < distance[it]){
                    distance[it] = steps + 1;
                    pq.push({steps+1,it});
                }
            }
        }
        for(int i = 0;i<distance.size();i++){
            if(distance[i] == k) ans.push_back(i);
        }
        return ans;
        

    }
};