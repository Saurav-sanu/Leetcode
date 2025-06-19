class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>state(5,0);
        unordered_map<string,int>mp;
        string currstate="00000";
        int result=0;
        mp[currstate] = -1;

        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                state[0]=(state[0]^1);
            }
            else if(s[i]=='e'){
                state[1]=(state[1]^1);
            }
            else if(s[i]=='i'){
                state[2]=(state[2]^1);
            }
            else if(s[i]=='o'){
                state[3]=(state[3]^1);
            }
            else if(s[i]=='u'){
                state[4]=(state[4]^1);
            }
            
            currstate="";

            for(int j=0;j<5;j++){
                currstate+=to_string(state[j]);
            }

            if(mp.find(currstate)!=mp.end()){
                result=max(result,i-mp[currstate]);
            }
            else{
                mp[currstate]=i;
            }
        }
        return result;
    }
};