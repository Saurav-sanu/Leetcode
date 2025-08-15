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
void solve(TreeNode* root,vector<int>&ans){
    //base case
    if(!root){
        return;
    }
  
    if(root){

        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }


}
    vector<int> preorderTraversal(TreeNode* root) {

        //dfs preordrer traversal
       vector<int>ans;
       solve(root,ans);
       return ans;
        
    }
};