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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL){
            return NULL;
        }
        //CASE 1: p and q both are on left node
        if(p->val<root->val && q->val<root->val){
            TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
            return leftAns;
        }
        //CASE 2: p and q both are on right node
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }
        //case 3:p is in left subtree and q is on right subtree
        //so q is small'
        // if(p->val < root->val && q->val > root->val){
        //     return root;
        // }
        // //case 4:q is in left subtree and p is on right subtree
        // //so p is small'
        // if(p->val > root->val && q->val < root->val){
        //     return root;
        // }
        return root;
    }
};