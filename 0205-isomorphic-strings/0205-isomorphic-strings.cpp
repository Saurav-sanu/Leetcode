class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>smap;
        unordered_map<char,char>tmap;

        for(int i=0;i<s.length();i++){
            char sk=s[i];
            char tk=t[i];

            if(smap.find(sk)!=smap.end() && smap[sk]!=tk || tmap.find(tk)!=tmap.end() && tmap[tk]!=sk){
                return false;
            }
            smap[sk]=tk;
            tmap[tk]=sk;
        }
        return true;

        
    }
};



//  bool isIsomorphic(string s, string t) {
//         int hash[300]={0};
//         bool isTCharMapped[300]={0};

//         for(int i=0;i<s.size();i++){
//             if(hash[s[i]]==0 && isTCharMapped[t[i]]==0){
//                 hash[s[i]]=t[i];
//                 isTCharMapped[t[i]]=true;
//             }
//         }
//         for(int i=0;i<s.length();i++){
//             if(char(hash[s[i]])!=t[i]){
//                 return false;
//             }
//         }
//         return true;
//     }