class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //blueprint 
        int n=s.length();

        vector<vector<int>>t(n,vector<int>(n));

        for(int i=0;i<n;i++){
            t[i][i]=1;
        }

        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=l+i-1;
                if(s[i]==s[j]){
                    t[i][j]=2+t[i+1][j-1];
                }
                else{
                    t[i][j]=max(t[i+1][j],t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
};