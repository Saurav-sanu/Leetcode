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
TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &idx,int start,int end){
    //base cs
    if(start>end){
        return NULL;
    }
    int rootVal=preorder[idx];
    int i=start;

    for(;i<=end;i++){
        if(inorder[i]==rootVal){
            break;
        }
    }
    idx++;
    TreeNode* root=new TreeNode(rootVal);

    root->left=solve(preorder,inorder,idx,start,i-1);
    root->right=solve(preorder,inorder,idx,i+1,end);

    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        int n=preorder.size();
        return solve(preorder,inorder,idx,0,n-1);
    }
};