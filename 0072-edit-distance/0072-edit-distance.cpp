class Solution {
public:
int t[501][501];
int solve(int i,int j,string a, string b){
    //base case
    if(i>=a.length()){
        return b.length()-j;
    }
    if(j>=b.length()){
        return a.length()-i;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }


    int result=0;

    if(a[i]!=b[j]){
        int update=1+solve(i+1,j+1,a,b);
        int delet=1+solve(i+1,j,a,b);
        int insert=1+solve(i,j+1,a,b);
        result=min({update,delet,insert});
    }
    else{
        result=solve(i+1,j+1,a,b);
        
    }
    return t[i][j]=result;

}
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,word1,word2);
    }
};

//another way of writing the same code
//from right to left only
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
