class Solution {
public:
void solve (int temp,int &result,int idx,vector<int>&uniqueCharacterstring){
    result=max(result,__builtin_popcount(temp));
    for(int i=idx;i<uniqueCharacterstring.size();i++){
        if((temp&uniqueCharacterstring[i])==0){
            solve(temp|uniqueCharacterstring[i],result,i+1,uniqueCharacterstring);
        }
    }
}
    int maxLength(vector<string>& arr) {
        vector<int>uniqueCharacterstring;

        for(string &s:arr){
            unordered_set<char>st(s.begin(),s.end());
            if(st.size()!=s.length()){
                continue;
            }

            int val=0;
            for(char &ch:s){
                val=(val|(1<<(ch-'a')));
            }

            uniqueCharacterstring.push_back(val);
        }
        int temp=0;
        int result=0;
        solve(temp,result,0,uniqueCharacterstring);
        return result;
    }
};