class Solution {
public:
void solve(vector<int>& candidates, int target,vector<vector<int>>&result,vector<int>&curr,int idx){
    //base case
    if(target<0){
        return ;
    }
    if(target==0){
        result.push_back(curr);
        return ;
    }

    for(int i=idx;i<candidates.size();i++){
        if(i>idx && candidates[i]==candidates[i-1]){
            continue;
        }
        curr.push_back(candidates[i]);
        solve(candidates,target-candidates[i],result,curr,i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>curr;
        solve(candidates,target,result,curr,0);
        return result;
    }
};