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
TreeNode* solve(vector<int>&preorder,int &index,int bound){
    //base case
    if(index>=preorder.size() || preorder[index]>bound){
        return NULL;
    }
    int val=preorder[index++];
    TreeNode* root=new TreeNode(val);
    root->left=solve(preorder,index,val);
    root->right=solve(preorder,index,bound);

    return root;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return solve(preorder,index,INT_MAX);
    }
};