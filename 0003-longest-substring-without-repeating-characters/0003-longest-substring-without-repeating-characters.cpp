class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int i=0,j=0;
        int n=s.length();

        unordered_map<char,bool>mp;
        while(j<n){
            int count=0;
            if(mp[s[j]]==false){
                mp[s[j]]=true;
                count+=j-i+1;
                maxi=max(count,maxi);
                j++;
            }
            else{
                mp[s[i]]=false;
                i++;
            }

        }
        return maxi;
    }
};
