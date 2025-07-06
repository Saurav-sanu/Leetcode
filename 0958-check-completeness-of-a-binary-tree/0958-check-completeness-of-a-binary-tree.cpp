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
bool level(TreeNode* root){
    //bvase case
    queue<TreeNode*>q;
    q.push(root);
    bool nullFound=false;
    while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();

        if(front==NULL){
            nullFound=true;
        }
        else{
            if(nullFound){
                return false;
            }
            q.push(front->left);
            q.push(front->right);
        }
    }
    return true;
}
    bool isCompleteTree(TreeNode* root) {
        return level(root);
    }
};



// using dfs
class Solution {
public:
int countNode(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+countNode(root->left)+countNode(root->right);
}
bool dfs(TreeNode* root,int i,int totalNode){
    //base ca
    if(root==NULL){
        return true;
    }
    if(i>totalNode){
        return false;
    }
    return dfs(root->left,2*i,totalNode)&& dfs(root->right,2*i+1,totalNode);

}
    bool isCompleteTree(TreeNode* root) {
        //using DFS
        int totalNode=countNode(root);

        int i=1;
        return dfs(root,i,totalNode);
    }
};
