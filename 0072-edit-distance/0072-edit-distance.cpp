class Solution {
public:
    int minDistance(string a, string b) {
        int m=a.size();
        int n=b.size();
        vector<vector<int>>t(m+1,vector<int>(n+1));

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    t[i][j]= i+j;
                }
                else if(a[i-1]==b[j-1]){
                    t[i][j]=t[i-1][j-1];
                }
                else{
                    t[i][j]=1+min({t[i-1][j-1],t[i-1][j],t[i][j-1]});
                }
            }
        }
        return t[m][n];
    }
};