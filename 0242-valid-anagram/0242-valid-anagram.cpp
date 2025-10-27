class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }

        for(int i=0;i<t.length();i++){
            mp[t[i]]--;
            if(mp[t[i]]==0){
                mp.erase(t[i]);
            }
        }

        return mp.empty();
    }
};