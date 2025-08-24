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
typedef long long ll;
bool isvalid(TreeNode* root,ll lower,ll upper){
    //base cse
    if(root==NULL){
        return true;
    }
    bool left=isvalid(root->left,lower,root->val);
    bool right=isvalid(root->right,root->val,upper);

    if(lower <root->val && root->val<upper && left && right){
        return true;
    }

    return false;
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        ll lower=-2147483649;
        ll upper=2147483648;
        return isvalid(root,lower,upper);

    }
};