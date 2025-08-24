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
bool isVALID(TreeNode*root,ll lower,ll upper){
    if(root==NULL){
        return true;
    }
    bool left= isVALID(root->left,lower,(ll)root->val);
    bool right= isVALID(root->right,(ll)root->val,upper);
    if(((ll)root->val>lower && (ll)root->val<upper) && left && right ){
        return true;
    }
    else{
        return false;
    }
    
    // return root->val>lower && root->val<upper;
}
    bool isValidBST(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
        ll lower=-2147483649;
        ll upper=2147483648;
        return isVALID(root,lower,upper);

        
    }
};