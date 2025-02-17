class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st;
        stack<int>starst;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else if(!starst.empty()){
                    starst.pop();
                }
                else{
                    return false;
                }
            }
            else{
                starst.push(i);
            }
        }

        //post prosssesing
        while(!st.empty() && !starst.empty()){
            if(st.top()>starst.top()){
                return false;
            }
            st.pop();
            starst.pop();
        }
        return st.empty();
    }
};