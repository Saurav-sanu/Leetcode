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
int solve(TreeNode* root,int &result){
    //base case
    int sum=0;
    if(root==NULL){
        return 0;
    }

    int left=root->left==NULL?0:solve(root->left,result);
    int right=root->right==NULL?0:solve(root->right,result);
    result=max(result,root->val+left+right);
    return root->val+max(left,right);
}
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        solve(root,result);
        return result;
    }
};