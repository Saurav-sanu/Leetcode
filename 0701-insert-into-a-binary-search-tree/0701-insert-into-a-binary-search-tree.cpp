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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
        root = new TreeNode(val);
        return root;
    }

    // it's not the root node
    if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    } else {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
    }


};



//iterative approach
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            root=new TreeNode(val);
            return root;
        }

        TreeNode* newNode=new TreeNode(val);
        TreeNode* curr=root;

        while(root){
            if(root->val>val){
                //left mai jao
                if(root->left==NULL){
                    root->left=newNode;
                    break;
                }
                else{

                root=root->left;
                }


            }
            else{
                if(root->right==NULL){
                    root->right=newNode;
                    break;
                }

                else{

                root=root->right;
                }
            }
        }
        return curr;
    }
};
