class Solution {
public:
bool isValid(string s){
    int n=s.length();
    int count=0;
    for(char ch:s){
      
        if(ch=='('){
            count++;
        }
        else{
            if(count==0){
                return false;
            }
            count--;
        }
    }
    return count==0;
}
void generate(int n,string output,vector<string>&ans){
    //base case
    if(output.size()==2*n){
        if(isValid(output)){
            ans.push_back(output);
        }
        return;
    }

    generate(n,output+'(',ans);
    generate(n,output+')',ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(n,"",ans);
        return ans;
    }
};