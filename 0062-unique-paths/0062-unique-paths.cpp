class Solution {
public:
int t[101][101];
int solve(int i,int j,int m,int n){
    //base case
     if(i<0 || i>=m || j<0 || j>=n){
        return 0;
     }

    if(i==m-1 && j==n-1){
        return 1;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
   int right=solve(i+1,j,m,n);
   int down=solve(i,j+1,m,n);
    return t[i][j]=right+down;
}
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));

        return solve(0,0,m,n);
    }
};