class Solution {
public:
    string smallestNumber(string pattern) {
        int counter=1;

        stack<char>st;
        int n=pattern.length();
        string num="";

        for(int i=0;i<n+1;i++){
            st.push(counter+'0');
            counter ++;

            if(i==n || pattern[i]=='I'){
                while(!st.empty()){
                    auto element=st.top();
                    st.pop();

                    num.push_back(element);

                }

            }
        }
        return num;
    }
};