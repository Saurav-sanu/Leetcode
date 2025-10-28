class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>>vec(123);
        for(auto ch:s){
            int freq=vec[ch].second;
            vec[ch]={ch,freq+1};
        }

        auto lambda=[&](pair<char,int>&p1,pair<char,int>&p2){
            return p1.second>p2.second;
        };

        sort(vec.begin(),vec.end(),lambda);

        string result="";

        for(int i=0;i<=122;i++){
            if(vec[i].second>0){
                char ch=vec[i].first;
                int freq=vec[i].second;
                string temp = string(freq, ch);
                result+=temp;
            }
        }
        return result;

    }
};