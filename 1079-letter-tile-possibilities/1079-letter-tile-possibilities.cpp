class Solution {
public:
void solve(string tiles,string &str,unordered_set<string>&result,vector<bool>&used){
    //base acse
   
    result.insert(str);

    for(int j=0;j<tiles.size();j++){
        if(used[j]){
            continue;
        }
        used[j]=true;
        str.push_back(tiles[j]);
        solve(tiles,str,result,used);

        used[j]=false;
        str.pop_back();
    }
}
    int numTilePossibilities(string tiles) {
        unordered_set<string>result;
        vector<bool>used(tiles.size(),false);
        string str="";
        solve(tiles,str,result,used);
        return result.size()-1;
    }
};

//APPROACH 2
class Solution {
public:
int n;
int count=0;
void solve(vector<int>&freq){
    count++;

    for(int i=0;i<26;i++){
        if(freq[i]==0){
            continue;
        }

        freq[i]--;
        solve(freq);
        freq[i]++;
    }
}
    int numTilePossibilities(string tiles) {
        n=tiles.size();
        // count=0;
        vector<int>freq(26,0);
        for(auto &ch:tiles){
            freq[ch-'A']++;
        }

        solve(freq);
        return count-1;

    }
};
