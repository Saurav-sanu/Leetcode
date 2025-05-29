class Solution {
public:
vector<string>result;
void solve(string digits,int index,unordered_map<char,string>&mp,string temp){
    //base case
    if(index>=digits.length()){
        result.push_back(temp);
        return;
    }

    char ch=digits[index];
    string str=mp[ch];

    for(int i=0;i<str.length();i++){
        temp.push_back(str[i]);
        solve(digits,index+1,mp,temp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        string temp="";
        solve(digits,0,mp,temp);

        if(digits.length()==0){
            return {};
        }
        return result;
    }
    
};