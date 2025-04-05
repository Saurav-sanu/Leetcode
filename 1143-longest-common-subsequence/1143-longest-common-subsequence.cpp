class Solution {
public:
    int solveUsingRecursion(string a,string b,int i,int j){
        //base case
        if(i>=a.length()){
            return 0;
        }
        if(j>=b.length()){
            return 0;
        }

        //recusion
        //match
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solveUsingRecursion(a,b,i+1,j+1);
        }
        else{
            ans=0+max(solveUsingRecursion(a,b,i+1,j),solveUsingRecursion(a,b,i,j+1));
        }
        return ans;
    }
    int solveUsingMemo(string &a,string &b,int i,int j,vector<vector<int> > &dp){
        //base case
        if(i>=a.length()){
            return 0;
        }
        if(j>=b.length()){
            return 0;
        }
        //chcek if ans already exist
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //recusion
        //match
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solveUsingMemo(a,b,i+1,j+1,dp);
        }
        else{
            ans=0+max(solveUsingMemo(a,b,i+1,j,dp),solveUsingMemo(a,b,i,j+1,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int solveUsingTabulation(string a,string b){
        //base case bhi cover ho gya as 0 se initialise kar diya hmne vector dp ko
        vector<vector<int> >dp(a.length()+1,vector<int>(b.length()+1,0));
        //ith index a.lenght -1 se shuru hoga a.legnth ki jagah kyuki base case sambahl kiya hai hmne phle hi
        for(int i_index=a.length()-1;i_index>=0;i_index--){
            for(int j_index=b.length()-1;j_index>=0;j_index--){
                int ans=0;
                if(a[i_index]==b[j_index]){
                    ans=1+dp[i_index+1][j_index+1];
                }
                else{ 
                    ans=0+max(dp[i_index+1][j_index],dp[i_index][j_index+1]);
                }
                dp[i_index][j_index]=ans;
            }
        }
        return dp[0][0];
    }
    //with loop change
    int solveUsingTabulationOP(string a,string b){
        //base case bhi cover ho gya as 0 se initialise kar diya hmne vector dp ko
        //vector<vector<int> >dp(a.length()+1,vector<int>(b.length()+1,0));
        //ith index a.lenght -1 se shuru hoga a.legnth ki jagah kyuki base case sambahl kiya hai hmne phle hi
        vector<int>curr(a.length()+1,0);
        vector<int>next(a.length()+1,0);

        for(int j_index=b.length()-1;j_index>=0;j_index--){
            for(int i_index=a.length()-1;i_index>=0;i_index--){
                int ans=0;
                if(a[i_index]==b[j_index]){
                    ans=1+next[i_index+1];
                }
                else{ 
                    ans=0+max(curr[i_index+1],next[i_index]);
                }
                curr[i_index]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    //without loop change
    int solveUsingTabulationOP2(string a,string b){
        //base case bhi cover ho gya as 0 se initialise kar diya hmne vector dp ko
        //vector<vector<int> >dp(a.length()+1,vector<int>(b.length()+1,0));
        //ith index a.lenght -1 se shuru hoga a.legnth ki jagah kyuki base case sambahl kiya hai hmne phle hi
        vector<int>curr(b.length()+1,0);
        vector<int>next(b.length()+1,0);

        for(int i_index=a.length()-1;i_index>=0;i_index--){
            for(int j_index=b.length()-1;j_index>=0;j_index--){
                int ans=0;
                if(a[i_index]==b[j_index]){
                    ans=1+next[j_index+1];
                }
                else{ 
                    ans=0+max(curr[j_index+1],next[j_index]);
                }
                curr[j_index]=ans;
            }
            next=curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        vector<vector<int> >dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        // int ans=solveUsingMemo(text1,text2,i,j,dp);
        // return ans;

        // int ans=solveUsingRecursion(text1,text2,i,j);
        // return ans;

        int ans=solveUsingTabulationOP2(text1,text2);
        return ans;
    }
};