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
int ans=-1;

int count=0;
void traversal(TreeNode* root,int k){
    //base case
    if(root==NULL){
        return ;
    }
    if(ans!=-1){
        return ;
    }

    if(root->left){

        traversal(root->left,k);
    }
    count++;
        if (count == k) {
            ans = root->val;
            return;
        }
    if(root->right){

        traversal(root->right,k);
    }

}
    int kthSmallest(TreeNode* root, int k) {
        traversal(root,k);
        return ans;
       
    }
};