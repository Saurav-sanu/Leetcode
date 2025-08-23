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
TreeNode* rightmin(TreeNode* root){
    //
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp=root;
        if(root==NULL){
            return NULL;
        }
        //base case
       if(root->val==key){
        //case i1
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL && root->right==NULL){
                TreeNode* dummy=root;
                root=root->left;
                delete dummy;
                return root;

            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* dummy=root;
                root=root->right;
                delete dummy;
                return root;
            }
            else{
            
                TreeNode* minright=rightmin(root->right);
                root->val=minright->val;
                root->right=deleteNode(root->right,minright->val);
            }
       }
        else if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
    
    return temp;
    }
};