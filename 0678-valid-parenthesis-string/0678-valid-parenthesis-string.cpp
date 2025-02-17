class Solution {
public:
int t[101][101];
bool solve(int i,int open,string &s,int n){
    //base case
    bool is_valid=false;
    if(i==n){
        return open==0;
    }
    if(t[i][open]!=-1){
        return t[i][open];
    }


    if(s[i]=='('){
        is_valid|=solve(i+1,open+1,s,n);
    }
    else if(s[i]=='*'){
        is_valid|=solve(i+1,open+1,s,n);
        is_valid|=solve(i+1,open,s,n);
        if(open>0){
            is_valid|=solve(i+1,open-1,s,n);
        }
    }
    else if(open>0){
        is_valid|=solve(i+1,open-1,s,n);
    }
    return  t[i][open]=is_valid;

}
    bool checkValidString(string s) {
        //option 1
        // recursion se
        memset(t,-1,sizeof(t));
        int n=s.length();
        return solve(0,0,s,n);
    }
};