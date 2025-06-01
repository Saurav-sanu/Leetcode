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