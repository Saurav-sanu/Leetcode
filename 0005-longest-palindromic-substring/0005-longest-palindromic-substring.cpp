class Solution {
public:
bool ispalindrome(string &str,int i,int j){
    while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(ispalindrome(s,i,j)){
                    string t=s.substr(i,j-i+1);
                    ans=t.size()>ans.size()?t:ans;
                }
            }
        }
        return ans;
    }
};