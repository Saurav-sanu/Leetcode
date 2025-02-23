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
TreeNode* solve(int depth,int &i,string traversal,int n){
    //basea case
    if(i>=n){
        return NULL;
    }

    int j=i;
    while(j<n && traversal[j]=='-'){
        j++;
    }

    int dash=j-i;
    if(dash!=depth){
        return NULL;
    }

    i+=dash;

    int num=0;

    while(i<n && isdigit(traversal[i])){
        num=(num*10)+(traversal[i]-'0');
        i++;
    }

    TreeNode* root=new TreeNode(num);

    root->left=solve(depth+1,i,traversal,n);
    root->right=solve(depth+1,i,traversal,n);

    return root;

}
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.length();
        int i=0;
        int depth=0;
        return solve(depth,i,traversal,n);
    }
};