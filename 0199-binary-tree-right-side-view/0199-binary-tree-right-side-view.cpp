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
vector<int>ans;
void right(TreeNode* root,int level){
    //base case
    if(root==NULL){
        return;
    }

    if(level==ans.size()){
        ans.push_back(root->val);
    }

    right(root->right,level+1);
    right(root->left,level+1);


}
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        right(root,level);
        return ans;
    }
};