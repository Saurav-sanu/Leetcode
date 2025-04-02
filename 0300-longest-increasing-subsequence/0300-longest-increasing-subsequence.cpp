class Solution {
public:
int solve(int prev,int index,vector<int>&nums,vector<vector<int>>&dp){
    //base case
    if(index>=nums.size()){
        return 0;
    }
    
    if(prev!=-1 && dp[index][prev]!=-1){
        return dp[index][prev];
    }


    int take=0;
    if(prev==-1 || nums[index]>nums[prev]){

        take=1+solve(index,index+1,nums,dp);
    }
    int skip=solve(prev,index+1,nums,dp);

    if(prev!=-1){
        dp[index][prev]=max(take,skip);
    }

    return max(take,skip);

}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(-1,0,nums,dp);
    }
};