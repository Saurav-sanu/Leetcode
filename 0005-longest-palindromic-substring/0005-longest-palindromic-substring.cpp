class Solution {
public:
    bool ispalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string result="";
        int maxi=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(ispalindrome(i,j,s)){
                    string t=s.substr(i,j-i+1);
                    result=t.length()>result.length()?t:result;
                }
            }
        }
        return result;
    }
};