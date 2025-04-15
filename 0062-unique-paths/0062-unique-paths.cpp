class Solution {
public:

    int uniquePaths(int m, int n) {
       
         //using bottom up approach
        vector<vector<int>>t(m,vector<int>(n));
        
        for(int i=0;i<m;i++){
            //row filling
            t[i][0]=1;
        }
        for(int i=0;i<n;i++){
            //column filling 
            t[0][i]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                t[i][j]=t[i-1][j]+t[i][j-1];
            }
        }

        return t[m-1][n-1];

    }
};