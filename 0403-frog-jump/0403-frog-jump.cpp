class Solution {
public:
unordered_map<int,int>mp;
int t[2001][2001];
int solve(vector<int>&stones,int curr_index,int prev_index){
    int n=stones.size();


    if(curr_index==n-1){
        return true;
    }

    if(t[curr_index][prev_index]!=-1){
        return t[curr_index][prev_index];
    }
    bool result=false;

    for(int next_jump=prev_index-1;next_jump<=prev_index+1;next_jump++){
        if(next_jump>0){
            int next_stone=stones[curr_index]+next_jump;
            if(mp.find(next_stone)!=mp.end()){
                result=result|| solve(stones,mp[next_stone],next_jump);
            }
        }
    }

    return t[curr_index][prev_index]=result;


}
    bool canCross(vector<int>& stones) {
        memset(t,-1,sizeof(t));
        int n=stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }

        if(stones[1]!=1){
            return false;
        }

        return solve(stones,0,0);
    }
};