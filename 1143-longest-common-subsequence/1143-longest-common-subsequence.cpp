class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        //using bottom up
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1));
        for(int row=0;row<m;row++){
            t[row][0]=0;
        }
        for(int col=0;col<n;col++){
            t[0][col]=0;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];

    }
};