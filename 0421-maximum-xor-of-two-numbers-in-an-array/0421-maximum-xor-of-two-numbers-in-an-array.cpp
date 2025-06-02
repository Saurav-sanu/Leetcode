class Solution {
public:
struct trieNode{
    trieNode* left;
    trieNode* right;
};

trieNode* root;
void insert(trieNode* root,int num){
    trieNode* crawler=root;
    for(int i=31;i>=0;i--){
        int ithbit=(num>>i)&1;
        if(ithbit==0){
            if(crawler->left==NULL){
                crawler->left=new trieNode();
            }
            crawler=crawler->left;
        }
        else{
             if(crawler->right==NULL){
                crawler->right=new trieNode();
            }
            crawler=crawler->right;
        }
    }
}
int findmax(trieNode* root,int num){
    int maxXor=0;
    trieNode* crawler=root;
    for(int i=31;i>=0;i--){
        int ithbit=(num>>i)&1;
        if(ithbit==1){

            //zero se xor krna chahe ge

            if(crawler->left!=NULL){
                maxXor+=pow(2,i)*1;
                crawler=crawler->left;
            }
            else{
                crawler=crawler->right;
            }
        }
        else{
             if(crawler->right!=NULL){
                maxXor+=pow(2,i)*1;
                crawler=crawler->right;
            }
            else{
                crawler=crawler->left;
            }
        }
    }
    return maxXor;
}
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        trieNode* root=new trieNode();
        int maxi=0;
        for(auto &num:nums){
            insert(root,num);
        }

        for(int i=0;i<n;i++){
            maxi=max(maxi,findmax(root,nums[i]));

        }

        return maxi;
    }
};