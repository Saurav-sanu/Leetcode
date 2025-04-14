class Solution {
public:
int t[1001][1001];
bool solve(string &s,int i,int j){
    if(i>=j){
        return 1;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }

    if(s[i]==s[j]){
        return t[i][j]=solve(s,i+1,j-1);
    }

    return t[i][j]=0;
}
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLen=0;
        int sp=0;
        memset(t,-1,sizeof(t));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }

                }
            }
        }

        return s.substr(sp,maxLen);
        // vector<vector<bool>>t(n,vector<bool>(n,false));
        // string ans="";

        // for(int l=1;l<=n;l++){
        //     for(int i=0;i+l-1<n;i++){
        //         int j=i+l-1;
        //         if(i==j){
        //             t[i][j]=true;
        //         }
        //         else if(i+1==j){
        //              t[i][j]=(s[i]==s[j]);
        //         }
        //         else{
        //             t[i][j]=(s[i]==s[j] && t[i-1][j+1]);
        //         }

        //          if(t[i][j]==true){
        //             count++;
        //         }

        //     }
        // }
        
    }
};