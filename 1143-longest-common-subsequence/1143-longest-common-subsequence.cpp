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