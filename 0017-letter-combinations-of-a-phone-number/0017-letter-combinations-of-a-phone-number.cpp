class Solution {
public:
vector<string>ans;
void solve(string digits, unordered_map<char,string>&mp,string &temp,int i){
    //base case
    if(i==digits.length()){
        ans.push_back(temp);
        return ;
    }

    char ch=digits[i];
    string str=mp[ch];

    for(int idx=0;idx<str.length();idx++){
        temp.push_back(str[idx]);
        solve(digits,mp,temp,i+1);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        if(digits.length()==0){
            return {};
        }

        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        string temp="";

        solve(digits,mp,temp,0);
        return ans;
       
    }
};