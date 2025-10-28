class Solution {
public:
    int beautySum(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>mp;
            for(int j=i;j<s.length();j++){
                int mini=INT_MAX;
                int maxi=INT_MIN;
                mp[s[j]]++;
               for(auto &p:mp){
                mini=min(mini,p.second);
                maxi=max(maxi,p.second);
               }

                count+=maxi-mini;

            }

        }
        return count;
    }
};