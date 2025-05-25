class Solution {
public:
bool isvalid(string t){
    //
    int count=0;
    for(char &ch:t){
        if(ch=='('){
            count++;
        }
        else{
            count--;
            if(count<0){
                return false;
            }
        }
    }
    return count==0;
}
void solve(int n,vector<string>&ans,string result){
    //baes case
    if(result.size()==2*n){
        if(isvalid(result)){
            ans.push_back(result);

        }
        return;
    }

    result.push_back('(');
    solve(n,ans,result);
    result.pop_back();


    result.push_back(')');
    solve(n,ans,result);
    result.pop_back();


}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string result="";
        solve(n,ans,result);
        return ans;

    }
};



//appraoch 2 withour valid function use 
class Solution {
public:
//approach 2
void solve(int n,vector<string>&ans,string result,int open,int close){
    //baes case
    if(result.size()==2*n){
       
            ans.push_back(result);

        return;
    }

    if(open<n){

        result.push_back('(');
        solve(n,ans,result,open+1,close);
        result.pop_back();
    }


    if(close<open){

        result.push_back(')');
        solve(n,ans,result,open,close+1);
        result.pop_back();
    }


}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string result="";
        int open,close=0;
        solve(n,ans,result,0,0);
        return ans;

    }
};
