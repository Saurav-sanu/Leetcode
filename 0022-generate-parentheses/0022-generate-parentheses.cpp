class Solution {
public:

void generate(int n,string output,vector<string>&ans,int open,int close){
    //base case
    if(output.size()==2*n){
        ans.push_back(output);
        return;
    }

    if(open<n){
        generate(n,output+'(',ans,open+1,close);
    }
    if(close<open){
        generate(n,output+')',ans,open,close+1);
    }

    
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(n,"",ans,0,0);
        return ans;
    }
};