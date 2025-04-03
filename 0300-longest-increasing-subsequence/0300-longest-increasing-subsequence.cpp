using recuriosn and memoisation

int solveLIS(int prevIndex,int index,vector<int>&nums,vector<vector<int>>&t){
    //base case
    if(index>=nums.size()){
        return 0;
    }

    if(t[prevIndex+1][index]!=-1){
        return t[prevIndex+1][index];
    }
    int take=0;
    if(prevIndex==-1 || nums[prevIndex]<nums[index]){
        take=1+solveLIS(index,index+1,nums,t);
    }
    int skip=solveLIS(prevIndex,index+1,nums,t);

    if(prevIndex!=-1){

        t[prevIndex+1][index]=max(skip,take);
    }

    return max(skip,take);

}



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //using bootom up appracoh
        int n=nums.size();
        vector<int>t(n,1);

        int maxLis=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    t[i]=max(t[i],t[j]+1);
                    maxLis=max(maxLis,t[i]);

                }
            }
        }
        return maxLis;

    }
};
