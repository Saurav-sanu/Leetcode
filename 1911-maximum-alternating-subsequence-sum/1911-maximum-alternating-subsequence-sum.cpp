class Solution {
 public:
 long long solve(int index,bool flag,vector<int>& nums,vector<vector<long long>>&dp){
     //base case
     if(index>=nums.size()){
         return 0;
     }
 
     if(dp[index][flag]!=-1){
         return dp[index][flag];
     }
 
     long long skip=solve(index+1,flag,nums,dp);
     long long val=nums[index];
     if(flag==false){
         val=-val;
     }
     long long take=solve(index+1,!flag,nums,dp)+val;
 
     return dp[index][flag]=max(take,skip);
 }
     long long maxAlternatingSum(vector<int>& nums) {
         int n=nums.size();
         vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
 
         return solve(0,true,nums,dp);
     }
 };
 };
 
 //using bottom up approach
 class Solution {
 public:
     long long maxAlternatingSum(vector<int>& nums) {
         //bottom up
         
         int n=nums.size();
         vector<vector<long long >>dp(n+1,vector<long long>(2,0));
 
 
         for(int i=1;i<n+1;i++){
             //even
             dp[i][0]=max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
 
             //odd
             dp[i][1]=max(dp[i-1][0]+nums[i-1],dp[i-1][1]);
 
         }
         return max(dp[n][0],dp[n][1]);
     }
 };
