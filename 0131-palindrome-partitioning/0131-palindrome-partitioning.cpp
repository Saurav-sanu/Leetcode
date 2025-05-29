class Solution {
public:
vector<vector<string>>result;
vector<string>curr;
bool isPalindrome(int i,int j,string &s){
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }

    }
    return true;
}
void solve(string s,int idx){
    //base case
    if(idx==s.length()){
        result.push_back(curr);
    }

    for(int i=idx;i<s.length();i++){
        if(isPalindrome(idx,i,s)){
            curr.push_back(s.substr(idx,i-idx+1));
            solve(s,i+1);
            curr.pop_back();
        }
    }

}
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return result;
    }
};