class Solution {
public:
int solve(int i,int j,int m ,int n,vector<vector<int>>&dp){
    //base case
    if(i<0 ||i>=m || j<0 ||j>=n){
        return 0;
    }
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
   
    int right =solve(i+1,j,m,n,dp);
    int down=solve(i,j+1,m,n,dp);
    return dp[i][j]=right+down;
}
    int uniquePaths(int m, int n) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(i,j,m,n,dp);
    }
};