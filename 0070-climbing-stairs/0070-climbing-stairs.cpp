class Solution {
public:
int solveusingrecursion(int n,vector<int>&dp){
    //bse acase
    if(n==1)return 1;
    if(n==2)return 2;

    if(dp[n]!=-1){
        return dp[n];
    }


    int ans=solveusingrecursion(n-1,dp)+solveusingrecursion(n-2,dp);
    return dp[n]=ans;
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=solveusingrecursion(n,dp);
        return ans;
    }
};