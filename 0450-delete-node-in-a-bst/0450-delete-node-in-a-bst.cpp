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
TreeNode* rightMin(TreeNode* root){
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

        if(root->val==key){
            //case 1 nothing is present
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            // case 2 left present only
            if(root->left!=NULL && root->right==NULL){
                TreeNode* dummy=root;
                root=root->left;
                delete dummy;
                return root;
            }
            // case 3 right present only
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* dummy=root;
                root=root->right;
                delete dummy;
                return root;
            }
            //case 4 both right and left present
            else{
                TreeNode* mini=rightMin(root->right);
                root->val=mini->val;
                root->right=deleteNode(root->right,mini->val);

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