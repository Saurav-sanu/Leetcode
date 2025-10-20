class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int open=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            
            if(ch=='('){
                open++;

                if(open>1 && ch=='('){
                    ans.push_back('(');
                }

            }
            else{
                if(open>1){
                    ans.push_back(')');
                }
                open--;
            }
        }
        return ans;
    }
};