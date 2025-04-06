class Solution {
public:
int t[1001][1001];
int solve(int index1,int index2,string &s1,string &s2){
    //base case
    if(index2>=s2.length()){
        return 0;
    }
    if(index1>=s1.length()){
        return 0;
    }
    if(t[index1][index2]!=-1){
        return t[index1][index2];
    }
    //take
    int take=0;
    int nottake=0;
    if(s1[index1]==s2[index2]){
        take=1+solve(index1+1,index2+1,s1,s2);
    }
    else{
        nottake=max(solve(index1,index2+1,s1,s2),solve(index1+1,index2,s1,s2));
    }

    return t[index1][index2]=take+nottake;
}
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,text1,text2);
    }
};

//using bottom up approcah
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
