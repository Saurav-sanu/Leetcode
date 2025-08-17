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
int solve(TreeNode* root,int &maxSum){
    //base case i
    if(root==NULL){
        return 0;
    }

    int l =  solve(root->left, maxSum);
    int r= solve(root->right, maxSum);

    int root_ka_ans=root->val;
    int left_yah_right=max(l,r)+root->val;
    int left_root_right=l+r+root->val;

    maxSum=max({maxSum,root_ka_ans,left_yah_right,left_root_right});

    return max(root_ka_ans,left_yah_right);
}
    int maxPathSum(TreeNode* root) {
        
        int maxSum=INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};