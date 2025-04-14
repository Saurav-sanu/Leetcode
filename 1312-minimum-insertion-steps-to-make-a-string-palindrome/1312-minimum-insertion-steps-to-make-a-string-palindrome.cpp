class Solution {
 public:
 int t[501][501];
 int solve(string &s,int i,int j){
     //base case
     if(i>=j){
         return 0;
     }
 
     if(t[i][j]!=-1){
         return t[i][j];
     }
 
     if(s[i]==s[j]){
         return t[i][j]=solve(s,i+1,j-1);
     }
     else{
         return t[i][j]=1+min(solve(s,i+1,j),solve(s,i,j-1));
     }
 }
     int minInsertions(string s) {
         memset(t,-1,sizeof(t));
         return solve(s,0,s.length()-1);
     }
 };


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
