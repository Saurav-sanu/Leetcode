class Solution {
public:
    string minWindow(string s, string p) {
        int n=s.length();
        if(p.length()>n){
            return "";
        }
        
        unordered_map<char,int>mp;
        for(char &ch:p){
            mp[ch]++;
        }
        
        int requiredCount=p.length();
        int i=0;int j=0;
        int minWindow_size=INT_MAX;
        int start_i=0;
        
        while(j<n){
            char ch=s[j];
            
            if(mp[ch]>0){
                requiredCount--;
            }
            mp[ch]--;
            
            while(requiredCount==0){
                int currentWindowSize=j-i+1;
                if(minWindow_size>currentWindowSize){
                    minWindow_size=currentWindowSize;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        
        return minWindow_size==INT_MAX?"":s.substr(start_i,minWindow_size);
    }
};