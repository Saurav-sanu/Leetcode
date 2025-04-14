class Solution {
public:
int t[501][501];
int solve(int m,int n,string a, string b){
    //base case
    if(m==0 || n==0){
        return m+n;
    }

    if(t[m][n]!=-1){
        return t[m][n];
    }


    int result=0;

    if(a[m-1]!=b[n-1]){
        int update=1+solve(m-1,n-1,a,b);
        int delet=1+solve(m-1,n,a,b);
        int insert=1+solve(m,n-1,a,b);
        result=min({update,delet,insert});
    }
    else{
        result=solve(m-1,n-1,a,b);
        
    }
    return t[m][n]=result;

}
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        int m=word1.size();
        int n=word2.size();
        return solve(m,n,word1,word2);
    }
};