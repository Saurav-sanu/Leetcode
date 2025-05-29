class Solution {
public:
vector<string>result;

    void solve(unordered_map<char,string>&mp,string digits,int idx,string temp){
        //base case
        if(idx==digits.length()){
            result.push_back(temp);
            return;
        }

        char ch=digits[idx];
        string str=mp[ch];

        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(mp,digits,idx+1,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
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

        solve(mp,digits,0,temp);

        return result;
    }
};