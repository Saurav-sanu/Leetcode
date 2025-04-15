class Solution {
public:
// int t[2001][2001];
// bool isPalindrome(string &s,int i ,int j){
//     //base case
//     if(i>=j){
//         return true;
//     }

//     while(i<=j){
//         if(s[i]!=s[j]){
//             return false;
//         }
//         i++;
//         j--;
 
//     }

//     return true;
// }
// int solve(string &s,int i,int j){
//     //base case 
//     if(i>=j){
//         return 0;
//     }

//     if(isPalindrome(s,i,j)){
//         return 0;
//     }

//     if(t[i][j]!=-1){
//         return t[i][j];
//     }

//     int result=INT_MAX;
//     for(int k=i;k<=j-1;k++){
//         int temp=1+solve(s,i,k)+solve(s,k+1,j);
//         result=min(result,temp);
//     }
//     return t[i][j]=result;
// }
    int minCut(string s) {
        int n=s.length();
        // memset(t,-1.sizeof(t));
        vector<vector<bool>>t(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            t[i][i]=true;
        }

        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    if(l==2){
                        t[i][j]=true;
                    }
                    else{
                        t[i][j]=t[i+1][j-1];
                    }
                }
            }
        }


        vector<int>dp(n);
        //it is going to strore the min value to cut a string[0...i]
        
        for(int i=0;i<n;i++){
            if(t[0][i]==true){
                dp[i]=0;
            }
            else{
                dp[i]=INT_MAX;
                for(int k=0;k<i;k++){
                    if(t[k+1][i]==true && 1+dp[k]<dp[i]){
                        dp[i]=1+dp[k];
                    }
                }
            }
        }

        return dp[n-1];
        
        
        // return solve(s,0,n-1);
    }
};