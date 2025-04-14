class Solution {
public:
    int minInsertions(string s) {
        //using blueprrint or kind of bottom up 
        int n=s.length();
        vector<vector<int>>t(n,vector<int>(n));

        for(int i=0;i<n;i++){
            t[i][i]=0;
        }

        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;

                if(s[i]==s[j]){
                    t[i][j]=t[i+1][j-1];
                }
                else{
                    t[i][j]=1+min(t[i+1][j],t[i][j-1]);
                }
            }
        }

        return t[0][n-1];

    }
};