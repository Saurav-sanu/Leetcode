class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(char &ch:s){
            mp[ch]++;
        }

        for(auto &it:mp){
            char charact=it.first;
            int freq=it.second;

            pq.push({freq,charact});

        }
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int freq=top.first;
            char ch=top.second;
            ans += string(freq, ch);
        }
        return ans;
    }
};