class Solution {
public:
vector<string>solve(string &s, unordered_map<string,bool>dict,int i){
    if(i==s.size())return {""};
    vector<string>ans;
    string word;
    for(int j=i;j<s.size();j++){
        word.push_back(s[j]);
        if(dict.find(word)==dict.end())continue;

        auto right=solve(s,dict,j+1);
        for(auto eachRightPart:right){
            string endPart;
            if(eachRightPart.size()>0 )endPart=" " + eachRightPart;
            ans.push_back(word+endPart);
        }
    }
    return ans;
}
vector<string>solveDP(string &s, unordered_map<string,bool>dict,int i,unordered_map<int,vector<string>>dp){
    if(i==s.size())return {""};
    vector<string>ans;
    string word;
    if(dp.find(i)!=dp.end()){
        return dp[i];
    }
    for(int j=i;j<s.size();j++){
        word.push_back(s[j]);
        if(dict.find(word)==dict.end())continue;

        auto right=solveDP(s,dict,j+1,dp);
        for(auto eachRightPart:right){
            string endPart;
            if(eachRightPart.size()>0 )endPart=" " + eachRightPart;
            ans.push_back(word+endPart);
        }
    }
    return dp[i]=ans;
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        unordered_map<int,vector<string>>dp;
        for(auto word:wordDict)dict[word]=1;

        return solveDP(s,dict,0,dp);
    }
};