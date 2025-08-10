class Solution {
public:
vector<vector<int>>result;
void solve(vector<int>&candidates,int target,int start,vector<int>&temp){
    //base case
    if(target==0){
        result.push_back(temp);
        return;
    }

    if(target<0){
        return;
    }

    //explore
    // if(target-candidates[start]>0){
    //     temp.push_back(candidates[start]);
    //     solve(candidates,target-candidates[start],start,temp);
    //     temp.pop_back();
    //     solve(candidates,target,start+1,temp);
    // }

    for(int i=start;i<candidates.size();i++){
        if(target-candidates[i]>=0){
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i,temp);
            temp.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(candidates,target,0,temp);
        return result;
    }
};