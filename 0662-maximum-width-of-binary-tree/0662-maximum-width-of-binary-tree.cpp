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
typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        ll maxi=0;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            ll L=q.front().second;
            ll R=q.back().second;

            maxi=max(maxi,R-L+1);

            while(size--){
                auto front=q.front();
                ll ind=q.front().second;
                q.pop();

                if(front.first->left!=NULL){
                    q.push({front.first->left,2*ind+1});
                }
                if(front.first->right!=NULL){
                    q.push({front.first->right,2*ind+2});
                }
            }
        }
        return maxi;
    }
};